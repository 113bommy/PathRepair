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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t, i, j, n, x, y, m, temp, ans, sum, mini, k, diff, maxi;
  string s;
  bool flag;
  t = 1;
  while (t--) {
    long long int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ans = 0;
    for (i = 0; i <= d; i++) {
      x = min(i, b);
      x = min(x, c);
      y = min(a, d - i);
      ans = max(ans, x * f + y * e);
    }
    cout << ans << "\n";
  }
}
