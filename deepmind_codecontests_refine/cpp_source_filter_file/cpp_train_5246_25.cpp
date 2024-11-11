#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int blocks;
  cin >> blocks;
  string s;
  cin >> s;
  long long int L_c = 0, R_c = 0;
  for (long long int i = 0; i < blocks; i++) {
    if (s[i] == 'L')
      L_c++;
    else if (s[i] == 'R')
      R_c++;
  }
  if (L_c == 0) {
    for (long long int i = 0; i < blocks; i++) {
      if (s[i] == 'R') {
        cout << i + 1 << " " << i + 1 + R_c << '\n';
        break;
      }
    }
  } else if (R_c == 0) {
    for (long long int i = blocks - 1; i >= 0; i--) {
      if (s[i] == 'L') {
        cout << i + 1 << " " << i + 1 - L_c << '\n';
        break;
      }
    }
  } else {
    long long int f = 0;
    for (long long int i = 0; i < blocks; i++) {
      if (s[i] == 'R') {
        cout << i + 1 << " ";
        for (long long int j = i + 1; j < blocks; j++) {
          if (s[j] == 'R' && s[j] != s[j + 1]) {
            cout << j + 1 << '\n';
            f = 1;
            break;
          }
        }
        if (f) break;
      }
    }
  }
}
int32_t main() {
  solve();
  return 0;
}
