#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast", "-funroll-all-loops")
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 110, M = 1e6 + 10;
int n, q, s, t, d[N], st[N], vis[N], low[N], up[N], res;
int head[N], nex[M], to[M], flow[M], w[M], tot = 1;
inline void ade(int a, int b, int c, int d) {
  to[++tot] = b;
  nex[tot] = head[a];
  w[tot] = d;
  flow[tot] = c;
  head[a] = tot;
}
inline void add(int a, int b, int c, int d) {
  ade(a, b, c, d);
  ade(b, a, 0, -d);
}
inline int spfa() {
  queue<int> q;
  q.push(s);
  memset(d, inf, sizeof d);
  d[s] = 0;
  memset(st, 0, sizeof st);
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; i; i = nex[i]) {
      if (flow[i] && d[to[i]] > d[u] + w[i]) {
        d[to[i]] = d[u] + w[i];
        if (!vis[to[i]]) q.push(to[i]), vis[to[i]] = 1;
      }
    }
  }
  return d[t] != inf;
}
int dfs(int x, int f) {
  if (x == t) return res += d[t] * f, f;
  int fl = 0;
  st[x] = 1;
  for (int i = head[x]; i && f; i = nex[i]) {
    if (flow[i] && !st[to[i]] && d[to[i]] == d[x] + w[i]) {
      int mi = dfs(to[i], min(flow[i], f));
      flow[i] -= mi, flow[i ^ 1] += mi, fl += mi, f -= mi;
    }
  }
  return fl;
}
signed main() {
  cin >> n >> q;
  t = n * 2 + 1;
  for (int i = 1; i <= n; i++) low[i] = 1, up[i] = n;
  while (q--) {
    int op, l, r, v;
    cin >> op >> l >> r >> v;
    if (op == 1) {
      for (int i = l; i <= r; i++) {
        low[i] = max(low[i], v);
        if (low[i] > up[i]) return puts("-1"), 0;
      }
    } else {
      for (int i = l; i <= r; i++) {
        up[i] = min(up[i], v);
        if (low[i] > up[i]) return puts("-1"), 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    add(i + n, t, 1, 0);
    for (int j = low[i]; j <= up[j]; j++) add(j, i + n, 1, 0);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) add(s, i, 1, (j - 1) * 2 + 1);
  }
  while (spfa()) dfs(s, inf);
  cout << res;
  return 0;
}
