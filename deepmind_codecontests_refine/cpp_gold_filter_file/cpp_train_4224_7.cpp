#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
int n, op, w[N], q[N];
long long c, dp[2][N];
inline int read() {
  int num = 0;
  char g = getchar();
  while (g < 48 || 57 < g) g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  return num;
}
int main() {
  n = read(), c = read();
  for (int i = 1; i <= n; i++) q[i] = read();
  for (int i = 1; i <= n; i++) w[i] = read();
  int op = 0;
  for (int i = 1; i <= n; i++) {
    op ^= 1;
    dp[op][0] = dp[op ^ 1][0] + q[i], dp[op][i] = dp[op ^ 1][i - 1] + w[i];
    for (int x = 1; x < i; x++)
      dp[op][x] = min(dp[op ^ 1][x - 1] + w[i], dp[op ^ 1][x] + q[i] + x * c);
  }
  long long ans = 4e18;
  for (int x = 0; x <= n; x++) ans = min(ans, dp[op][x]);
  cout << ans << endl;
  return 0;
}
