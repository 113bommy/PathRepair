#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int T, n, m1, m2, u, v;
string s;
void solve() {
  cin >> n >> s;
  bool idk = 0;
  int j = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] != '?') {
      j = i;
      break;
    }
  }
  if (j == -1) {
    for (int i = 0; i < n; i++) {
      if (i % 2) {
        cout << "B";
      } else {
        cout << "R";
      }
    }
    cout << "\n";
    return;
  }
  for (int i = j; i < n; i++) {
    if (s[i] == '?') {
      if (s[i - 1] == 'B') {
        s[i] = 'R';
      } else {
        s[i] = 'B';
      }
    }
  }
  for (int i = j; i > -1; i--) {
    if (s[i] == '?') {
      if (s[i + 1] == 'B') {
        s[i] = 'R';
      } else {
        s[i] = 'B';
      }
    }
  }
  cout << s << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
