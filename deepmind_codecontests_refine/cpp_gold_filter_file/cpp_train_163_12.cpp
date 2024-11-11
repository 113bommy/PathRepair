#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void Out(long long a) {
  if (a < 0) putchar('-'), a = -a;
  if (a >= 10) Out(a / 10);
  putchar(a % 10 + '0');
}
const int N = 1005;
long long a[N], b[N << 1];
long long dp[N][N << 1];
int n, m, p;
long long cacu(long long a, long long b) {
  if (b <= a && a <= p)
    return abs(p - a) + abs(a - b) * 2;
  else if (a <= b && b <= p)
    return abs(p - a);
  else
    return abs(a - b) + abs(p - b);
}
int main() {
  n = read();
  m = read();
  p = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= m; i++) b[i] = read();
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i <= m; i++) dp[0][i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= m; j++) {
      dp[i][j] = min(dp[i][j - 1],
                     max(dp[i - 1][j - 1], abs(a[i] - b[j]) + abs(b[j] - p)));
    }
  Out(dp[n][m]);
  puts("");
  return 0;
}
