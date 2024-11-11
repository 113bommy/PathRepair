#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
const long long pri = 1e9 + 7;
long long myPow(long long a, long long b) {
  long long ret = 1;
  while (b != 0) {
    if (b % 2 != 0) {
      ret = (ret * a) % pri;
    }
    a = (a * a) % pri;
    b /= 2;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long precision = numeric_limits<double>::digits10;
  cin >> n >> m >> k;
  if (k == -1 && (n + m) % 2 != 0)
    cout << -1 << "\n";
  else {
    long long ans = myPow(2, m - 1);
    ans = myPow(ans, n - 1);
    cout << ans << "\n";
  }
}
