#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int low = 0;
    int high = 0;
    int digit = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= 'a' and s[i] <= 'z') {
        low++;
      } else if (s[i] >= 'A' and s[i] <= 'Z') {
        high++;
      } else if (s[i] >= '0' and s[i] <= '9') {
        digit++;
      }
    }
    if (high > 0 and low > 0 and digit > 0) {
      cout << s << endl;
      continue;
    }
    if (low == 0 and high > 0 and digit > 0) {
      if (high > 1) {
        for (int i = 0; i < s.size(); i++) {
          if (s[i] >= 'A' and s[i] <= 'Z') {
            s[i] = 'a';
            break;
          }
        }
      } else if (digit > 1) {
        for (int i = 0; i < s.size(); i++) {
          if (s[i] >= '0' and s[i] <= '9') {
            s[i] = 'a';
            break;
          }
        }
      }
    } else if (high == 0 and low > 0 and digit > 0) {
      if (low > 1) {
        for (int i = 0; i < s.size(); i++) {
          if (s[i] >= 'a' and s[i] <= 'z') {
            s[i] = 'A';
            break;
          }
        }
      } else if (digit > 1) {
        for (int i = 0; i < s.size(); i++) {
          if (s[i] >= '0' and s[i] <= '9') {
            s[i] = 'A';
            break;
          }
        }
      }
    } else if (digit == 0 and low > 0 and high > 0) {
      if (low > 1) {
        for (int i = 0; i < s.size(); i++) {
          if (s[i] >= 'a' and s[i] <= 'z') {
            s[i] = '1';
            break;
          }
        }
      } else if (high > 1) {
        for (int i = 0; i < s.size(); i++) {
          if (s[i] >= 'A' and s[i] <= 'Z') {
            s[i] = '1';
            break;
          }
        }
      }
    } else {
      if (digit > 0) {
        s[0] = 'A';
        s[1] = 'a';
      } else if (high > 0) {
        s[0] = '5';
        s[1] = 'a';
      } else if (low > 0) {
        s[0] = '5';
        s[1] = 'A';
      }
    }
    cout << s << endl;
  }
  return 0;
}
