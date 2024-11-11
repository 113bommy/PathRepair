#include <bits/stdc++.h>
using namespace std;
int n, s[1001000], f[1001000], g[1001000][19], e[19], sa[1001000], rk[1001000],
    t[1001000 * 10];
struct node {
  int x[1001000], y[1001000], a[1001000], height[1001000];
  void ssort() {
    int mx = 0;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) a[x[y[i]]]++, mx = max(mx, x[y[i]]);
    for (int i = 1; i <= mx; i++) a[i] += a[i - 1];
    for (int i = n; i >= 1; i--) sa[a[x[y[i]]]] = y[i], a[x[y[i]]]--;
  }
  void make() {
    for (int i = 1; i <= n; i++) y[i] = i, x[i] = s[i];
    ssort();
    for (int j = 1; j <= n; j *= 2) {
      int k = 0;
      for (int i = n - j + 1; i <= n; i++) y[++k] = i;
      for (int i = 1; i <= n; i++)
        if (sa[i] > j) y[++k] = sa[i] - j;
      ssort();
      for (int i = 1; i <= n; i++) y[i] = x[i];
      x[sa[1]] = k = 1;
      for (int i = 2; i <= n; i++) {
        if (y[sa[i]] != y[sa[i - 1]] || y[sa[i] + j] != y[sa[i - 1] + j]) k++;
        x[sa[i]] = k;
      }
      if (k == n) break;
    }
    for (int i = 1; i <= n; i++) rk[sa[i]] = i;
    int k = 0;
    for (int i = 1; i <= n; i++) {
      int j = sa[rk[i] - 1];
      while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
      height[rk[i]] = k;
      if (k > 0) k--;
    }
    for (int i = 1; i <= n; i++) g[i][0] = height[i];
    for (int j = 1; j <= 18; j++)
      for (int i = 1; i <= n; i++)
        g[i][j] = min(g[i][j - 1], g[i + e[j - 1]][j - 1]);
  }
} SA;
void ins(int v, int i, int j, int x, int y) {
  t[v] = max(t[v], y);
  if (i == j) return;
  int m = (i + j) >> 1;
  if (x <= m)
    ins(v + v, i, m, x, y);
  else
    ins(v + v + 1, m + 1, j, x, y);
}
int find(int v, int i, int j, int x, int y) {
  if (i == x && j == y) return t[v];
  int m = (i + j) >> 1;
  if (y <= m) return find(v + v, i, m, x, y);
  if (x > m) return find(v + v + 1, m + 1, j, x, y);
  return max(find(v + v, i, m, x, m), find(v + v + 1, m + 1, j, m + 1, y));
}
int get(int x, int y) {
  x++;
  if (x > y) return 0;
  int j = log2(y - x + 1);
  return min(g[x][j], g[y - e[j] + 1][j]);
}
int ef1(int x, int k) {
  int l = 1, r = x;
  while (l + 1 < r) {
    int m = (l + r) >> 1;
    if (get(m, x) >= k)
      r = m;
    else
      l = m;
  }
  if (get(l, x) >= k) r = l;
  return r;
}
int ef2(int x, int k) {
  int l = x, r = n;
  while (l + 1 < r) {
    int m = (l + r) >> 1;
    if (get(x, m) >= k)
      l = m;
    else
      r = m;
  }
  if (get(x, r) >= k) l = r;
  return l;
}
int calc(int x, int k) {
  int l = ef1(rk[x], k), r = ef2(rk[x], k);
  return find(1, 1, n, l, r);
}
int main() {
  e[0] = 1;
  for (int i = 1; i <= n; i++) e[i] = e[i - 1] * 2;
  scanf("%d\n", &n);
  for (int i = 1; i <= n; i++) s[i] = getchar() - 96;
  SA.make();
  int ans = 1;
  for (int i = n; i >= 1; i--) {
    int k = f[i + 1] + 1;
    for (; k; k--) {
      ins(1, 1, n, rk[i + k], f[i + k]);
      if (max(calc(i, k - 1), calc(i + 1, k - 1)) >= k - 1) break;
    }
    f[i] = k;
    ans = max(ans, f[i]);
  }
  printf("%d\n", ans);
}
