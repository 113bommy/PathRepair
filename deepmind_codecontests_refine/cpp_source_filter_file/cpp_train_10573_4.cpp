#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  long long ans = 0;
  if (a != 0 && b != 0 && c != 0) ans += 256 * (min(a, min(c, d)));
  int t = (min(a, min(c, d)));
  a -= t;
  c -= t;
  d -= t;
  ans += 32 * (min(a, b));
  { std::cout << ans << '\n'; };
  return 0;
}
