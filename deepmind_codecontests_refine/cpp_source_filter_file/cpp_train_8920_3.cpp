#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const long double eps = 0.0000000001;
const long long INF = 0x3fffffffffffffff;
long long n, r, a, b, f[1 << 18], ans;
long double s;
signed main() {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(6);
  cin >> n >> r;
  s = 1 << n;
  for (long long i = 0; i < 1 << n; ++i) {
    cin >> f[i];
    ans += f[i];
  }
  cout << ans << endl;
  for (long long i = 1; i <= r; ++i) {
    cin >> a >> b;
    ans -= f[a];
    f[a] = b;
    ans += f[a];
    cout << ans / s << endl;
  }
  return 0;
}
