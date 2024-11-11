#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXM = 31;
const int MAXN = 61;
const int MAXSUM = 1830;
int m;
int a[MAXM];
int dp[MAXSUM + 1][MAXM][MAXN + 1];
int nxt[MAXSUM + 1][MAXM][MAXN + 1];
int n;
int want[MAXN];
int have[MAXN];
int g[MAXN][MAXN];
void run() {
  scanf("%d", &m);
  for (int i = (0); i < (m); ++i) scanf("%d", &a[i]);
  sort(a, a + m);
  memset(dp, -1, sizeof(dp));
  for (int sum = MAXSUM; sum >= 0; --sum)
    for (int i = (0); i < (m); ++i)
      for (int j = (0); j <= (MAXN); ++j) {
        if (sum < j * (j - 1) / 2) continue;
        if (i == m - 1 && sum == j * (j - 1) / 2) {
          dp[sum][i][j] = j;
          nxt[sum][i][j] = -1;
          break;
        }
        if (sum + a[i] <= MAXSUM && j + 1 <= MAXN &&
            dp[sum + a[i]][i][j + 1] != -1 &&
            (dp[sum][i][j] == -1 ||
             dp[sum + a[i]][i][j + 1] <= dp[sum][i][j])) {
          dp[sum][i][j] = dp[sum + a[i]][i][j + 1];
          nxt[sum][i][j] = i;
        }
        if (i + 1 < m && sum + a[i + 1] <= MAXSUM && j + 1 <= MAXN &&
            dp[sum + a[i + 1]][i + 1][j + 1] != -1 &&
            (dp[sum][i][j] == -1 ||
             dp[sum + a[i + 1]][i + 1][j + 1] <= dp[sum][i][j])) {
          dp[sum][i][j] = dp[sum + a[i + 1]][i + 1][j + 1];
          nxt[sum][i][j] = i + 1;
        }
      }
  if (dp[a[0]][0][1] == -1) {
    printf("=(\n");
    return;
  }
  {
    n = 0;
    want[n++] = a[0];
    int sum = a[0], i = 0, j = 1;
    while (nxt[sum][i][j] != -1) {
      int cur = nxt[sum][i][j];
      want[n++] = a[cur];
      sum += a[cur], i = max(i, cur), ++j;
    }
  }
  sort(want, want + n);
  for (int i = (0); i < (n); ++i) have[i] = i;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j) g[i][j] = i > j ? 1 : 0;
  while (true) {
    int p = 0;
    while (p < n && have[p] == want[p]) ++p;
    if (p >= n) break;
    assert(have[p] < want[p]);
    while (p + 1 < n && have[p + 1] == have[p]) ++p;
    int q = p + 1;
    while (q < n && have[q] <= want[q]) ++q;
    assert(q < n);
    int r = -1;
    for (int i = (0); i < (n); ++i)
      if (i != p && i != q && g[q][i] && g[i][p]) {
        r = i;
        break;
      }
    assert(r != -1);
    g[q][r] = g[r][p] = 0, g[p][r] = g[r][q] = 1, ++have[p], --have[q];
  }
  printf("%d\n", n);
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (n); ++j) printf("%d", g[i][j]);
    puts("");
  }
}
int main() {
  run();
  return 0;
}
