#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 7;
const long long N = 2e5 + 7;
const long double Pi = 3.14159265358979323846;
signed main() {
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(11);
  };
  long long tests;
  cin >> tests;
  for (long long test = 0; test < tests; test++) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long k1 = n / k;
    if (k1 >= m)
      cout << m << '\n';
    else {
      long long x, y;
      x = k1;
      m -= k1;
      k--;
      y = m / k + (m % k != 0);
      cout << x - y << '\n';
    }
  }
  return 0;
}
