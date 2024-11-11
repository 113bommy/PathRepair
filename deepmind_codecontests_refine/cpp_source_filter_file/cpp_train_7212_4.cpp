#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using ll = long long;
using namespace std;
const long double PI = acos(-1);
const long long M = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline long long mod(long long n, long long m = M) {
  long long ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}
long long exp(long long n, long long k, long long m = M) {
  if (k == 0) return 1;
  if (k == 1) return n;
  long long ax = exp(n, k / 2, m);
  ax = mod(ax * ax, m);
  if (k % 2) ax = mod(ax * n, m);
  return ax;
}
long long gcd(long long a, long long b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
vector<vector<long long> > arr;
vector<long long> sum;
long long n, k;
long long ans = -1e18;
void solve(long long l, long long r, vector<long long> dp) {
  if (l == r) {
    long long acc = 0;
    ans = max(ans, dp[k]);
    for (long long i = 1; i <= k && i <= arr[l].size(); i++) {
      acc += arr[l][i - 1];
      ans = max(ans, acc + dp[k - i]);
    }
  } else {
    long long m = (l + r) >> 1;
    vector<long long> dpl(dp);
    for (long long i = l; i <= m; i++) {
      long long len = arr[i].size();
      for (long long j = k; j >= len; j--) {
        dpl[j] = max(dpl[j], dpl[j - len] + sum[i]);
        ans = max(ans, dpl[j]);
      }
    }
    solve(l, m, dpl);
    vector<long long> dpr(dp);
    for (long long i = m + 1; i <= r; i++) {
      long long len = arr[i].size();
      for (long long j = k; j >= len; j--) {
        dpr[j] = max(dpr[j], dpr[j - len] + sum[i]);
        ans = max(ans, dpr[j]);
      }
    }
    solve(l, m, dpr);
  }
}
void solution() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    long long s;
    cin >> s;
    arr.push_back(vector<long long>(s, 0));
    sum.push_back(0);
    for (long long &x : arr.back()) cin >> x, sum.back() += x;
  }
  vector<long long> dp(k + 1, -1e18);
  dp[0] = 0;
  solve(0, n - 1, dp);
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solution();
}
