#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
template <typename T>
inline void Swap(T& A, T& B) {
  A ^= B ^= A ^= B;
}
int n, m, k, u[N], v[N];
struct node {
  int x, y;
  node() {}
  node(int _x, int _y) : x(_x), y(_y) {}
  inline friend bool operator<(node A, node B) {
    return (A.x == B.x) ? (A.y < B.y) : (A.x < B.x);
  }
  inline friend bool operator==(node A, node B) {
    return (A.x == B.x && A.y == B.y);
  }
};
class dsu_undo {
 public:
  node stk[N];
  int h, fa[N], d[N];
  inline void init(int R) {
    for (register int i = (1); i <= (R); ++i) fa[i] = i;
  }
  inline int Fnd(int u) {
    while (u ^ fa[u]) u = fa[u];
    return u;
  }
  inline void Mrg(int u, int v) {
    u = Fnd(u), v = Fnd(v);
    if (u == v) return;
    (d[u] > d[v]) && (Swap(u, v), 0);
    stk[++h] = node(u, d[u] == d[v]);
    fa[u] = v, d[v] += d[u] == d[v];
  }
  inline int step() { return h; }
  inline void undo(int lim) {
    while (lim--) {
      d[fa[stk[h].x]] -= stk[h].y;
      fa[stk[h].x] = stk[h].x, h--;
    }
  }
} d;
int tot, id[N], c[N], tmp;
bool odc[N];
inline bool cmp(int A, int B) {
  return c[u[A]] == c[v[A]] ? (c[u[A]] < c[u[B]] || c[u[B]] != c[v[B]]) : 0;
}
inline bool Cmp(int A, int B) {
  return c[u[A]] == c[u[B]] ? c[v[A]] < c[v[B]] : c[u[A]] < c[u[B]];
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (register int i = (1); i <= (n); ++i) scanf("%d", c + i);
  for (register int i = (1); i <= (m); ++i)
    scanf("%d%d", u + i, v + i), id[i] = i;
  for (register int i = (1); i <= (m); ++i)
    if (c[u[i]] > c[v[i]]) swap(u[i], v[i]);
  d.init(n << 1);
  sort(id + 1, id + m + 1, cmp);
  int j = 1;
  tmp = k;
  for (register int i = (1); i <= (k); ++i) {
    while (c[u[id[j]]] == c[v[id[j]]] && c[u[id[j]]] == i) {
      odc[i] |= (d.Fnd(u[id[j]]) == d.Fnd(v[id[j]]));
      d.Mrg(u[id[j]], v[id[j]] + n), d.Mrg(u[id[j]] + n, v[id[j]]), ++j;
    }
    tmp -= odc[i];
  }
  sort(id + j, id + m + 1, Cmp);
  int tt = d.step();
  for (register int i = j; i <= m; i = j) {
    int tu = c[u[id[i]]], tv = c[v[id[i]]];
    d.undo(d.step() - tt);
    if (odc[tu] || odc[tv]) {
      while (j <= m && tu == c[u[id[j]]] && tv == c[v[id[j]]]) ++j;
      continue;
    }
    bool fl = 0;
    while (j <= m && tu == c[u[id[j]]] && tv == c[v[id[j]]]) {
      fl |= d.Fnd(u[id[j]]) == d.Fnd(v[id[j]]);
      d.Mrg(u[id[j]], v[id[j]] + n), d.Mrg(u[id[j]] + n, v[id[j]]);
      ++j;
    }
    tot += fl;
  }
  printf("%lld\n", 1ll * tmp * (tmp - 1) / 2 - tot);
  return 0;
}
