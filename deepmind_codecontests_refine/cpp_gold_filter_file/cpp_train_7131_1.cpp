#include <bits/stdc++.h>
using namespace std;
template <class T>
void Read(T& x) {
  x = 0;
  int flag = 0, sgn = 1;
  char c;
  while (c = getchar()) {
    if (c == '-')
      sgn = -1;
    else if (c >= '0' && c <= '9')
      x *= 10, x += c - '0', flag = 1;
    else if (flag)
      break;
  }
  x *= sgn;
}
const int MAXN = 151, MAXS = MAXN * (MAXN - 1) / 2;
long long dp[2][MAXN][MAXS];
int a[MAXN], n, K, s;
int main() {
  Read(n), Read(K), Read(s);
  for (int i = 1; i <= n; i++) Read(a[i]);
  if (s >= n * (n - 1) / 2) {
    sort(a + 1, a + 1 + n);
    int sum = 0;
    for (int i = 1; i <= K; i++) sum += a[i];
    cout << sum << endl;
    return 0;
  }
  memset(dp, 0x3f3f3f3f, sizeof(dp));
  dp[0][0][0] = 0;
  int now = 0, pre = 1;
  for (int i = 1; i <= n; i++) {
    now ^= 1, pre ^= 1;
    for (int j = 0; j <= min(K, i); j++)
      for (int k = 0; k <= n * (n - 1) / 2; k++) {
        dp[now][j][k] = dp[pre][j][k];
        if (j && k - (i - j) >= 0)
          dp[now][j][k] =
              min(dp[now][j][k], dp[pre][j - 1][k - (i - j)] + a[i]);
      }
  }
  long long ans = 0x3f3f3f3f;
  for (int i = 0; i <= s; i++) ans = min(ans, dp[now][K][i]);
  cout << ans << endl;
}
