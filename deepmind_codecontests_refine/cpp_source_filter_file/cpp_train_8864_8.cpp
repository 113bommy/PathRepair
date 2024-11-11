#include <bits/stdc++.h>
using namespace std;
const int mxsz = 2e5 + 3;
const int MX2 = 5e5 + 3;
int n, m;
int spt[20][MX2];
int mx = 0;
void computeST() {
  for (int i = 1; i <= mx; i++) spt[0][i] = max(spt[0][i], spt[0][i - 1]);
  for (int i = 1; i <= 19; i++)
    for (int j = 1; j <= mx; j++) spt[i][j] = spt[i - 1][spt[i - 1][j]];
}
int query(int x, int y) {
  int tot = 0;
  for (int i = 19; i >= 0; --i) {
    if (spt[i][x] < y) {
      x = spt[i][x];
      tot += (1 << i);
    }
  }
  if (spt[0][x] >= y) return tot + 1;
  return -1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= n; i++) {
    cin >> x >> y;
    spt[0][x] = max(spt[0][x], y);
    mx = max(mx, y);
  }
  computeST();
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    cout << query(x, y) << '\n';
  }
  return 0;
}
