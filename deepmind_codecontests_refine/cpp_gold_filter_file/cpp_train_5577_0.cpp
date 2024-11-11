#include <bits/stdc++.h>
using namespace std;
const long long nmax = (long long)2e5 + 20;
signed main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b, c;
  cin >> n >> a >> b >> c;
  long long rem = n % 4;
  long long ans = 0;
  if (rem > 0) {
    rem = 4 - rem;
    if (rem == 1) {
      ans += min(a, min(b + c, 3 * c));
    }
    if (rem == 2) {
      ans += min(a + a, min(b, 2 * c));
    }
    if (rem == 3) {
      ans += min(3 * a, min(b + a, c));
    }
  }
  cout << ans << endl;
  return 0;
}
