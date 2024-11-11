#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
mt19937 rnd(time(nullptr));
const long long INF = 1e18, X1 = 2007, P1 = 1e9 + 7, X2 = 20072007,
                P2 = 1e9 + 9;
vector<pair<long long, long long> > h, pw;
long long get_h1(long long a, long long b) {
  return ((h[b].first - h[a].first * pw[b - a].first) % P1 + P1) % P1;
}
long long get_h2(long long a, long long b) {
  return ((h[b].second - h[a].second * pw[b - a].second) % P2 + P2) % P2;
}
bool check(long long l1, long long r1, long long l2, long long r2) {
  long long ln1 = r1 - l1 + 1, ln2 = r2 - l2 + 1, h1 = get_h1(l2, r2 + 1),
            h2 = h1 = get_h2(l2, r2 + 1);
  if (ln2 > ln1) return false;
  for (long long i = l1; i <= r1 - ln2 + 1; i++)
    if (get_h1(i, i + ln2) == h1 && get_h2(i, i + ln2) == h2) return true;
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  h.resize(n + 1);
  pw.resize(n + 1);
  pw[0].first = 1;
  pw[0].second = 1;
  for (long long i = 0; i < n; i++) {
    h[i + 1].first = (h[i].first * X1 + s[i]) % P1;
    h[i + 1].second = (h[i].second * X2 + s[i]) % P2;
    pw[i + 1].first = (pw[i].first * X1) % P1;
    pw[i + 1].second = (pw[i].second * X2) % P2;
  }
  vector<long long> pr(n, INF);
  for (long long i = 0; i < n - 1; i++) {
    long long l = 0, r = n - i;
    while (r - l > 1) {
      long long mid = (l + r) / 2;
      if (check(0, i, i + 1, i + mid))
        l = mid;
      else
        r = mid;
    }
    pr[i] = l + i;
  }
  vector<long long> dp(n, INF);
  dp[0] = a;
  for (long long i = 1; i < n; i++) {
    dp[i] = dp[i - 1] + a;
    for (long long j = 0; j < i; j++) {
      if (pr[j] >= i) {
        dp[i] = min(dp[i], dp[j] + b);
      }
    }
  }
  cout << dp[n - 1];
  return 0;
}
