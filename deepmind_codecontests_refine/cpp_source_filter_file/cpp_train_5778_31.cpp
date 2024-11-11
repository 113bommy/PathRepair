#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int ans = 0;
  ans += (min(b + a, f + a) * min(b + a, f + a) - a * a);
  ans += (min(c + d, e + d) * min(c + d, e + d) - d * d);
  ans += ((max(b, f) - min(b, f)) * min(b + a, f + a) * 4);
  cout << ans;
  return 0;
}
