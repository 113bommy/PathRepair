#include <bits/stdc++.h>
using namespace std;
int n, k;
long long m;
long long pot(long long a, long long b) {
  long long ret = 1;
  for (long long i = 1; i <= b; i <<= 1) {
    if (b & i) ret = (ret * a) % 998244353;
    a = (a * a) % 998244353;
  }
  return ret;
}
long long p[5001];
int dp[5001][5001];
int solve(int x, int y) {
  if (x > n) return 0;
  if (y == k) return p[x];
  if (dp[x][y] != -1) return dp[x][y];
  long long ret = (((long long)x) * solve(x, y + 1)) % 998244353;
  ret = (ret + ((long long)(n - x)) * solve(x + 1, y + 1)) % 998244353;
  return dp[x][y] = ret;
}
int main() {
  cin >> n >> m >> k;
  m = pot(m, 998244353 - 2);
  p[0] = 1;
  for (int i = 1; i <= k; i++) p[i] = (p[i - 1] * m) % 998244353;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= k; j++) dp[i][j] = -1;
  printf("%lld\n", solve(0, 0));
  return 0;
}
