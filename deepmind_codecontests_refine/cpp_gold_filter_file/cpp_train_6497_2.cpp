#include <bits/stdc++.h>
using namespace std;
void SieveOfErat() {
  bool prime[1000001];
  memset(prime, true, sizeof(prime));
  for (long long vec = 2; vec * vec <= 1000000; vec++) {
    if (prime[vec] == true) {
      for (long long dd = vec * 2; dd <= 1000000; dd += vec) prime[dd] = false;
    }
  }
}
long long gcd(long long aa, long long id2) {
  if (aa == 0) {
    return id2;
  } else
    return gcd(aa % id2, id2);
}
struct vect {
  struct vect *foll;
  long long calc;
  struct vect *succ;
};
long long n, k, a[100001], dp[100001];
bool chk(long long mid) {
  memset(dp, 0, sizeof(dp));
  for (long long i = 1; i <= n; i++) dp[i] = i - 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = i; j < n; j++)
      if ((j - i + 1) * mid >= abs(a[i] - a[j + 1]))
        dp[j + 1] = min(dp[i] + j - i, dp[j + 1]);
    dp[n] = min(dp[n], dp[i] + n - i);
  }
  return dp[n] <= k;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long low = 0, high = 2 * 1000000010, mid, ans;
  while (high - low > 1) {
    mid = (low + high) >> 1;
    if (chk(mid))
      ans = mid, high = mid;
    else
      low = mid + 1;
  }
  if (chk(low)) ans = min(ans, low);
  if (chk(high)) ans = min(ans, high);
  cout << ans;
  return 0;
}
