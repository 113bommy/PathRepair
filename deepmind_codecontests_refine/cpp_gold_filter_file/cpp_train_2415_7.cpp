#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
vector<long long> g[205001], par(205001), vis(205001), dis(205001);
long long mm(long long x, long long y) {
  x %= M, y %= M;
  return (x * y) % M;
}
long long po(long long x, long long y) {
  if (!y) return 1;
  long long a = po(x, y / 2) % M;
  if (y % 2) return mm(a, mm(a, x));
  return mm(a, a);
}
void solve() {
  long long n;
  cin >> n;
  long long m = n, ans = 0, c = 0;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      n /= i;
      ans = i;
    }
    if (ans) break;
  }
  if (n == m)
    cout << n;
  else if (n == 1)
    cout << ans;
  else
    cout << 1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
