#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7, M = 5e5 + 7;
pair<int, int> sgm[N];
int rmq[17 + 1][M];
int n;
void precalc() {
  int x(-1), j(0);
  for (int i = 0; i < M; ++i) {
    while (j < n && sgm[j].first <= i) x = max(x, sgm[j].second), ++j;
    rmq[0][i] = x;
  }
  for (int j = 1; j < 17 + 1; ++j)
    for (int i = 0; i < M; ++i) rmq[j][i] = rmq[j - 1][rmq[j - 1][i]];
}
int main() {
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> sgm[i].first >> sgm[i].second;
  sort(sgm, sgm + n);
  precalc();
  for (int j = 0; j < m; ++j) {
    int x, y;
    cin >> x >> y;
    int ans(0);
    for (int i = 17; i >= 0; --i)
      if (rmq[i][x] < y) x = rmq[i][x], ans += (1 << i);
    if (rmq[0][x] >= y)
      cout << ans + 1 << '\n';
    else
      cout << "-1\n";
  }
  return 0;
}
