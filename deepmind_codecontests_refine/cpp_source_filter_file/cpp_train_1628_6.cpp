#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + ch - 48;
    ch = getchar();
  }
  return s * f;
}
constexpr int mod = 1e9 + 7;
constexpr int N = 5e5 + 100;
struct node {
  int l, r, w;
} s[N];
int tot = 0, ans[N];
struct star {
  int id, x, y, w;
} qt[N];
int cnt = 0;
struct DSU {
  static const int maxn = 2e5 + 100;
  int f[maxn], dep[maxn];
  int siz = 0;
  struct node {
    int son, fa, prefa, dep;
  } st[maxn];
  void init() {
    for (int i = 1; i < maxn; ++i) {
      f[i] = i;
      dep[i] = 1;
    }
  }
  int found(int x) { return f[x] == x ? x : found(f[x]); }
  int unit(int x, int y, int sign) {
    x = found(x), y = found(y);
    if (x == y) return 1;
    if (dep[x] > dep[y]) swap(x, y);
    int fax = found(x), fay = found(y);
    if (sign == 1) st[++siz] = {fax, fay, fax, dep[y]};
    if (dep[y] == dep[x]) dep[y]++;
    f[fax] = fay;
    return 0;
  }
  void del() {
    for (int i = siz; i >= 1; --i) {
      int son = st[i].son, fa = st[i].fa;
      f[son] = st[i].prefa;
      dep[fa] = st[i].dep;
    }
    siz = 0;
  }
} dsu;
int main() {
  int n = read<int>(), m = read<int>();
  for (int i = 1; i <= m; ++i) {
    s[i] = {read<int>(), read<int>(), read<int>()};
  }
  int q = read<int>();
  for (int i = 1; i <= q; ++i) {
    int k = read<int>();
    for (int j = 1; j <= k; ++j) {
      int id = read<int>();
      qt[++cnt] = {i, s[id].l, s[id].r, s[id].w};
    }
  }
  sort(s + 1, s + 1 + m, [](node a, node b) { return a.w < b.w; });
  sort(qt + 1, qt + 1 + cnt, [](star a, star b) {
    if (a.w == b.w) return a.id < b.id;
    return a.w < b.w;
  });
  dsu.init();
  int now = 1;
  for (int i = 1; i <= m; ++i) {
    while (qt[now].w == s[i].w && now <= cnt) {
      if (ans[qt[now].id] == 1) {
        ++now;
        continue;
      }
      int flag = dsu.unit(qt[now].x, qt[now].y, 1), id = qt[now].id;
      while (qt[now + 1].id == id && qt[now + 1].w == s[i].w) {
        ++now;
        flag += dsu.unit(qt[now].x, qt[now].y, 1);
      }
      if (flag) {
        ans[id] = 1;
      }
      dsu.del();
      ++now;
    }
    dsu.unit(s[i].l, s[i].r, 0);
  }
  for (int i = 1; i <= q; ++i) {
    ans[i] == 1 ? printf("NO\n") : printf("YES\n");
  }
}
