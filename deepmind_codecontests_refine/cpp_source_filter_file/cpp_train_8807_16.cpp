#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast", "-funroll-all-loops")
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, s, t, h[N], x[N], y[N], l = 1, r;
int head[N], nex[M], to[M], w[M], tot;
inline void ade(int a, int b, int c) {
  to[++tot] = b;
  nex[tot] = head[a];
  w[tot] = c;
  head[a] = tot;
}
inline void add(int a, int b, int c) {
  ade(a, b, c);
  ade(b, a, 0);
}
inline int bfs() {
  queue<int> q;
  memset(h, 0, sizeof h);
  h[s] = 1;
  q.push(s);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = nex[i]) {
      if (w[i] && !h[to[i]]) {
        h[to[i]] = h[u] + 1;
        q.push(to[i]);
      }
    }
  }
  return h[t];
}
int dfs(int x, int f) {
  if (x == t) return f;
  int fl = 0;
  for (int i = head[x]; i && f; i = nex[i]) {
    if (w[i] && h[to[i]] == h[x] + 1) {
      int mi = dfs(to[i], min(w[i], f));
      w[i] -= mi, w[i ^ 1] += mi, fl += mi, f -= mi;
    }
  }
  if (!fl) h[x] = -1;
  return fl;
}
inline int dinic() {
  int res = 0;
  while (bfs()) res += dfs(s, inf);
  return res;
}
inline int check(int mid) {
  tot = 1;
  memset(head, 0, sizeof head);
  for (int i = 1; i <= n; i++) add(i + m, t, mid);
  for (int i = 1; i <= m; i++)
    add(s, i, 1), add(i, y[i] + m, 1), add(i, x[i] + m, 1);
  return dinic() == m;
}
signed main() {
  cin >> n >> m;
  r = n;
  t = n + m + 1;
  for (int i = 1; i <= m; i++) cin >> x[i] >> y[i];
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << '\n';
  check(l);
  for (int i = 1; i <= m; i++) {
    if (w[head[i] ^ 1])
      printf("%d %d\n", x[i], y[i]);
    else
      printf("%d %d\n", y[i], x[i]);
  }
  return 0;
}
