#include <bits/stdc++.h>
int n, lg[300010], a[300010], vl[300010], vr[300010], l[300010][20],
    r[300010][20];
template <typename COMP>
struct ST {
  int st[300010][20];
  COMP cmp;
  int operator()(int const &l, int const &r) {
    int k = lg[r - l + 1];
    return cmp(st[l][k], st[r - (1 << k) + 1][k]);
  }
  void init() {
    for (int i = 1; i <= 3 * n; i++) st[i][0] = i;
    for (int j = 1; j <= lg[3 * n]; j++)
      for (int i = 1; i + (1 << j) - 1 <= 3 * n; i++)
        st[i][j] = cmp(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
  }
};
struct Max {
  int operator()(int const &x, int const &y) { return vr[x] < vr[y] ? y : x; }
};
struct Min {
  int operator()(int const &x, int const &y) { return vl[x] > vl[y] ? y : x; }
};
ST<Max> rmqr;
ST<Min> rmql;
int main() {
  scanf("%d", &n);
  if (n == 1) return puts("0"), 0;
  for (int i = 2; i <= n * 3; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i), a[i + n] = a[i + n + n] = a[i];
  for (int i = 1; i <= 3 * n; i++) {
    vl[i] = l[i][0] = std::max(1, i - a[i]);
    vr[i] = r[i][0] = std::min(3 * n, i + a[i]);
  }
  rmql.init(), rmqr.init();
  for (int i = 1; i <= lg[3 * n]; i++)
    for (int j = 1; j <= 3 * n; j++) {
      int posl = rmql(l[j][i - 1], r[j][i - 1]),
          posr = rmqr(l[j][i - 1], r[j][i - 1]);
      l[j][i] = std::min(l[posl][i - 1], l[posr][i - 1]),
      r[j][i] = std::max(r[posl][i - 1], r[posr][i - 1]);
    }
  for (int j = n + 1; j <= n * 2; j++) {
    int u = j, v = j, ans = 0;
    for (int i = lg[3 * n]; ~i; i--)
      if (std::max(r[v][i], r[u][i]) - std::min(l[u][i], l[v][i]) + 1 < n) {
        int nu = rmql(l[u][i], r[v][i]), nv = rmqr(l[u][i], r[v][i]);
        u = nu, v = nv, ans |= 1 << i;
      }
    printf("%d ", ans + 1);
  }
  return 0;
}
