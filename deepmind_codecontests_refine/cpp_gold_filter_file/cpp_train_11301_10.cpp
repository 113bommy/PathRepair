#include <bits/stdc++.h>
using namespace std;
int mult(int x, int y) {
  long long int ans, x1 = (long long int)x, y1 = (long long int)y;
  ans = (x1 * y1) % 1000000007;
  return (int)ans;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int pow1(int a, int b) {
  int ans = 1;
  while (b > 0) {
    if (b & 1) ans = mult(ans, a);
    a = mult(a, a);
    b >>= 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  ;
  long long int l1, r1, l2, r2, k, ans = 0;
  cin >> l1 >> r1 >> l2 >> r2 >> k;
  if (r2 < l1 || l2 > r1)
    ans = 0;
  else {
    if (l2 >= l1 && r2 > r1) {
      ans = r1 - l2 + 1;
      if (k >= l2 && k <= r1) ans--;
    } else if (l2 >= l1 && r2 <= r1) {
      ans = r2 - l2 + 1;
      if (k >= l2 && k <= r2) ans--;
    } else if (l2 < l1 && r2 <= r1) {
      ans = r2 - l1 + 1;
      if (k >= l1 && k <= r2) ans--;
    } else if (l2 < l1 && r2 > r1) {
      ans = r1 - l1 + 1;
      if (k >= l1 && k <= r1) ans--;
    }
  }
  cout << ans << "\n";
  return 0;
}
