#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, k[12];
    int c = 0, f = 0, x = 0;
    cin >> s;
    for (int i = 0; i < 12; i++) {
      if (s[i] == 'X') {
        x++;
        f = 1;
      }
    }
    if (x == 12)
      cout << 6 << " "
           << "1x12 2x6 3x4 4x3 6x2 12x1" << endl;
    else if (f == 1) {
      c++;
      x = 0;
      k[x++] = "1x12";
      for (int i = 0; i < 6; i++) {
        if (s[i] == 'X') {
          if (s[i + 6] == 'X') {
            c++;
            k[x++] = "2x6";
            break;
          }
        }
      }
      for (int i = 0; i < 4; i++) {
        if (s[i] == 'X') {
          if (s[i + 4] == 'X' && s[i + 8] == 'X') {
            c++;
            k[x++] = "3x4";
            break;
          }
        }
      }
      for (int i = 0; i < 3; i++) {
        if (s[i] == 'X') {
          if (s[i + 3] == 'X' && s[i + 9] == 'X' && s[i + 6] == 'X') {
            c++;
            k[x++] = "4x3";
            break;
          }
        }
      }
      for (int i = 0; i < 2; i++) {
        if (s[i] == 'X') {
          if (s[i + 2] == 'X' && s[i + 4] == 'X' && s[i + 6] == 'X' &&
              s[i + 8] == 'X' && s[i + 10] == 'X') {
            c++;
            k[x++] = "6x2";
            break;
          }
        }
      }
      cout << c << " ";
      for (int i = 0; i < c; i++) cout << k[i] << " ";
      cout << endl;
    } else
      cout << 0 << endl;
  }
  return 0;
}
