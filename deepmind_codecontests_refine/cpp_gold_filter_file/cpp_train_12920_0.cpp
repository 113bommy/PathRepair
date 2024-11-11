#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int l = s.length();
    int ctr1 = 0, ctr2 = 0, ctr3 = 0;
    for (int i = 0; i < l; i++) {
      if (s[i] >= 97 && s[i] <= 122)
        ctr1++;
      else if (s[i] >= 65 && s[i] <= 90)
        ctr2++;
      else if (s[i] >= 48 && s[i] <= 57)
        ctr3++;
    }
    if (ctr1 && ctr2 && ctr3) {
      cout << s << endl;
    } else {
      if (ctr1 == 0 && ctr2 == 0 && ctr3 > 1) {
        s[0] = 'A';
        s[1] = 'a';
      } else if (ctr2 == 0 && ctr3 == 0 && ctr1 > 1) {
        s[0] = 'A';
        s[1] = '7';
      } else if (ctr1 == 0 && ctr3 == 0 && ctr2 > 1) {
        s[0] = 'q';
        s[1] = '7';
      } else if (ctr1 == 0 && ctr2 == 1 && ctr3 > 1) {
        for (int i = 0; i < l - 1; i++) {
          if (s[i] >= 48 && s[i] <= 57) {
            s[i] = 'a';
            break;
          }
        }
      } else if (ctr1 == 0 && ctr3 == 1 && ctr2 > 1) {
        for (int i = 0; i < l - 1; i++) {
          if (s[i] >= 65 && s[i] <= 90) {
            s[i] = 'a';
            break;
          }
        }
      } else if (ctr1 == 0 && ctr3 > 1 && ctr2 > 1) {
        for (int i = 0; i < l - 1; i++) {
          if (s[i] >= 65 && s[i] <= 90) {
            s[i] = 'a';
            break;
          }
        }
      } else if (ctr2 == 0 && ctr1 == 1 && ctr3 > 1) {
        for (int i = 0; i < l - 1; i++) {
          if (s[i] >= 48 && s[i] <= 57) {
            s[i] = 'A';
            break;
          }
        }
      } else if (ctr2 == 0 && ctr3 == 1 && ctr1 > 1) {
        for (int i = 0; i < l - 1; i++) {
          if (s[i] >= 97 && s[i] <= 122) {
            s[i] = 'A';
            break;
          }
        }
      } else if (ctr2 == 0 && ctr3 > 1 && ctr1 > 1) {
        for (int i = 0; i < l - 1; i++) {
          if (s[i] >= 97 && s[i] <= 122) {
            s[i] = 'Q';
            break;
          }
        }
      } else if (ctr3 == 0 && ctr2 == 1 && ctr1 > 1) {
        for (int i = 0; i < l - 1; i++) {
          if (s[i] >= 97 && s[i] <= 122) {
            s[i] = '7';
            break;
          }
        }
      } else if (ctr3 == 0 && ctr1 == 1 && ctr2 > 1) {
        for (int i = 0; i < l - 1; i++) {
          if (s[i] >= 65 && s[i] <= 90) {
            s[i] = '7';
            break;
          }
        }
      } else if (ctr3 == 0 && ctr1 > 1 && ctr2 > 1) {
        for (int i = 0; i < l - 1; i++) {
          if (s[i] >= 65 && s[i] <= 90) {
            s[i] = '7';
            break;
          }
        }
      }
      cout << s << endl;
    }
  }
  return 0;
}
