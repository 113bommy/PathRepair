#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 5e2 + 1;
const long long M = 1e6 + 1;
long long dp[2 * N][2 * N], min1[2 * N][2 * N], ar[2 * N], ar1[M];
bool check[2 * N][2 * N];
vector<long long> occur[N];
long long solve(long long l, long long r) {
  if (l > r) {
    return 1;
  }
  if (check[l][r]) {
    return dp[l][r];
  }
  long long y = min1[l][r];
  if (occur[y][0] < l || occur[y][occur[y].size() - 1] > r) {
    check[l][r] = true;
    return 0;
  }
  if (l == r) {
    check[l][r] = true;
    dp[l][r] = 1;
    return dp[l][r];
  }
  check[l][r] = true;
  long long tich = 1, sum = solve(l, occur[y][0] - 1),
            sum1 = solve(occur[y][occur[y].size() - 1] + 1, r), i;
  if (l <= occur[y][0] - 1) {
    sum *= 2;
  }
  if (occur[y][occur[y].size() - 1] + 1 <= r) {
    sum1 *= 2;
  }
  for (i = 0; i + 2 < occur[y].size(); i++) {
    tich *= solve(occur[y][i] + 1, occur[y][i + 1] - 1);
    tich %= mod;
  }
  for (i = l; i < occur[y][0] - 1; i++) {
    sum += solve(l, i) * solve(i + 1, occur[y][0] - 1);
    sum %= mod;
  }
  for (i = occur[y][occur[y].size() - 1] + 1; i < r; i++) {
    sum1 += solve(occur[y][occur[y].size() - 1] + 1, i) * solve(i + 1, r);
    sum1 %= mod;
  }
  dp[l][r] = ((sum * sum1) % mod * tich) % mod;
  return dp[l][r];
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, i, j, k, l = 0;
  cin >> n >> m;
  ar1[0] = -1;
  for (i = 1; i <= m; i++) {
    cin >> ar1[i];
    if (ar1[i] != ar1[i - 1]) {
      l++;
      ar[l] = ar1[i];
      if (l > 2 * n + 1) {
        cout << 0;
        exit(0);
      }
    }
  }
  n = l;
  for (i = 1; i <= n; i++) {
    min1[i][i] = ar[i];
    occur[ar[i]].push_back(i);
    for (j = i + 1; j <= n; j++) {
      min1[i][j] = min(min1[i][j - 1], ar[j]);
    }
  }
  cout << solve(1, n);
}
