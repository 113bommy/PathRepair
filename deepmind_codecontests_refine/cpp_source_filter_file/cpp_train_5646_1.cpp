#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, F = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') F = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * F;
}
int tcnt, ct, rnk[1000 + 5][1000 + 5], dfn[1000000 + 5];
int n, m, ch[1000000 + 5][26], jp[1000 + 5];
char s[1000 + 5], ans[1000 + 5];
long long k, dp[1000 + 5][1000 + 5], sum[1000 + 5][1000 + 5];
void Insert(int p) {
  int np = 0;
  for (int i = p; i <= n; i++) {
    int dir = s[i] - 'a';
    if (!ch[np][dir]) ch[np][dir] = ++tcnt;
    np = rnk[p][i] = ch[np][dir];
  }
}
void dfs(int x) {
  dfn[x] = ++ct;
  for (int i = 0; i < 26; i++)
    if (ch[x][i]) dfs(ch[x][i]);
}
bool check(int x) {
  for (int i = 1; i <= n; i++) {
    jp[i] = 0;
    for (jp[i] = 0; i + jp[i] <= n && rnk[i][i + jp[i]] <= x; jp[i]++)
      ;
  }
  dp[n + 1][0] = sum[n + 1][0] = 1;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= m; j++) dp[i][j] = 0;
    for (int j = 1; j <= m; j++)
      dp[i][j] = min(dp[i][j] + sum[i + jp[i] + 1][j - 1], k);
    for (int j = 0; j <= m; j++) sum[i][j] = min(sum[i + 1][j] + dp[i][j], k);
  }
  return dp[1][m] < k;
}
void dfs2(int x, int val, int d) {
  if (dfn[x] == val) printf("%s", ans);
  for (int i = 0; i < 26; i++)
    if (ch[x][i]) {
      ans[d] = i + 'a';
      dfs2(ch[x][i], val, d + 1);
      ans[d] = 0;
    }
}
int main() {
  n = read(), m = read(), k = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) Insert(i);
  dfs(0);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) rnk[i][j] = dfn[rnk[i][j]];
  int l = 1, r = tcnt, res;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  dfs2(0, res, 0);
}
