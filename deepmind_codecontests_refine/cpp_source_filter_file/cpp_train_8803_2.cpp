#include <bits/stdc++.h>
using namespace std;
const int SIZE = 5e3 + 50;
const int mod = 1e9 + 7;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x;
}
int n, len;
int str[SIZE];
int C[SIZE][SIZE], dp[SIZE][30];
char pre[SIZE];
int main() {
  n = read();
  scanf("%s", pre + 1);
  for (int i = 1; i <= n; ++i) {
    int ch = pre[i] - 'a' + 1;
    if (ch == str[len]) continue;
    str[++len] = ch;
  }
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i <= len; ++i) {
    for (int j = i; j; --j) {
      int tmp = str[i], res = 0;
      for (int k = 0; k <= 26; ++k) {
        if (k ^ tmp) {
          res = (res + dp[j - 1][k]) % mod;
        }
      }
      dp[j][tmp] = res;
    }
  }
  int ans = 0;
  for (int i = 1; i <= len; ++i) {
    int tmp = 0;
    for (int k = 1; k <= 26; ++k) {
      tmp = (tmp + dp[i][k]) % mod;
    }
    ans = (ans + (1 * C[n][i] * tmp % mod)) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
