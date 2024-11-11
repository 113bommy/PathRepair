#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > 57 || c < 48) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c > 47 && c < 58) x = x * 10 + c - 48, c = getchar();
  return x * f;
}
int cnt[200], k, t;
long long c[200][200], dp[20][200];
long long calc(int n) {
  for (int i = 0; i <= 16; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = 0;
  dp[0][n] = 1;
  for (int i = 1; i <= 16; i++)
    for (int j = 0; j <= n; j++)
      if (dp[i - 1][j])
        for (int k = 0; k <= cnt[i] && j >= k; k++)
          dp[i][j - k] += dp[i - 1][j] * c[j][k];
  return dp[16][0];
}
int main() {
  for (int i = 0; i < 200; i++) c[i][0] = 1;
  for (int i = 1; i < 200; i++)
    for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  k = read(), t = read();
  int len;
  for (int i = 1; i <= 16; i++) cnt[i] = t;
  for (len = 1;; len++) {
    long long tmp = calc(len) / 16 * 15;
    if (tmp >= k) break;
    k -= tmp;
  }
  for (int i = 1; i <= len; i++)
    for (int j = 1; j <= 16; j++) {
      if (i == 1 && j == 1) continue;
      cnt[j]--;
      long long tmp = calc(len - i);
      if (tmp >= k) {
        printf("%c", j <= 10 ? j - 1 + '0' : j - 11 + 'a');
        break;
      }
      k -= tmp;
      cnt[j]++;
    }
  return 0;
}
