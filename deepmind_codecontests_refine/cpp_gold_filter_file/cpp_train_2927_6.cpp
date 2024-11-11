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
int n, s, m, k;
int a[2000 + 5], b[2000 + 5], Nxt[2000 + 5];
int dp[2000 + 5][2000 + 5], sum[2000 + 5];
bool check(int val) {
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (a[i] <= val);
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    for (int j = 1; j <= n; j++)
      if (Nxt[j])
        dp[i][Nxt[j]] =
            max(dp[i][Nxt[j]], dp[i - 1][j - 1] + sum[Nxt[j]] - sum[j - 1]);
    for (int j = 1; j <= n; j++) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
  }
  return dp[m][n] >= k;
}
int main() {
  n = read(), s = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++) b[i] = a[i] = read();
  for (int i = 1; i <= s; i++) {
    int l = read(), r = read();
    for (int j = l; j <= r; j++) Nxt[j] = max(Nxt[j], r);
  }
  sort(b + 1, b + n + 1);
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(b[mid]))
      ans = b[mid], r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d", ans);
}
