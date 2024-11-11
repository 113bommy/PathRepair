#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int n, m, w;
struct vec {
  int x, y;
};
vec operator+(vec a, vec b) { return (vec){a.x + b.x, a.y + b.y}; }
vec operator-(vec a, vec b) { return (vec){a.x - b.x, a.y - b.y}; }
long long dot(vec a, vec b) { return 1ll * a.x * b.x + 1ll * a.y * b.y; }
long long crs(vec a, vec b) { return 1ll * a.x * b.y - 1ll * b.x * a.y; }
long long pw2(long long a) { return a * a; }
long long pw2(vec a) { return dot(a, a); }
vec A[N], B[N], W[N];
int R[N];
int wide;
const int M = 1e6;
const int INF = 1e9;
int nxt[M], hea[M], to[M], cap[M], vis[M], dis[M], hew[M], S, T, C;
void add_edge(int a, int b, int c) {
  static int tot = 0;
  nxt[++tot] = hea[a];
  hea[a] = tot;
  to[tot] = b;
  cap[tot] = c;
  nxt[++tot] = hea[b];
  hea[b] = tot;
  to[tot] = a;
  cap[tot] = 0;
}
void push(int p, int v) {
  cap[p] -= v;
  cap[p & 1 ? p + 1 : p - 1] += v;
}
int dfs(int t, int x) {
  if (t == T) return x;
  int w = 0;
  for (int &p = hew[t]; p; p = nxt[p])
    if (cap[p] && dis[to[p]] == dis[t] + 1) {
      int v = dfs(to[p], min(x, cap[p]));
      push(p, v);
      w += v;
      x -= v;
      if (!x) return w;
    }
  return w;
}
void bfs() {
  queue<int> B;
  B.push(S);
  for (int i = 1; i <= C; ++i) vis[i] = 0, dis[i] = -1;
  dis[S] = 0;
  vis[S] = 1;
  while (!B.empty()) {
    int t = B.front();
    B.pop();
    for (int p = hea[t]; p; p = nxt[p])
      if (cap[p] && !vis[to[p]]) {
        vis[to[p]] = 1;
        dis[to[p]] = dis[t] + 1;
        B.push(to[p]);
      }
  }
}
int Dinic() {
  int w = 0;
  while (1) {
    bfs();
    if (!vis[T]) return w;
    for (int i = 1; i <= C; ++i) hew[i] = hea[i];
    w += dfs(S, INF);
  }
}
int main() {
  scanf("%d%d", &n, &w);
  for (int i = 0; i < n; ++i) scanf("%d%d", &A[i].x, &A[i].y);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", &B[i].x, &B[i].y, &R[i]);
  {
    int p = 0, q = 0;
    for (int i = 1; i < n; ++i) {
      if (A[i].x < A[p].x) p = i;
      if (A[i].x > A[q].x) q = i;
    }
    A[n] = A[0];
    wide = A[q].x - A[p].x;
    for (int i = 0; i < n * 2; ++i) {
      W[i] = A[p] - A[q];
      if (crs(A[p + 1] - A[p], A[q] - A[q + 1]) >= 0)
        p = (p + 1) % n;
      else
        q = (q + 1) % n;
    }
    W[n * 2] = W[0];
  }
  S = m * 2 + 1, C = T = S + 1;
  for (int i = 1; i <= m; ++i) {
    add_edge(i * 2 - 1, i * 2, 1);
    if (wide + R[i] > B[i].x) add_edge(S, i * 2 - 1, INF);
    if (wide + R[i] > w - B[i].x) add_edge(i * 2, T, INF);
  }
  for (int i = 1; i <= m; ++i)
    for (int j = i + 1; j <= m; ++j) {
      vec w = B[j] - B[i];
      int fl = 1;
      for (int k = 0; k < n * 2; ++k)
        if (crs(W[k + 1] - W[k], w - W[k]) < 0) fl = 0;
      for (int k = 0; k < n * 2; ++k)
        if (dot(W[k + 1] - W[k], w - W[k]) >= 0 &&
            dot(W[k] - W[k + 1], w - W[k + 1]) >= 0)
          if (pw2(crs(W[k + 1] - W[k], w - W[k])) <
              pw2(R[i] + R[j]) * pw2(W[k + 1] - W[k]))
            fl = 1;
      for (int k = 0; k < n * 2; ++k)
        if (pw2(w - W[k]) < pw2(R[i] + R[j])) fl = 1;
      if (fl) {
        add_edge(i * 2, j * 2 - 1, INF);
        add_edge(j * 2, i * 2 - 1, INF);
      }
    }
  printf("%d\n", Dinic());
}
