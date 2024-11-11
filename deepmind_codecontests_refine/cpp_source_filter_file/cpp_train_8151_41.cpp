#include <bits/stdc++.h>
using namespace std;
void code() {
  long long n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  long long x = (k * l) / n;
  long long y = c * d;
  long long z = p / np;
  long long res = min({x, y, z}) / n;
  cout << res << endl;
}
signed main() {
  cin.tie(NULL);
  cout.tie(NULL);
  code();
  return 0;
}
