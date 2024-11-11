#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double eps = 1e-10;
const double pi = acos(-1);
int T, cases, n, m;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (2 * n * m % k) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  cout << "0 0" << endl;
  long long a, b;
  if (2 * m % k == 0)
    a = n, b = 2 * m / k;
  else if (2 * n % k == 0)
    a = 2 * n / k, b = m;
  else {
    int tmp = 2 * n * m / k;
    for (a = 1;; a++)
      if (tmp % a == 0) {
        if (tmp / a < m) {
          b = tmp / a;
          break;
        }
        if (a <= m && tmp / a <= n) {
          b = a, a = tmp / a;
          break;
        }
      }
  }
  cout << "0 " << b << endl;
  cout << a << " 0" << endl;
  return 0;
}
