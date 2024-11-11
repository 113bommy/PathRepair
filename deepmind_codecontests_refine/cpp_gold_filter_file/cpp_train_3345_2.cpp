#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const long long INF = (long long)1e18;
struct Node {
  long long number, cost;
};
Node oper(const Node &a, const Node &b) {
  return (Node){a.number + b.number, a.cost + b.cost};
}
struct STree {
  vector<Node> st;
  int n;
  STree(int n = 0) : st(4 * n + 5, ((Node){0, 0})), n(n) {}
  void upd(int k, int s, int e, int p, Node v) {
    if (s + 1 == e) {
      st[k] = oper(st[k], v);
      return;
    }
    int m = (s + e) / 2;
    if (p < m)
      upd(2 * k, s, m, p, v);
    else
      upd(2 * k + 1, m, e, p, v);
    st[k] = oper(st[2 * k], st[2 * k + 1]);
  }
  long long godown(int k, int s, int e, long long x) {
    if (s + 1 == e) return min((long long)st[k].number, x / s);
    int m = (s + e) / 2;
    Node le = st[k + k];
    if (le.cost <= x)
      return le.number + godown(k + k + 1, m, e, x - le.cost);
    else
      return godown(k + k, s, m, x);
  }
  void upd(int p, Node v) { upd(1, 0, n, p, v); }
  long long godown(long long x) {
    if (x < 0) return -INF;
    return godown(1, 0, n, x);
  }
};
struct Edge {
  int to, w;
};
int n, X[MAXN], T[MAXN];
long long tot_t, f[MAXN];
vector<Edge> g[MAXN];
STree S(MAXN);
void dfs(int v, long long rem) {
  S.upd(T[v], (Node){X[v], (long long)X[v] * T[v]});
  f[v] = S.godown(rem);
  for (Edge e : g[v]) {
    dfs(e.to, rem - 2 * e.w);
  }
  S.upd(T[v], (Node){-X[v], -(long long)X[v] * T[v]});
}
long long getans(int v, long long rem) {
  long long mx = 0;
  long long smx = 0;
  for (Edge e : g[v]) {
    long long k = getans(e.to, rem - e.w);
    if (k > mx) {
      smx = mx;
      mx = k;
    } else if (k > smx) {
      smx = k;
    }
  }
  return max(f[v], smx);
}
int main() {
  while (scanf("%d %lld", &n, &tot_t) >= 1) {
    for (int i = (0); i < (int)(n); i++) scanf("%d", &X[i]);
    for (int i = (0); i < (int)(n); i++) scanf("%d", &T[i]);
    for (int i = (0); i < (int)(n - 1); i++) {
      int p, l;
      scanf("%d %d", &p, &l);
      --p;
      g[p].push_back((Edge){i + 1, l});
    }
    dfs(0, tot_t);
    long long ans = f[0];
    for (Edge e : g[0]) {
      ans = max(ans, getans(e.to, tot_t - e.w));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
