#include <bits/stdc++.h>
using namespace std;
void testCase() {
  long long n;
  cin >> n;
  long long a, b, c;
  cin >> a >> b >> c;
  long long x, y, z;
  cin >> x >> y >> z;
  assert(a + b + c == n);
  assert(x + y + z == n);
  long long mx = 0;
  mx += min(a, y);
  mx += min(b, z);
  mx += min(c, x);
  long long mn = 0;
  mn = max(mn, a - x - z);
  mn = max(mn, b - y - x);
  mn = max(mn, c - z - y);
  cout << mn << ' ' << mx << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) testCase();
  return 0;
}
