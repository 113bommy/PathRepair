#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
int bit[M], x[M], y[M], vis[M];
vector<int> tx, ty, zuobiao[M];
void add(int xx) {
  while (xx < M) bit[xx]++, xx += xx & -xx;
}
int sum(int xx) {
  int ans = 0;
  while (xx) ans += bit[xx], xx -= xx & -xx;
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    tx.push_back(x[i]);
    ty.push_back(y[i]);
  }
  sort(tx.begin(), tx.end());
  sort(ty.begin(), ty.end());
  for (int i = 1; i <= n; i++) {
    x[i] = lower_bound(tx.begin(), tx.end(), x[i]) - tx.begin() + 1;
    y[i] = lower_bound(ty.begin(), ty.end(), y[i]) - ty.begin() + 1;
    zuobiao[y[i]].push_back(x[i]);
  }
  long long ans = 0;
  for (int i = M - 1; i > 0; i--) {
    if (zuobiao[i].size() == 0) continue;
    sort(zuobiao[i].begin(), zuobiao[i].end());
    for (int j = 0; j < zuobiao[i].size(); j++) {
      int xx = zuobiao[i][j];
      if (!vis[xx]) add(xx), vis[xx] = 1;
      int l = sum(xx - 1);
      int r;
      if (j + 1 == zuobiao[i].size())
        r = sum(M - 1) - sum(xx);
      else
        r = sum(zuobiao[i][j] - 1) - sum(xx);
      ans += (l + 1) * 1ll * (r + 1);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
