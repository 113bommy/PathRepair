#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = 5010, INF = 10000;
namespace MF {
int tot, fi[N], a[M], ne[M], c[M];
inline void Pre() {
  memset(fi, 0, sizeof fi);
  tot = 1;
}
inline void Add(int x, int y, int z) {
  a[++tot] = y;
  ne[tot] = fi[x];
  fi[x] = tot;
  c[tot] = z;
}
inline int Adde(int x, int y, int z) {
  Add(x, y, z);
  Add(y, x, 0);
  return tot;
}
int de[N], cur[N];
queue<int> q;
inline bool Bfs(int s, int t) {
  memset(de, 0, sizeof de);
  de[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = fi[u]; i; i = ne[i])
      if (c[i] && !de[a[i]]) de[a[i]] = de[u] + 1, q.push(a[i]);
  }
  return de[t];
}
inline int Dfs(int x, int flow, int t) {
  if (x == t) return flow;
  int sm = 0, tmp;
  for (int i = fi[x]; i; i = ne[i])
    if (de[x] + 1 == de[a[i]] && c[i] &&
        (tmp = Dfs(a[i], min(flow, c[i]), t))) {
      c[i] -= tmp;
      c[i ^ 1] += tmp;
      sm += tmp;
      flow -= tmp;
      if (!flow) return sm;
    }
  return sm;
}
inline int Solve(int s, int t) {
  int maxflow = 0;
  while (Bfs(s, t)) memcpy(cur, fi, sizeof cur), maxflow += Dfs(s, 1e9, t);
  return maxflow;
}
}  // namespace MF
int n, m, s, t, px[M], py[M], pz[M], is_lim[M], du[N], id[M];
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  MF::Pre();
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", px + i, py + i, pz + i);
    if (pz[i])
      MF::Adde(px[i], py[i], 1), MF::Adde(py[i], px[i], INF);
    else
      MF::Adde(px[i], py[i], INF);
  }
  printf("%d\n", MF::Solve(s, t));
  for (int i = 1; i <= m; ++i)
    is_lim[i] = pz[i] && MF::de[px[i]] && !MF::de[py[i]];
  MF::Pre();
  MF::Adde(t, s, INF);
  s = n + 1, t = n + 2;
  for (int i = 1; i <= m; ++i)
    if (pz[i]) {
      ++du[px[i]];
      --du[py[i]];
      id[i] = MF::Adde(px[i], py[i], INF);
    }
  for (int i = 1; i <= n; ++i)
    if (du[i] > 0)
      MF::Adde(s, i, du[i]);
    else if (du[i] < 0)
      MF::Adde(i, t, -du[i]);
  MF::Solve(s, t);
  for (int i = 1; i <= m; ++i) {
    int tmp = MF::c[id[i]] + pz[i];
    printf("%d %d\n", tmp, tmp + !is_lim[i]);
  }
  return 0;
}
