#include <bits/stdc++.h>
using namespace std;
long long dx[] = {1, -1, 0, 0};
long long dy[] = {0, 0, 1, -1};
long long z = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % z;
      b--;
    } else {
      a = (a * a) % z;
      b = b >> 1;
    }
  }
  return res;
}
long long ar[300001], dp[300001] = {0}, sdp[300001] = {0};
long long n, k;
bool func(long long val) {
  long long s = 1;
  dp[0] = 1;
  sdp[1] = 1;
  for (long long i = 1; i <= n; i++) {
    while (ar[i] - val > ar[s]) s++;
    if (s - 1 > i - k)
      dp[i] = 0;
    else
      dp[i] = !!(sdp[i - k + 1] - sdp[s - 1]);
    sdp[i + 1] = sdp[i] + dp[i];
  }
  return dp[n];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) cin >> ar[i];
    sort(ar + 1, ar + n);
    long long l = 0, r = 1e9, ans = -1;
    while (l <= r) {
      long long mid = l + (r - l) / 2;
      if (func(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    cout << ans << "\n";
  }
}
