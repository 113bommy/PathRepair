#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int mod = 1000000007;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  long long int ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  long long int zz = 1;
  if (ax == ay && bx == by) {
    zz = 0;
  }
  cout << power(k, n * m - r * c * zz, mod);
}
