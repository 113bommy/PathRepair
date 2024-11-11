#include <bits/stdc++.h>
using namespace std;
vector<int> son[500005];
int i, j, rt, x, y, n, mn = 1e9, fa[500005][20], a[500005];
long long res, ans;
void dfs(int now, int fat) {
  fa[now][0] = fat;
  for (int i = 1; i < 20; ++i) fa[now][i] = fa[fa[now][i - 1]][i - 1];
  for (int T, i = 0; i < son[now].size(); ++i)
    if ((T = son[now][i]) != fat) dfs(T, now);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> a[i], mn = min(mn, a[i]);
  for (i = 1; i <= n; ++i)
    if (a[i] == mn) rt = i;
  for (i = 1; i < n; ++i)
    cin >> x >> y, son[x].push_back(y), son[y].push_back(x);
  dfs(rt, rt);
  for (i = 1; i <= n; ++i) {
    if (i != rt) {
      res = 1e9;
      for (j = 0; j < 19; ++j)
        if (fa[i][j]) res = min(res, 1ll * a[fa[i][j]] * (j + 1));
      ans += res + a[i];
    }
  }
  cout << ans;
}
