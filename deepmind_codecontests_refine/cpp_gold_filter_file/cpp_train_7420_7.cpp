#include <bits/stdc++.h>
using namespace std;
long long int mul(long long int x, long long int y) {
  return (x * y) % 1000000007;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, val3;
  cin >> n >> m;
  if (m > n) swap(m, n);
  if (m == 1) {
    cout << n << endl;
    return 0;
  }
  if (m == 2) {
    cout << 2 * (2 * (n / 4) + min(n % 4, 2ll)) << endl;
    return 0;
  }
  long long int val1 =
      n * ((m + 2) / 3) + (m > 3 && m % 3 == 2) + 2 * (m > 3 && m % 3 == 0);
  long long int val2 =
      m * ((n + 2) / 3) + (n > 3 && n % 3 == 2) + 2 * (n > 3 && n % 3 == 0);
  if ((n * m) % 2 == 0)
    val3 = n * m / 2;
  else
    val3 = (n * m + 1) / 2;
  cout << max(val3, max(val1, val2)) << endl;
}
