#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long k;
  cin >> k;
  long long cur = 0ll;
  long long pow10 = 1ll;
  for (int i = 1; i <= 100; i++) {
    long long p9 = 9ll * pow10;
    if (cur + p9 * i * 1ll >= k) {
      k -= cur;
      long long x = pow10 + (k / i * 1ll);
      long long g = k % i;
      if (g == 0) {
        g = i * 1ll;
        x--;
      }
      vector<int> v;
      while (x) {
        v.push_back(x % 10ll);
        x /= 10ll;
      }
      reverse(v.begin(), v.end());
      cout << v[g - 1] << endl;
      return 0;
    }
    cur += p9 * i * 1ll;
    pow10 *= 10ll;
  }
  return 0;
}
