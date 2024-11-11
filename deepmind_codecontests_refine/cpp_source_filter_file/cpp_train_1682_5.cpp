#include <bits/stdc++.h>
using namespace std;
long long n, m, i, x, y, z, d;
long long gcd(long long u, long long v) { return v ? gcd(v, u % v) : u; }
int main() {
  cin >> n >> m;
  cin >> x;
  for (i = 2; i <= n; i++) cin >> y, d = gcd(y - x, d);
  for (i = 1; i <= m; i++) {
    cin >> x;
    if (d % x == 0) {
      cout << "YES" << endl;
      cout << x << " " << i;
      return 0;
    }
  }
  cout << "NO";
}
