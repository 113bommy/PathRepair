#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 1;
const long long MOD = 1e9 + 7;
const long double PI = 3.14159265358979323846264338;
long long fast_ex(long long a, long long n, long long m) {
  if (n == 0) return 1;
  if (n == 1) return a;
  long long x = 1;
  x *= fast_ex(a, n / 2, m);
  x %= m;
  x *= x;
  x %= m;
  if (n % 2) x *= a;
  x %= m;
  return x;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  long long one = abs(x - y) * t1;
  long long two = (abs(x - z) + abs(x - y)) * t2 + 2 * t3;
  if (two <= one)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
