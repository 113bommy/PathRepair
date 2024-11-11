#include <bits/stdc++.h>
inline int clz(int x) { return __builtin_clz(x); }
inline int clz(long long x) { return __builtin_clzll(x); }
inline int lg2(int x) { return !x ? -1 : 31 - clz(x); }
inline int lg2(long long x) { return !x ? -1 : 63 - clz(x); }
using namespace std;
const int M = 200000 + 10, mod = (int)1e9 + 7;
int rk[M], sa[M], h[M], st[20][M];
int n, m;
char s[M];
char t[M];
int dp[M][32];
int x;
void da(char *s, int n, int m) {
  static int t1[M], t2[M], c[M];
  int *x = t1, *y = t2, i, j, k, p = 1;
  memset(c, 0, sizeof(c[0]) * m);
  for (i = 0; i < n; i++) c[x[i] = s[i]]++;
  for (i = 1; i < m; i++) c[i] += c[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
  for (k = 1; p < n; k <<= 1, m = p) {
    for (p = 0, i = n - k; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= k) y[p++] = sa[i] - k;
    memset(c, 0, sizeof(c[0]) * m);
    for (i = 0; i < n; i++) c[x[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
    for (swap(x, y), x[sa[0]] = 0, p = i = 1; i < n; i++)
      x[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]
                     ? p - 1
                     : p++;
  }
  memcpy(rk, x, sizeof(x[0]) * n);
  for (i = 0, k = 0; i < n - 1; h[rk[i++]] = k ? k-- : k)
    for (j = sa[rk[i] - 1]; s[i + k] == s[j + k]; k++)
      ;
  memcpy(st[0], h, sizeof(h[0]) * n);
  for (k = 1; 1 << k <= n; k++)
    for (i = 0; i + (1 << k) - 1 < n; i++)
      st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << k - 1)]);
}
int getlcp(int i, int j) {
  i = rk[i], j = rk[j];
  if (i > j) swap(i, j);
  i++;
  int f = lg2(j - i + 1);
  return min(st[f][i], st[f][j - (1 << f) + 1]);
}
int main() {
  scanf("%d%s", &n, s);
  scanf("%d%s", &m, t);
  scanf("%d", &x);
  s[n] = '#';
  s[n + 1] = 0;
  strcat(s, t);
  da(s, n + m + 2, 128);
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= x; ++j)
      if (dp[i][j] != -1) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        int lcp = getlcp(i, n + dp[i][j] + 1);
        if (lcp == 0) continue;
        dp[i + lcp][j + 1] = max(dp[i + lcp][j + 1], dp[i][j] + lcp);
      }
  }
  for (int j = 0; j <= x; ++j) {
    if (dp[n][j] == m) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
