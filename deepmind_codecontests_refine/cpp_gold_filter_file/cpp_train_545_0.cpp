#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long& x : a) cin >> x;
  const auto f = [&a](long long l, long long r, long long mult) {
    cout << l << ' ' << r << '\n';
    for (long long i = l; i <= r; i++) {
      cout << a[i - 1] * mult << ' ';
    }
    cout << '\n';
  };
  if (n == 1) {
    f(1, 1, -1);
    f(1, 1, 0);
    f(1, 1, 0);
    return 0;
  }
  f(1, n - 1, n - 1);
  f(n, n, n - 1);
  f(1, n, -n);
}
