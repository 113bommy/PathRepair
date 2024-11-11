#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const long long mod = 1e9 + 7;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
long long dp[1005];
int p[1005];
int main(void) {
  int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (i = 1; i <= n; i++) {
    dp[i] = 2;
    for (j = p[i]; j <= i - 1; j++) dp[i] = dp[i] + dp[j] % mod;
  }
  long long ans = 0;
  for (i = 1; i <= n; i++) ans = ans + dp[i] % mod;
  cout << ans << endl;
  return 0;
}
