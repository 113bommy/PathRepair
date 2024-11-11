#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int pre[11][101][101];
int c, q, n, x, y, b, xx, yy, t;
long long ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q >> c;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> b;
    pre[b][x][y]++;
  }
  for (int i = 0; i <= c; i++) {
    for (int j = 0; j <= 100; j++) {
      for (int k = 0; k <= 100; k++) {
        if (k) pre[i][j][k] += pre[i][j][k - 1];
      }
    }
  }
  for (int i = 0; i <= c; i++) {
    for (int j = 0; j <= 100; j++) {
      for (int k = 0; k <= 100; k++) {
        if (k) pre[i][k][j] += pre[i][k - 1][j];
      }
    }
  }
  for (int i = 0; i < q; i++) {
    cin >> t >> x >> y >> xx >> yy;
    for (int i = 0; i <= c; i++) {
      int br = (i + t) % (c + 1);
      long long total = pre[i][xx][yy] - pre[i][x - 1][yy] - pre[i][xx][y - 1] +
                        pre[i][x - 1][y - 1];
      ans += br * total;
    }
    cout << ans << endl;
    ans = 0;
  }
  return 0;
}
