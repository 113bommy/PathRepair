#include <bits/stdc++.h>
using namespace std;
const long long N = 505;
char en = '\n';
long long inf = 1e17;
long long mod = 998244353;
long long power(long long x, long long n, long long mod) {
  long long res = 1;
  x %= mod;
  while (n) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
long long n, m;
long long arr[N];
long long dp[N][N];
long long recur(long long l, long long r) {
  if (l >= r) return 1;
  long long &ans = dp[l][r];
  if (ans != -1) return ans;
  long long indx = min_element(arr + l, arr + r + 1) - arr;
  long long sum1 = 0;
  for (long long i = l; i <= indx; i++) {
    sum1 += recur(l, i - 1) * recur(i, indx - 1) % mod;
    if (sum1 >= mod) sum1 -= mod;
  }
  long long sum2 = 0;
  for (long long i = indx; i <= r; i++) {
    sum2 += recur(indx + 1, i) * recur(i + 1, r) % mod;
    if (sum2 >= mod) sum2 -= mod;
  }
  ans = sum1 * sum2;
  ans %= mod;
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  memset(dp, -1, sizeof(dp));
  cout << recur(1, n) << en;
  return 0;
}
