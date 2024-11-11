#include <bits/stdc++.h>
using namespace std;
const long long logN = 20;
const long long M = 1000000007;
const long long INF = 1e12;
const long long N = 505;
const long long K = 250505;
long long dp[K];
void solve() {
  long long n, k;
  cin >> n >> k;
  long long A[n], B[n];
  for (long long i = 0; i < n; i++) cin >> A[i] >> B[i];
  long long r = 0, g = 0;
  for (long long i = 0; i < n; i++) r += A[i], g += B[i];
  dp[0] = 1;
  for (long long i = 0; i < n; i++) {
    long long r0 = A[i];
    long long g0 = B[i];
    if ((r0 + g0) < k) continue;
    long long downr = max(k - g0, 0LL);
    long long upr = min(r0, k);
    long long mx = K;
    for (long long i = K - 1; i >= 0; i--) {
      if (dp[i] != 0) {
        for (long long j = i + downr + 1; j >= i + upr + 1; j--) {
          if (j >= mx) break;
          dp[j] = dp[i] + 1;
        }
        dp[i + downr] = dp[i] + 1;
        mx = i + downr;
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i < K; i++) {
    if (dp[i] != 0) {
      long long cnt = dp[i] - 1;
      long long r0 = i;
      long long g0 = cnt * k - r0;
      cnt += (r - r0) / k + (g - g0) / k;
      ans = max(ans, cnt);
    }
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long no;
  no = 1;
  while (no--) {
    solve();
  }
  return 0;
}
