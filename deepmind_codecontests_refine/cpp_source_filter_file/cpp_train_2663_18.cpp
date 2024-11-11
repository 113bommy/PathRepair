#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[2005];
int cnt[50];
int sum[5005][50];
int mem[2005][2005];
int ans2[2005];
long long dp[2005];
bool check(int x, int y) {
  int i, t, len;
  if (mem[x][y] == -1) {
    len = y - x + 1;
    mem[x][y] = 1;
    for (i = 0; i < 26; i++) {
      t = sum[y][i];
      if (x - 1) t -= sum[x - 1][i];
      if (t > 0 && len > cnt[i]) mem[x][y] = 0;
    }
    if (mem[x][y]) m = max(m, len);
  }
  return mem[x][y];
}
long long f(int x) {
  int i;
  if (x == n) return 1;
  if (dp[x] == -1LL) {
    dp[x] = 0;
    ans2[x] = 5005;
    for (i = x; i < n; i++) {
      if (check(x, i)) {
        dp[x] = (dp[x] + f(i + 1) + 1000000007) % 1000000007;
        ans2[x] = min(ans2[x], ans2[i + 1] + 1);
      }
    }
  }
  return dp[x];
}
int main() {
  int i, j;
  scanf("%d", &n);
  cin >> a;
  for (i = 0; i < 26; i++) scanf("%d", &cnt[i]);
  for (i = 0; i < n; i++) {
    for (j = 0; j < 26; j++) {
      sum[i][j] = (a[i] == (j + 'a'));
      if (i) sum[i][j] += sum[i - 1][j];
    }
  }
  m = 0;
  memset(mem, -1, sizeof(mem));
  memset(dp, -1LL, sizeof(dp));
  f(0);
  printf("%I64d\n%d\n%d", dp[0], m, ans2[0]);
}
