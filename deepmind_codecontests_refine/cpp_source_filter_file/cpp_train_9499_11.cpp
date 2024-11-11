#include <bits/stdc++.h>
using namespace std;
const int N = 5010, mod = 998244353;
int n;
long long first[N], rf[N], dp[N][N], ans[N];
long long bp(long long x, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return res;
}
long long inv(long long x) { return bp(x, mod - 2); }
int main() {
  first[0] = rf[0] = 1;
  for (int i = 1; i <= 5000; i++)
    first[i] = first[i - 1] * i, rf[i] = inv(first[i]);
  dp[0][0] = 1;
  for (int i = 1; i <= 5000; i++) {
    for (int j = 0; j < i; j++) {
      int a = j, b = i - 1 - j;
      dp[a + 1][b] = (dp[a + 1][b] + dp[a][b] * (b + 1)) % mod;
      dp[a][b + 1] = (dp[a][b + 1] + dp[a][b] * (a + 1)) % mod;
    }
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; i + j < n; j++)
      ans[i] = (ans[i] + dp[i][j] * first[n] % mod * rf[i + j + 1]) % mod;
  for (int i = 0; i < n; i++) printf("%lld ", ans[i]);
}
