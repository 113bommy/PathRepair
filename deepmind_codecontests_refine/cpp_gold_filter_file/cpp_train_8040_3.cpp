#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long t, a[200010];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    long long n;
    set<long long> s;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i], a[i] = a[i] % n;
    for (long long i = 0; i < n * 3; i++) s.insert(i + (a[i % n]));
    if (s.size() != 3 * n)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
  return 0;
}
