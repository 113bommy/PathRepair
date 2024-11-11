#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1000000007;
void solve() {
  int p, q;
  cin >> p >> q;
  if (p % q)
    cout << p << "\n";
  else {
    long long x = 1;
    bool f = false;
    for (long long i = 2; i * i <= q; i++) {
      if (q % i == 0) {
        f = true;
        long long t = p;
        while (t && t % i == 0 && t % q == 0) t /= i;
        if (t % q) x = max(x, t);
        long long l = q / i;
        t = p;
        while (t && t % l == 0 && t % q == 0) t /= l;
        if (t % q) x = max(x, t);
      }
    }
    if (!f) {
      while (p % q == 0) p /= q;
      x = p;
    }
    cout << x << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
