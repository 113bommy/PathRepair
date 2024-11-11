#include <bits/stdc++.h>
using namespace std;
int const maxn = 1003;
int n = 0, m = 0;
long long k = 0;
char s[maxn];
int lcp[maxn][maxn];
struct Substring {
  int l, r;
};
inline bool operator<(Substring const &lhs, Substring const &rhs) {
  int L = lcp[lhs.l][rhs.l];
  if (L >= lhs.r - lhs.l + 1 || L >= rhs.r - rhs.l + 1)
    return lhs.r - lhs.l + 1 < rhs.r - rhs.l + 1;
  return s[lhs.l + L] < s[rhs.l + L];
}
Substring a[maxn * maxn];
int cnt = 0;
long long dp[maxn][maxn], d[maxn][maxn];
bool check(int p) {
  memset(dp, 0, sizeof dp);
  memset(d, 0, sizeof d);
  d[n + 1][0] = 1;
  int stdLen = a[p].r - a[p].l + 1;
  for (int i = n; i >= 1; --i) {
    int t = std::min(stdLen, lcp[a[p].l][i]);
    if (t == stdLen || s[i + t] > s[a[p].l + t])
      for (int j = 1; j <= m; ++j) dp[i][j] = d[i + t + 1][j - 1];
    for (int j = 0; j <= m; ++j) d[i][j] = std::min(d[i + 1][j] + dp[i][j], k);
  }
  return dp[1][m] >= k;
}
int main() {
  scanf("%d %d %lld", &n, &m, &k);
  scanf("%s", s + 1);
  for (int i = n; i >= 1; --i)
    for (int j = n; j >= 1; --j)
      lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j) a[++cnt] = Substring{i, j};
  sort(a + 1, a + cnt + 1);
  int l = 1, r = cnt;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  for (int i = a[l].l; i <= a[l].r; ++i) putchar(s[i]);
  printf("\n");
  return 0;
}
