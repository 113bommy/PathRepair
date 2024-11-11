#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long x, long long y) { return x ? gcd(y % x, x) : y; }
const long long mod = 1e9 + 7;
inline long long QPow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long d = a;
  if (b == 0)
    x = 1, y = 0;
  else {
    d = exgcd(b, a % b, y, x), y -= a / b * x;
  }
  return d;
}
const long long maxn = 1000005;
signed arr[maxn];
signed pos[maxn];
signed dp[maxn];
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  long long n, l, m, A, cf, cm, pl, pr, vl, vr, k, x;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> A, pos[A] = i;
  for (long long i = 1; i <= n; i++) cin >> A, arr[i] = pos[A];
  for (long long i = 1; i <= n / 2; i++) swap(arr[i], arr[n - i + 1]);
  dp[1] = arr[1];
  long long cur = 1;
  for (long long i = 2; i <= n; i++) {
    signed id = lower_bound(dp + 1, dp + 1 + cur, arr[i]) - dp;
    if (id == cur + 1)
      dp[++cur] = arr[i];
    else
      dp[id] = arr[i];
  }
  cout << cur << endl;
  return 0;
}
