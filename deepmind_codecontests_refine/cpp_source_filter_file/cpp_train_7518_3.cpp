#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, M = 20;
bool fl[N], rev[N], tg;
int n, k, va, vb, opt, tot, q[N], w[N], h[N], dp[N], gt[N], ft[N], fa[N], st[N],
    col[N], dep[N], cnt[N], e[N][M];
vector<int> v[N], vw[N];
vector<pair<int, int>> f[N];
struct edge {
  int u, t;
} g[N];
inline int read() {
  int num = 0;
  char g = getchar();
  while (g < 48 || 57 < g) g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  return num;
}
inline int lca(int u, int t) {
  if (dep[u] < dep[t]) swap(u, t);
  int z = dep[u] - dep[t];
  for (int i = 19; i >= 0; i--)
    if ((1 << i) & z) u = e[u][i];
  if (u == t) return u;
  for (int i = 19; i >= 0; i--)
    if (e[u][i] != e[t][i]) u = e[u][i], t = e[t][i];
  return fa[u];
}
inline int jmp(int u, int t) {
  for (int i = 19; i >= 0; i--)
    if ((1 << i) & t) u = e[u][i];
  return u;
}
inline void dfs(int u) {
  st[++st[0]] = u, e[u][0] = fa[u];
  for (int z = 1; z <= 19; z++) e[u][z] = e[e[u][z - 1]][z - 1];
  for (int i = 0; i < v[u].size(); i++) {
    int x = v[u][i];
    if (fa[u] == x) continue;
    fa[x] = u, dep[x] = dep[u] + 1, dfs(x);
  }
}
inline void bfs(int u) {
  q[q[0] = 1] = u;
  for (int i = 1; i <= q[0]; i++) {
    u = q[i];
    if (col[u])
      vb = max(vb, dp[ft[u]]);
    else
      va = max(va, dp[ft[u]]);
    for (int z = 0; z < vw[u].size(); z++) {
      int x = vw[u][z];
      if (col[x] == -1)
        col[x] = col[u] ^ 1, q[++q[0]] = x;
      else if (col[u] == col[x])
        tg = 1;
    }
  }
}
inline void bfg(int k) {
  for (int i = 1; i <= q[0]; i++) {
    int u = q[i];
    if (col[u] == k) rev[ft[u]] ^= 1;
  }
}
inline bool check(int d) {
  memset(dp, 0, sizeof(dp));
  for (int s = n; s >= 1; s--) {
    int u = st[s], opt = 1;
    ft[1] = fa[u];
    int suma = 0, sumb = 0;
    for (int i = 0; i < v[u].size(); i++) {
      int x = v[u][i];
      if (fa[u] == x) continue;
      gt[x] = ++opt, ft[opt] = x;
    }
    for (int i = 1; i <= opt; i++) vw[i].resize(0);
    for (int i = 0; i < f[u].size(); i++) {
      vw[gt[f[u][i].first]].push_back(gt[f[u][i].second]);
      vw[gt[f[u][i].second]].push_back(gt[f[u][i].first]);
      fl[gt[f[u][i].first]] = 1, fl[gt[f[u][i].second]] = 1;
    }
    for (int i = 0; i < v[u].size(); i++) {
      int x = v[u][i];
      if (fa[u] == x || !w[x]) continue;
      vw[1].push_back(gt[x]), vw[gt[x]].push_back(1), fl[gt[x]] = 1;
    }
    va = 0, vb = 0, col[1] = 0, bfs(1), suma = vb, sumb = va;
    int vc = 0, vd = 0;
    for (int i = 1; i <= opt; i++)
      if ((col[i] == -1 && h[ft[i]]) || i == 1) {
        va = 0, vb = 0, col[i] = 0, bfs(i);
        if (va < vb) swap(va, vb);
        vc = max(vc, va), vd = max(vd, vb);
      }
    for (int i = 1; i <= opt; i++) col[i] = -1, vw[i].resize(0), fl[i] = 0;
    if (max(vc, suma) + max(vd, sumb) + 1 > d &&
        max(vc, sumb) + max(vd, suma) + 1 > d)
      return false;
    dp[u] = 1919810;
    if (max(vc, suma) + max(vd, sumb) + 1 <= d || u == 1)
      dp[u] = min(dp[u], max(vc, suma));
    if (max(vc, sumb) + max(vd, suma) + 1 <= d || u == 1)
      dp[u] = min(dp[u], max(vd, suma));
    dp[u]++;
  }
  return true;
}
inline void solve(int d) {
  for (int s = n; s >= 1; s--) {
    int u = st[s], opt = 1;
    ft[1] = 0;
    int suma = 0, sumb = 0;
    for (int i = 0; i < v[u].size(); i++) {
      int x = v[u][i];
      if (fa[u] == x) continue;
      gt[x] = ++opt, ft[opt] = x;
    }
    for (int i = 1; i <= opt; i++) vw[i].resize(0);
    for (int i = 0; i < f[u].size(); i++) {
      vw[gt[f[u][i].first]].push_back(gt[f[u][i].second]);
      vw[gt[f[u][i].second]].push_back(gt[f[u][i].first]);
      fl[gt[f[u][i].first]] = 1, fl[gt[f[u][i].second]] = 1;
    }
    for (int i = 0; i < v[u].size(); i++) {
      int x = v[u][i];
      if (fa[u] == x || !w[x]) continue;
      vw[1].push_back(gt[x]), vw[gt[x]].push_back(1), fl[gt[x]] = 1;
    }
    va = 0, vb = 0, col[1] = 0, bfs(1), bfg(1), suma = vb, sumb = va;
    int vc = 0, vd = 0;
    for (int i = 1; i <= opt; i++)
      if ((col[i] == -1 && h[ft[i]])) {
        va = 0, vb = 0, col[i] = 0, bfs(i);
        if (dp[u] - 1 >= va && vb + dp[u] <= d)
          bfg(0);
        else if (dp[u] - 1 >= vb && va + dp[u] <= d)
          bfg(1);
      }
    for (int i = 1; i <= opt; i++) col[i] = -1, vw[i].resize(0), fl[i] = 0;
  }
}
int main() {
  n = read(), k = read();
  int u, t, c;
  for (int i = 1; i <= n; i++) col[i] = -1;
  int pt, qt;
  for (int i = 1; i < n; i++)
    u = read(), t = read(), v[u].push_back(t), v[t].push_back(u);
  dfs(1);
  for (int i = 1; i <= k; i++) {
    u = read(), t = read(), c = lca(u, t);
    int a = 0, b = 0;
    if (i == 1) pt = u, qt = t;
    h[u]++, h[t]++, h[c] -= 2;
    if (c != u) a = jmp(u, dep[u] - dep[c] - 1), w[u]++, w[a]--;
    if (c != t) b = jmp(t, dep[t] - dep[c] - 1), w[t]++, w[b]--;
    if (a > 0 && b > 0) f[c].push_back(make_pair(a, b));
  }
  for (int s = n; s >= 1; s--) {
    u = st[s], opt = 1;
    for (int i = 0; i < v[u].size(); i++) {
      int x = v[u][i];
      if (fa[u] == x) continue;
      w[u] += w[x], h[u] += h[x];
      gt[x] = ++opt;
    }
    for (int i = 1; i <= opt; i++) vw[i].resize(0);
    for (int i = 0; i < f[u].size(); i++) {
      vw[gt[f[u][i].first]].push_back(gt[f[u][i].second]);
      vw[gt[f[u][i].second]].push_back(gt[f[u][i].first]);
      fl[gt[f[u][i].first]] = 1, fl[gt[f[u][i].second]] = 1;
    }
    for (int i = 0; i < v[u].size(); i++) {
      int x = v[u][i];
      if (fa[u] == x || !w[x]) continue;
      vw[1].push_back(gt[x]), vw[gt[x]].push_back(1), fl[gt[x]] = 1;
    }
    for (int i = 1; i <= opt; i++)
      if (col[i] == -1) col[i] = 0, bfs(i);
    for (int i = 1; i <= opt; i++) col[i] = -1, vw[i].resize(0), fl[i] = 0;
  }
  if (tg) {
    puts("-1");
    return 0;
  }
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int d = (l + r) >> 1;
    if (check(d))
      ans = d, r = d - 1;
    else
      l = d + 1;
  }
  check(ans), solve(ans);
  cout << ans << endl;
  for (int s = 1; s <= st[0]; s++) {
    int u = st[s];
    for (int i = 0; i < v[u].size(); i++) {
      int x = v[u][i];
      if (fa[u] == x || !h[x]) continue;
      rev[x] ^= rev[u];
      if (rev[x])
        tot++, g[tot].u = u, g[tot].t = x;
      else
        tot++, g[tot].u = x, g[tot].t = u;
    }
  }
  q[0] = 0;
  memset(dp, 0, sizeof(dp));
  for (int s = 1; s <= n; s++) v[s].resize(0);
  for (int s = 1; s <= tot; s++) cnt[g[s].t]++, v[g[s].u].push_back(g[s].t);
  for (int s = 1; s <= n; s++)
    if (!cnt[s]) q[++q[0]] = s;
  for (int s = 1; s <= q[0]; s++) {
    int u = q[s];
    dp[u]++;
    for (int i = 0; i < v[u].size(); i++) {
      int x = v[u][i];
      dp[x] = max(dp[x], dp[u]);
      cnt[x]--;
      if (!cnt[x]) q[++q[0]] = x;
    }
  }
  for (int s = 1; s <= n; s++) printf("%d ", dp[s]);
}
