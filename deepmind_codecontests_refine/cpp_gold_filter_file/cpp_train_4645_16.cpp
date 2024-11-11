#include <bits/stdc++.h>
using namespace std;
inline int re_ad() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return x * f;
}
int n;
int d[300010], fa[21][300010], base[25];
int lg[300010];
vector<int> s1, s2;
inline void add(int x, int f) {
  fa[0][x] = f;
  d[x] = d[f] + 1;
  for (int i = 1; base[i] <= d[x]; ++i) fa[i][x] = fa[i - 1][fa[i - 1][x]];
}
inline int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  register int i, t = d[x] - d[y];
  for (i = 0; t; ++i) {
    if (t & 1) x = fa[i][x];
    t >>= 1;
  }
  if (x == y) return x;
  for (i = lg[d[x]]; i >= 0; --i) {
    if (fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
  }
  return fa[0][x];
}
inline int dis(int x, int y) { return d[x] + d[y] - (d[lca(x, y)] << 1); }
inline int ma(int x, int y) { return x > y ? x : y; }
int main() {
  register int i, x, j, d1, d2, d = 0;
  n = re_ad() + 1;
  lg[0] = -1;
  base[0] = 1;
  for (i = 1; i <= 20; ++i) base[i] = base[i - 1] << 1;
  for (i = 1; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
  s1.push_back(1);
  for (i = 2; i <= n; ++i) {
    x = re_ad();
    add(i, x);
    if (!s1.empty())
      d1 = dis(s1[0], i);
    else
      d1 = 0;
    if (!s2.empty())
      d2 = dis(s2[0], i);
    else
      d2 = 0;
    if (ma(d1, d2) < d)
      ;
    else if (ma(d1, d2) == d) {
      if (d1 == d)
        s2.push_back(i);
      else
        s1.push_back(i);
    } else {
      d = ma(d1, d2);
      if (d1 == d) {
        for (j = 0; j < s2.size(); ++j) {
          x = s2[j];
          if (dis(x, i) == d) s1.push_back(x);
        }
        s2.clear();
        s2.push_back(i);
      } else {
        for (j = 0; j < s1.size(); ++j) {
          x = s1[j];
          if (dis(x, i) == d) s2.push_back(x);
        }
        s1.clear();
        s1.push_back(i);
      }
    }
    x = s1.size() + s2.size();
    printf("%d\n", x);
  }
}
