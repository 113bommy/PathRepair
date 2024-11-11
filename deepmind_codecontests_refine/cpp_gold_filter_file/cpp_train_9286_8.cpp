#include <bits/stdc++.h>
using namespace std;
struct node {
  int per, to;
} e[1000010 << 1];
int n, q, tot;
int head[1000010], f[1000010], updep[1000010], ch[1000010], ans[1000010],
    dp[1000010];
pair<int, int> mx[1000010], secmx[1000010];
vector<int> vec[1000010];
void addedge(int from, int to) {
  e[++tot].to = to;
  e[tot].per = head[from];
  head[from] = tot;
}
int dfs1(int u, int fa, int dep) {
  f[u] = fa;
  int mxdep = dep;
  for (int i = head[u]; i > 0; i = e[i].per) {
    int v = e[i].to;
    if (v == fa) continue;
    int dd = dfs1(v, u, dep + 1);
    mxdep = max(mxdep, dd);
    pair<int, int> pa = make_pair(dd - dep, v);
    vec[dd - dep].push_back(u);
    if (mx[u].first < dd - dep) {
      secmx[u] = mx[u];
      mx[u] = pa;
    } else if (secmx[u].first < dd - dep) {
      secmx[u] = pa;
    }
  }
  return mxdep;
}
void dfs2(int u, int fa) {
  for (int i = head[u]; i > 0; i = e[i].per) {
    int v = e[i].to;
    if (v == fa) continue;
    updep[v] =
        1 + max(updep[u], v == mx[u].second ? secmx[u].first : mx[u].first);
    vec[updep[v]].push_back(v);
    dfs2(v, u);
  }
}
int main() {
  memset(head, -1, sizeof(head));
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    addedge(u, v);
    addedge(v, u);
  }
  dfs1(1, 0, 0);
  dfs2(1, 0);
  for (int i = 1; i <= n; ++i) vec[0].push_back(i);
  int maxx = 0, t = 0;
  for (int i = n; i >= 0; --i) {
    ans[i * 2 + 1] = maxx;
    for (int v : vec[i]) {
      ans[i * 2 + 1] = max(ans[i * 2 + 1], dp[v] + 1);
    }
    for (int v : vec[i]) {
      maxx = max(maxx, ++dp[v]);
      t = max(t, dp[v] + ch[v] - 2);
      if (v != 1) {
        ch[f[v]] = max(ch[f[v]], dp[v]);
        t = max(t, dp[f[v]] + ch[f[v]] - 2);
      }
    }
    ans[2 * i] = max(maxx, t);
  }
  for (int i = 1; i <= n; ++i) cout << max(ans[i], 1) << " ";
  return 0;
}
