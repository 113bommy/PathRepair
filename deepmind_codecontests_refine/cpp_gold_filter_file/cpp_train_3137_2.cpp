#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    bool isPalindrome = true;
    for (int j = 0; j < s.length() / 2; j++) {
      if (s[j] != s[s.length() - j - 1]) isPalindrome = false;
    }
    if (s.length() == 1 || s.length() == 2 && s[0] == s[1])
      cout << "-1" << endl;
    else if (!isPalindrome)
      cout << s << endl;
    else {
      bool allsame = true;
      for (int k = 0; k < s.length() / 2; k++) {
        if (s[k] != s[k + 1]) {
          char temp = s[k + 1];
          s[k + 1] = s[k];
          s[k] = temp;
          allsame = false;
          break;
        }
      }
      if (s.length() == 2)
        cout << "-1" << endl;
      else if (!allsame)
        cout << s << endl;
      else
        cout << "-1" << endl;
    }
  }
}
