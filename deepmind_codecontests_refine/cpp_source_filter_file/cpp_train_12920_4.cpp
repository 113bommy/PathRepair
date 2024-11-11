#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    int cu = 0, cl = 0, num = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] >= 65 && s[i] <= 90) {
        cu++;
      } else if (s[i] >= 97 && s[i] <= 122) {
        cl++;
      } else if (s[i] >= 48 && s[i] <= 57) {
        num++;
      }
    }
    if (cu > 0 && cl > 0 && num > 0) {
      cout << s << "\n";
    } else {
      if (cu == 0 && cl != 0 && num != 0) {
        if (num == 1 && cl > 1) {
          for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 97 && s[i] <= 122) {
              s[i] = 65;
              break;
            }
          }
        } else if (cl == 1 && num > 1) {
          for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 48 && s[i] <= 57) {
              s[i] = 65;
              break;
            }
          }
        } else {
          for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 48 && s[i] <= 57) {
              s[i] = 65;
              break;
            }
          }
        }
      } else if (cu != 0 && cl == 0 && num != 0) {
        if (num == 1 && cu > 1) {
          for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 65 && s[i] <= 90) {
              s[i] = 97;
              break;
            }
          }
        } else if (cu == 1 && num > 1) {
          for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 48 && s[i] <= 57) {
              s[i] = 97;
              break;
            }
          }
        } else {
          for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 65 && s[i] <= 90) {
              s[i] = 97;
              break;
            }
          }
        }
      } else if (cu != 0 && cl != 0 && num == 0) {
        if (cl == 1 && cu > 1) {
          for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 65 && s[i] <= 122) {
              s[i] = 49;
              break;
            }
          }
        } else if (cu == 1 && cl > 1) {
          for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 97 && s[i] <= 122) {
              s[i] = 49;
              break;
            }
          }
        } else {
          for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 97 && s[i] <= 122) {
              s[i] = 49;
              break;
            }
          }
        }
      } else if (cl == 0 && cu == 0 && num != 0) {
        s[0] = 97;
        s[1] = 65;
      } else if (cl == 0 && num == 0 && cu != 0) {
        s[0] = 97;
        s[1] = 49;
      } else if (cl != 0 && cu == 0 && num == 0) {
        s[0] = 65;
        s[1] = 49;
      }
      cout << s << "\n";
    }
  }
  return 0;
}
