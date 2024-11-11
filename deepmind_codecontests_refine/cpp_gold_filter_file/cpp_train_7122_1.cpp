#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 9;
const int mod1 = 999999937;
const int inf = 2e9;
const double eps = 1e-7;
int d[101][101];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    d[a - 1][b - 1] = c;
  }
  int ans = 0;
  int w = n;
  while (w--) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (d[i][j] > 0 && d[j][k] > 0) {
            int q = min(d[i][j], d[j][k]);
            d[i][j] -= q;
            d[j][k] -= q;
            d[i][k] += q;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans += d[i][j];
    }
  }
  cout << ans;
  return 0;
}
