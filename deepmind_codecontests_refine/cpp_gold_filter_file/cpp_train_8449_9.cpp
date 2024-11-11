#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool tomax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline bool tomin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
const int M = 105, N = M * 5;
template <int N, int M, class T>
struct Link {
  int HEAD[N], NXT[M], tot;
  T W[M];
  void add(int x, T w) {
    NXT[++tot] = HEAD[x];
    W[HEAD[x] = tot] = w;
  }
  T &operator[](int x) { return W[x]; }
};
struct Edge {
  int to, flow;
};
Link<N, M * M * 2, Edge> G;
inline int rev(int k) { return ((k - 1) ^ 1) + 1; }
void addEdge(int u, int v, int w) {
  G.add(u, (Edge){v, w});
  G.add(v, (Edge){u, 0});
}
int mark[N], que[N];
bool bfs(int s, int t) {
  memset(mark, 0, sizeof mark);
  int hed = 1, tai = 0;
  mark[s] = 1;
  que[++tai] = s;
  while (hed <= tai) {
    int o = que[hed++];
    for (int k(G.HEAD[o]); k; k = G.NXT[k]) {
      Edge e = G[k];
      if (e.flow == 0 || mark[e.to]) continue;
      mark[e.to] = mark[o] + 1;
      que[++tai] = e.to;
    }
  }
  return mark[t];
}
int dfs(int s, int mn, int t) {
  if (s == t) return mn;
  int ans = 0;
  for (int k(G.HEAD[s]); k; k = G.NXT[k]) {
    Edge e = G[k];
    if (e.flow == 0 || mark[e.to] != mark[s] + 1) continue;
    int tmp = dfs(e.to, min(mn, e.flow), t);
    G[k].flow -= tmp;
    mn -= tmp;
    G[rev(k)].flow += tmp;
    ans += tmp;
    if (mn == 0) break;
  }
  return ans;
}
int dinic(int s, int t) {
  int ans = 0;
  while (bfs(s, t)) ans += dfs(s, 1e9, t);
  return ans;
}
int v1[M + M], v2[M + M], x[M + M], y[M + M];
void init(int *a, int *vec, int &n) {
  for (int i(1), i_END_(n); i <= i_END_; i++) vec[i] = a[i];
  sort(vec + 1, vec + 1 + n);
  int t = n;
  n = unique(vec + 1, vec + 1 + n) - vec - 1;
  for (int i(1), i_END_(t); i <= i_END_; i++)
    a[i] = lower_bound(vec + 1, vec + 1 + n, a[i]) - vec;
}
int main() {
  int n1, n2, m;
  scanf("%*d%d", &m);
  for (int i(1), i_END_(m); i <= i_END_; i++) {
    scanf("%d%d%d%d", x + i, y + i, x + i + m, y + i + m);
    x[i + m]++;
    y[i + m]++;
  }
  init(x, v1, n1 = m + m);
  init(y, v2, n2 = m + m);
  int s = n1 + n2 + 1, t = s + 1, tot = t;
  for (int i(1), i_END_(n1 - 1); i <= i_END_; i++)
    addEdge(s, i, v1[i + 1] - v1[i]);
  for (int i(1), i_END_(n2 - 1); i <= i_END_; i++)
    addEdge(i + n1, t, v2[i + 1] - v2[i]);
  for (int i(1), i_END_(m); i <= i_END_; i++) {
    int o = ++tot;
    for (int j(x[i]), j_END_(x[i + m] - 1); j <= j_END_; j++)
      addEdge(j, o, 1e9);
    for (int j(y[i]), j_END_(y[i + m] - 1); j <= j_END_; j++)
      addEdge(o, n1 + j, 1e9);
  }
  printf("%d\n", dinic(s, t));
  return 0;
}
