#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int sa[maxn], t1[maxn], t2[maxn], c[maxn], Rank[maxn], height[maxn];
void build_sa(int s[], int n, int m) {
  int i, j, p, *x = t1, *y = t2;
  for (i = 0; i < m; i++) c[i] = 0;
  for (i = 0; i < n; i++) c[x[i] = s[i]]++;
  for (i = 1; i < m; i++) c[i] += c[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
  for (j = 1; j <= n; j <<= 1) {
    p = 0;
    for (i = n - j; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[y[i]]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
    swap(x, y);
    p = 1;
    x[sa[0]] = 0;
    for (i = 1; i < n; i++)
      x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]
                     ? p - 1
                     : p++;
    if (p >= n) break;
    m = p;
  }
}
void getHeight(int s[], int n) {
  int i, j, k = 0;
  for (i = 0; i <= n; i++) Rank[sa[i]] = i;
  for (i = 0; i < n; i++) {
    if (k) k--;
    j = sa[Rank[i] - 1];
    while (s[i + k] == s[j + k]) k++;
    height[Rank[i]] = k;
  }
}
int f[maxn][30];
int n, m, dp[maxn][30];
int r[maxn];
char s[maxn], t[maxn];
void Lcp_init() {
  for (int i = 1; i <= n + m + 1; i++) dp[i][0] = height[i];
  for (int j = 1; (1 << j) <= n + m + 1; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n + m + 1; i++) {
      dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int lcp(int l, int r) {
  l = Rank[l], r = Rank[r];
  if (l > r) swap(l, r);
  ++l;
  int k = 0, len = r - l + 1;
  while ((1 << (k + 1)) <= len) ++k;
  return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}
int main() {
  scanf("%d%s%d%s", &n, s, &m, t);
  for (int i = 0; i < n; i++) r[i] = s[i] - 'a' + 1;
  r[n] = '*';
  for (int i = n + 1; i < n + m + 1; i++) r[i] = t[i - n - 1] - 'a' + 1;
  r[n + m + 1] = 0;
  build_sa(r, n + m + 2, 256);
  getHeight(r, n + m + 1);
  Lcp_init();
  int x, ans = 0;
  scanf("%d", &x);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      f[i + 1][j] = max(f[i + 1][j], f[i][j]);
      int t = lcp(i, f[i][j] + n + 1);
      f[i + t][j + 1] = max(f[i + t][j + 1], f[i][j] + t);
      ans = max(ans, f[i][j]);
    }
  }
  if (ans == m)
    puts("YES");
  else
    puts("NO");
  return 0;
}
