#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e8;
int main() {
  ios_base::sync_with_stdio(0);
  long long s, x;
  cin >> s >> x;
  long long a = (s - x);
  if (a % 2 != 0 || a < 0) {
    cout << 0 << '\n';
    return 0;
  }
  a >>= 1;
  if (a & x != 0) {
    cout << 0 << '\n';
    return 0;
  }
  long long ans = 1;
  long long t = __builtin_popcountll(x);
  ans = (1ll << t);
  if (x == s) ans -= 2;
  cout << ans << '\n';
  return 0;
}
