#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
inline int __read() {
  int x(0), t(1);
  char o(getchar());
  while (o < '0' || o > '9') {
    if (o == '-') t = -1;
    o = getchar();
  }
  for (; o >= '0' && o <= '9'; o = getchar()) {
    x = (x << 1) + (x << 3) + (o ^ 48);
  }
  return x * t;
}
int n, m, k;
int ans, sum;
int f[maxn], id[maxn];
struct Node {
  int u, v, w, id;
  bool operator<(const Node &T) const {
    if (w ^ T.w) return u > T.u;
    return w < T.w;
  }
} edge[maxn];
int get_f(int x) {
  if (f[x] == x) return x;
  return f[x] = get_f(f[x]);
}
inline void Init(int delta) {
  for (int i(1); i <= n; ++i) f[i] = i;
  for (int i(1); i <= m; ++i)
    if (edge[i].u == 1) edge[i].w += delta;
  sort(edge + 1, edge + m + 1);
}
inline bool check(int x) {
  Init(x);
  int cnt(0), tot(0);
  for (int i(1); i <= m; ++i) {
    int fa = get_f(edge[i].u), fb = get_f(edge[i].v);
    if (fa == fb || (edge[i].u == 1 && cnt == k)) continue;
    f[fa] = fb;
    id[++tot] = edge[i].id;
    if (edge[i].u == 1) ++cnt;
  }
  for (int i(1); i <= m; ++i)
    if (edge[i].u == 1) edge[i].w -= x;
  return cnt >= k && tot == (n - 1);
}
signed main() {
  n = __read(), m = __read(), k = __read();
  for (int i = 1; i <= m; ++i) {
    edge[i].u = __read(), edge[i].v = __read(), edge[i].w = __read();
    edge[i].id = i;
    if (edge[i].v == 1) swap(edge[i].u, edge[i].v);
  }
  int l(-m), r(m);
  while (l < r) {
    int mid((l + r + 1) >> 1);
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  if (!check(l))
    puts("-1");
  else {
    printf("%d\n", n - 1);
    for (int i(1); i < n; ++i) printf("%d ", id[i]);
    puts("");
  }
}
