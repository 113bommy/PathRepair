#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxx = 100 + 10;
int sum[13][maxx][maxx];
int n, q, c;
int sumv(int v, int x1, int y1, int x2, int y2) {
  return sum[v][x2][y2] - sum[v][x1 - 1][y2] - sum[v][x2][y1 - 1] +
         sum[v][x1 - 1][y1 - 1];
}
int main() {
  cin >> n >> q >> c;
  for (int i = 1; i <= n; ++i) {
    int x, y, s;
    cin >> x >> y >> s;
    sum[s][x][y]++;
  }
  for (int l = 0; l <= c; ++l)
    for (int i = 1; i <= 107; ++i)
      for (int j = 1; j <= 107; ++j)
        sum[l][i][j] +=
            sum[l][i - 1][j] + sum[l][i][j - 1] - sum[l][i - 1][j - 1];
  for (int i = 1; i <= q; ++i) {
    int t, x1, y1, x2, y2, ans = 0;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    for (int j = 0; j <= c; ++j) {
      int s = (t + j) % (c + 1);
      ans += sumv(j, x1, y1, x2, y2) * s;
    }
    cout << ans << endl;
  }
}
