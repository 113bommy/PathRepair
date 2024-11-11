#include <bits/stdc++.h>
using namespace std;
int n, k, t, s[1000111];
int f[200111][10];
int main() {
  if (fopen("test.inp", "r")) freopen("test.inp", "r", stdin);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    char x;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      if (x == 'R') s[i] = 0;
      if (x == 'G') s[i] = 1;
      if (x == 'B') s[i] = 2;
    }
    int res = 1e9;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 3; j++) {
        f[i][j] = f[i - 1][(j - 1 + 3) % 3] + (j != s[i]);
        if (i >= k) {
          int Max = f[i][j] - f[i - k][(j - (k % 3) + 3) % 3];
          res = min(Max, res);
        }
      }
    }
    cout << res << '\n';
  }
}
