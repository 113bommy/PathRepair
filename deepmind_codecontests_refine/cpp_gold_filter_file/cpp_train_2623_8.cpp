#include <bits/stdc++.h>
using namespace std;
long long fpm(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class edge>
struct Graph {
  vector<vector<edge> > adj;
  Graph(int n) {
    adj.clear();
    adj.resize(n + 5);
  }
  void adde(int s, edge e) { adj[s].push_back(e); }
  typename vector<edge>::iterator operator[](int t) { return adj[t].begin(); }
};
const int maxn = 110000;
typedef long long arr64[maxn];
struct edge {
  int t;
  edge *n;
};
arr64 sx, sy, sdx, sdy, x, y, sz;
edge graph[maxn << 1], *eptr = graph, *adj[maxn];
long long tx, ty, ans, n, pa, pb;
void dfs(int v, int f) {
  edge *e;
  sx[v] = x[v], sy[v] = y[v], sz[v] = 1;
  for (e = adj[v]; e; e = e->n)
    if (e->t != f) {
      dfs(e->t, v);
      pb += sx[e->t] * sz[e->t] * y[v];
      sx[v] += sx[e->t];
      sz[v] += sz[e->t];
    }
  pb += (tx - sx[v]) * (n - sz[v]) * y[v];
}
void adde(int s, int t) { *(++eptr) = (edge){t, adj[s]}, adj[s] = eptr; }
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1, s, t; i < n; ++i) cin >> s >> t, adde(s, t), adde(t, s);
  for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i], tx += x[i], ty += y[i];
  dfs(1, 0);
  ({}), ({});
  ans = pb;
  cout << setprecision(15) << 1.0 * ans / tx / ty << endl;
  return 0;
}
