#include <bits/stdc++.h>
using namespace std;
void lc() { cout << endl; }
long long md(long long n) { return n; }
long long pown(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0)
    return md(pown(md(a * a), b / 2));
  else
    return md(a * pown(a, b - 1));
}
void solve() {
  long long n, r = 0;
  cin >> n;
  long long dp[65];
  dp[0] = 0;
  for (long long i = 1; i <= 60; i++) dp[i] = i + 2 * dp[i - 1];
  while (n > 0) {
    long long p;
    for (long long i = 0; i < 61; i++) {
      long long p1 = (1 << i);
      if (p1 & n) p = i;
    }
    r += dp[p] + p + 1;
    long long k = pown(2, p);
    n -= k;
  }
  cout << r;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
    lc();
  }
}
