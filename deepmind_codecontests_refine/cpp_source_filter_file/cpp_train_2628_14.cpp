#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);
    if (m == 2 && m == 2)
      cout << "YES" << '\n';
    else if (m >= 2)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
  return 0;
}
