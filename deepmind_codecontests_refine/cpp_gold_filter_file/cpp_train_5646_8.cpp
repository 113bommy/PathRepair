#include <bits/stdc++.h>
using namespace std;
const int MN = 2222;
const long long INF = 1e18;
struct node {
  int l, r;
} a[MN * MN];
int N, M, rk[MN][MN], lcp[MN][MN], r[MN], tot;
char s[MN];
long long dp[MN], K;
inline bool cmp(node a, node b) {
  int p = a.l + lcp[a.l][b.l], q = b.l + lcp[a.l][b.l];
  if (p > a.r || q > b.r) return a.r - a.l < b.r - b.l;
  return s[p] < s[q];
}
inline long long calc(int mid) {
  for (int i = 1; i <= N; ++i) {
    r[i] = i;
    while (r[i] <= N && rk[i][r[i]] < mid) ++r[i];
  }
  memset(dp, 0, sizeof(dp));
  dp[N + 1] = 1;
  for (int i = 1; i <= M; ++i) {
    for (int j = N; j >= 1; --j)
      dp[j] = dp[j] + dp[j + 1] < INF ? dp[j] + dp[j + 1] : INF;
    for (int j = 1; j <= N; ++j) dp[j] = r[j] <= N ? dp[r[j] + 1] : 0;
    dp[N + 1] = 0;
  }
  return dp[1];
}
int main() {
  scanf("%d%d%lld%s", &N, &M, &K, s + 1);
  for (int i = N; i >= 1; --i)
    for (int j = N; j >= 1; --j)
      if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
  for (int i = 1; i <= N; ++i)
    for (int j = i; j <= N; ++j) a[++tot] = (node){i, j};
  sort(a + 1, a + 1 + tot, cmp);
  for (int i = 1; i <= tot; ++i) rk[a[i].l][a[i].r] = i;
  int lft = 1, rht = tot, res;
  while (lft <= rht) {
    int mid = lft + rht >> 1;
    if (calc(mid) >= K) {
      lft = mid + 1;
      res = mid;
    } else
      rht = mid - 1;
  }
  for (int i = a[res].l; i <= a[res].r; ++i) putchar(s[i]);
  return 0;
}
