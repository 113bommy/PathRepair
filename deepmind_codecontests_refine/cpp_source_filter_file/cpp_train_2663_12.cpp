#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long dp[1111], f[1111];
int lmax;
char s[1111];
int a[30];
int check(int i, int j) {
  int len = j - i + 1;
  for (int k = i; k <= j; k++) {
    if (a[s[k] - 'a'] < len) return 0;
  }
  return 1;
}
int main() {
  int n, i, j;
  cin >> n;
  scanf("%s", s + 1);
  for (i = 0; i < 26; i++) cin >> a[i];
  dp[0] = 1;
  f[0] = 0;
  lmax = -1;
  for (i = 1; i <= n; i++) {
    f[i] = 0x3f3f3f3f;
    for (j = 1; j <= i; j++) {
      if (check(i - j + 1, i)) {
        f[i] = min(f[i], f[i - j] + 1);
        dp[i] = (dp[i] + dp[i - j]) % mod;
        lmax = max(lmax, j);
      }
    }
  }
  printf("%I64d\n%I64d\n%d\n", dp[n], lmax, f[n]);
  return 0;
}
