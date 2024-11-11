#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int MOD = 1e9 + 7;
int power(int a, int b, int m = MOD) {
  if (b == 0) return 1;
  if (b == 1) return a;
  int x = power(a, b / 2, m) % m;
  x = (x * x) % m;
  if (b % 2) return (x * a) % m;
  return x;
}
long long n, arr[N], dp[1001][20001];
long long solve(long long i, long long j) {
  if (i > n) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  long long ans = 0;
  ans += solve(i + 1, j + arr[i]);
  ans %= MOD;
  ans += solve(i + 1, j - arr[i]);
  ans %= MOD;
  if (j - arr[i] == 10000) ans++;
  if (j + arr[i] == 10000) ans++;
  ans %= MOD;
  return dp[i][j] = ans;
}
int main() {
  scanf("%lld", &n);
  for (long long a = 1; a <= n; a++) scanf("%lld", &arr[a]);
  memset(dp, -1, sizeof(dp));
  long long ans = 0;
  for (long long a = 1; a <= n; a++) ans = (ans + solve(a, 10000)) % MOD;
  printf("%lld\n", ans);
  return 0;
}
