#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
bool comp(long long a, long long b) { return a > b; }
void sol() {}
int main() {
  ios_base::sync_with_stdio(false);
  long long f[6];
  long long k;
  cin >> k;
  for (long long i = 0; i < 6; i++) cin >> f[i];
  long long q;
  cin >> q;
  long long n;
  cin >> n;
  long long st10 = 1;
  vector<long long> dp(n + 1);
  for (int i = 1; i <= n; i++) dp[i] = -1000000000000000;
  for (long long i = 0; i < 6; i++) {
    long long mm = 3 * (k - 1);
    long long base = 1;
    while (mm) {
      base = min(base, mm);
      long long val = base * f[i];
      long long del = base * st10 * 3;
      for (int j = n; j >= del; j--) dp[j] = max(dp[j], dp[j - del] + val);
      mm -= base;
      base *= 2;
    }
    st10 *= 10;
  }
  long long ans = 0;
  for (long long last = 0; last <= n; last++) {
    long long cur = 0;
    long long d = 0;
    long long x = last;
    while (x) {
      if (x % 10 % 3 == 0) cur += x % 10 / 3 * f[d];
      x /= 10;
      d++;
    }
    ans = max(ans, dp[n - last] + cur);
  }
  cout << ans << endl;
}
