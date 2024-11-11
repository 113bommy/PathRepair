#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long n, k, a, b, res = 0;
  cin >> n >> k;
  cin >> a >> b;
  if (k == 1) {
    cout << n * (a - 1) << endl;
    return 0;
  }
  while (n >= k) {
    if (!(n % k) && a * (n - n / k) >= b) {
      n /= k;
      res += b;
    } else if (!(n % k)) {
      res += a * (n - n / k);
      n /= k;
    } else {
      res += a * (n % k);
      n -= n % k;
    }
  }
  cout << res + a * (n - 1) << endl;
}
