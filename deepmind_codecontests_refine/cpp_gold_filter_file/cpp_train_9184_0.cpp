#include <bits/stdc++.h>
using namespace std;
long long n, h, l, r;
long long dp[2003][2003];
long long a[2003];
bool ch(long long nn) {
  if (nn >= l && nn <= r) return 1;
  return 0;
}
long long f(long long p, long long hh) {
  if (p >= n) return ch(hh);
  long long tmp = 0;
  if (ch(hh)) tmp = 1;
  if (dp[p][hh] == -1) {
    tmp += max(f(p + 1, (hh + a[p]) % h), f(p + 1, (hh + a[p] - 1) % h));
    dp[p][hh] = tmp;
  }
  return dp[p][hh];
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> h >> l >> r;
  memset(dp, -1, sizeof dp);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << f(0, h);
  return 0;
}
