#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int U = 0, D = 0, L = 0, R = 0;
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == 'L') ++L;
      if (s[i] == 'D') ++D;
      if (s[i] == 'U') ++U;
      if (s[i] == 'R') ++R;
    }
    int minLR = min(L, R);
    int minUD = min(U, D);
    int minAll = min(minLR, minUD);
    if (minAll == 0) {
      if (minLR >= 1) {
        cout << 2 << endl << "LR";
      } else if (minUD >= 1) {
        cout << 2 << endl << "UD";
      } else {
        cout << 0 << endl;
      }
    } else {
      cout << minLR * 2 + minUD * 2 << endl;
      cout << string(minLR, 'L');
      cout << string(minLR, 'D');
      cout << string(minUD, 'R');
      cout << string(minUD, 'U');
    }
    cout << endl;
  }
  return 0;
}
