#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
vector<char> password; 
    for (int i = 0; i < 2; i++) {
        char c; 
        cin >> c; 
        password.push_back(c);
    }
    int n; 
    cin >> n; 
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        std::cin >> words[i];
    }

    bool char1Found = false, char2Found = false;
    bool case1 = false;
    bool case2 = false;
    string stringPassword = "";
     stringPassword += password[1];  
     stringPassword += password[0];
    for (int i = 0; i < n; i++) {
        if (words[i] == stringPassword) {
            case1 = true;
            cout << "YES" << endl;
            return 0;
            break;
        } 
        else if (words[i][0] == password[0] && words[i][1] == password[1]) {
            // Complete password found in one word
            cout << "YES" << endl;
            case2 = true;
            return 0;
        } else if (words[i][0] == password[1]) {
            char2Found = true;
        } else if (words[i][1] == password[0]) {
            char1Found = true;
        }
    }

        // Check if both characters have been found (even in separate words)
        if ((char1Found && char2Found) && !case2) {
            cout << "YES" << endl;
            return 0;
        }

    // Password not found
    if (((!char1Found || !char2Found) && !case1)) {
        cout << "NO" << endl;
    }
    return 0;
}
