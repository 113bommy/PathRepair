#include <bits/stdc++.h>
using namespace std;
int ans[100005], t, T, n, m, l[100005], r[100005], v[100005], mn, mx, gg[2],
    L[2], R[2];
vector<int> to[100005];
void dfs(int now, int val) {
  v[now] = val;
  L[v[now]] = max(L[v[now]], l[now]);
  R[v[now]] = min(R[v[now]], r[now]);
  for (int T, i = 0; i < to[now].size(); ++i) {
    if (~v[T = to[now][i]]) {
      if (v[T] == val) cout << "IMPOSSIBLE", exit(0);
    } else
      dfs(T, val ^ 1);
  }
}
void tj(int now) {
  ans[now] = gg[v[now]];
  v[now] = -2;
  for (int T, i = 0; i < to[now].size(); ++i)
    if (v[T = to[now][i]] != -2) tj(T);
}
int i, x, y;
int main() {
  cin >> t >> T >> n >> m;
  mn = 1e9;
  for (i = 1; i <= n; ++i)
    cin >> l[i] >> r[i], mn = min(mn, r[i]), mx = max(mx, l[i]);
  if (mn + mx > T) mn = T - mx;
  if (mn + mx < t) mx = t - mn;
  for (i = 1; i <= n; ++i)
    if ((mn > r[i] || mn < l[i]) && (mx > r[i] || mx < l[i]))
      cout << "IMPOSSIBLE", exit(0);
  for (i = 1; i <= m; ++i)
    cin >> x >> y, to[x].push_back(y), to[y].push_back(x);
  memset(v, -1, sizeof(v));
  for (i = 1; i <= n; ++i) {
    if (v[i] == -2) continue;
    L[0] = L[1] = 0;
    R[0] = R[1] = 1e9;
    dfs(i, 0);
    if (L[0] <= mn && mn <= R[0] && L[1] <= mx && mx <= R[1]) {
      gg[0] = 1;
      gg[1] = 2;
      tj(i);
    } else if (L[0] <= mx && mx <= R[0] && L[1] <= mn && mn <= R[1]) {
      gg[0] = 2;
      gg[1] = 1;
      tj(i);
    } else {
      cout << "IMPOSSIBLE", exit(0);
    }
  }
  cout << "POSSIBLE\n" << mn << " " << mx << "\n";
  for (i = 1; i <= n; ++i) cout << ans[i];
}
