#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535897;
const int mod = 1e9 + 7;
const int M = 100005;
int INF = 1e9 + 5;
int solve() {
  long long n, k, l1, r1, l2, r2;
  cin >> n >> k >> l1 >> r1 >> l2 >> r2;
  long long ans = 0;
  if ((l2 <= l1 && l1 <= r2) || (l1 <= l2 && l2 <= r1)) {
    long long p = n * (min(r1, r2) - max(l1, l2));
    long long t = n * (abs(l2 - l1) + abs(r2 - r1));
    k -= p;
    if (k <= 0) return !(cout << "0\n");
    if (k <= t) return !(cout << k << "\n");
    k -= t;
    cout << t + 2 * k << "\n";
  } else {
    long long p = max(r2, r1) - min(l1, l2);
    long long a = max(l1, l2) - min(r1, r2);
    if (k <= p) return !(cout << a + k << "\n");
    k -= p;
    ans = a + p;
    while (n--) {
      long long r = min(k, p);
      long long m = min(2 * r, a + r);
      ans += m;
      k -= r;
    }
    ans += 2 * k;
    cout << ans << "\n";
  }
  return 0;
}
int main() {
  cin.sync_with_stdio(false);
  int t = 1, i = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
