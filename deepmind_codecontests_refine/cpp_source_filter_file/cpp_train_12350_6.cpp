#include <bits/stdc++.h>
using namespace std;
inline int readint() {
  int a = 0;
  char c = getchar(), f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -f;
  for (; '0' <= c && c <= '9'; c = getchar())
    a = (a << 3) + (a << 1) + (c ^ 48);
  return a * f;
}
const int MaxN = 500005;
struct UFS {
  int fa[MaxN], rnk[MaxN];
  vector<int> zxy;
  void init(int n) {
    for (int i = 1; i <= n; ++i) fa[i] = i, rnk[i] = 1;
    zxy.clear();
  }
  inline int find(int a) const {
    for (; a ^ fa[a]; a = fa[a])
      ;
    return a;
  }
  inline bool merge(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return false;
    if (rnk[x] > rnk[y]) swap(x, y);
    fa[x] = y, rnk[y] += rnk[x];
    zxy.push_back(x);
    return 1;
  }
  void stepBack() {
    int x = zxy.back();
    rnk[fa[x]] -= rnk[x];
    fa[x] = 0, zxy.pop_back();
  }
};
struct Edge {
  int a, b, v;
  bool operator<(const Edge &t) const { return v < t.v; }
};
Edge ori[MaxN], e[MaxN];
struct Query {
  int id, k;
  bool operator<(const Query &t) const {
    if (ori[k].v != ori[t.k].v) return ori[k].v < ori[t.k].v;
    return id < t.id;
  }
};
Query ask[MaxN];
bool ans[MaxN];
UFS xyx;
int n, m, q, tot;
void solve() {
  int p = 1;
  for (int i = 1, nxt; i <= m; i = nxt) {
    ;
    while (p <= tot && ori[ask[p].k].v == e[i].v) {
      ans[ask[p].id] =
          ans[ask[p].id] && xyx.merge(ori[ask[p].k].a, ori[ask[p].k].b);
      if (p <= tot && ask[p + 1].id != ask[p].id)
        while (!xyx.zxy.empty()) xyx.stepBack();
      ++p;
    };
    for (nxt = i; nxt <= m; ++nxt)
      if (e[nxt].v != e[i].v)
        break;
      else
        xyx.merge(e[nxt].a, e[nxt].b);
    xyx.zxy.clear();
  }
  for (int i = 1; i <= q; ++i) puts(ans[i] ? "YES" : "NO");
}
int main() {
  n = readint(), m = readint();
  for (int i = 1; i <= m; ++i) {
    e[i].a = readint();
    e[i].b = readint();
    e[i].v = readint();
    ori[i] = e[i];
  }
  q = readint(), tot = 0;
  for (int i = 1; i <= q; ++i) {
    int lj = readint();
    while (lj--) {
      ask[++tot].id = i;
      ask[tot].k = readint();
    }
    ans[i] = true;
  }
  sort(ask + 1, ask + tot + 1);
  sort(e + 1, e + m + 1);
  xyx.init(n), solve();
  return 0;
}
