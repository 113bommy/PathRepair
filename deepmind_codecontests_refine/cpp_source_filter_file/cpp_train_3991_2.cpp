#include <bits/stdc++.h>
using namespace std;
int getint() {
  unsigned int c;
  int x = 0;
  while (((c = getchar()) - '0') >= 10) {
    if (c == '-') return -getint();
    if (!~c) exit(0);
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while (((c = getchar()) - '0') < 10);
  return x;
}
int getc_str(char str[]) {
  unsigned int c, n = 0;
  while ((c = getchar()) <= ' ')
    ;
  if (!~c) exit(0);
  do {
    str[n++] = c;
  } while ((c = getchar()) > ' ');
  str[n] = '\0';
  return n;
}
const long long MOD = 1000000007;
long long dp[123][2789];
int n;
char in[123];
int main() {
  int i, j, k, tcc, tc = getint();
  dp[0][0] = 1;
  for (i = 0; i < 111; i++) {
    for (j = 0; j <= 2600; j++) {
      for (k = 0; k < 26; k++) {
        (dp[i + 1][j + k] += dp[i][j]) % MOD;
      }
    }
  }
  for (tcc = 0; tcc < tc; tcc++) {
    n = getc_str(in);
    int sum = 0;
    for (i = 0; i < n; i++) sum += in[i] - 'a';
    int res = (dp[n][sum] - 1 + MOD) % MOD;
    printf("%d\n", res);
  }
  return 0;
}
