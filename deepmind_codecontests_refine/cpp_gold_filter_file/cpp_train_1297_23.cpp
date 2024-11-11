#include <bits/stdc++.h>
using namespace std;
int count(unsigned long long x) {
  int res = 0;
  for (; x; x >>= 1) res += (x & 1);
  return res;
}
unsigned long long ok[1 << 21];
double dp[1 << 21];
char str[55][25];
int main() {
  int n, len, diff, i, j, k, cnt;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%s", str[i]);
  len = strlen(str[0]);
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) {
      for (k = diff = 0; k < len; k++)
        if (str[i][k] == str[j][k]) diff |= 1 << k;
      ok[diff] |= (1LL << i) | (1LL << j);
    }
  for (i = (1 << len) - 1; i >= 0; i--) {
    for (j = cnt = 0; j < len; j++) {
      if (!(i >> j & 1)) {
        ok[i] |= ok[i | (1 << j)];
        dp[i] += dp[i | (1 << j)];
        cnt++;
      }
    }
    (cnt ? (dp[i] /= cnt) : dp[i]) += count(ok[i]) / (double)n;
  }
  printf("%.10lf\n", dp[0]);
}
