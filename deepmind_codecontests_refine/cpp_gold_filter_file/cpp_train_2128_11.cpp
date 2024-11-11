#include <bits/stdc++.h>
const int INF = (int)1e9;
const long long INF64 = (long long)1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;
int main() {
  long long n;
  long long kk;
  cin >> n >> kk;
  long long k = kk;
  if ((n / 2 > kk))
    cout << -1 << endl;
  else if (n == 1) {
    if (k == 0)
      cout << 1 << endl;
    else
      cout << -1 << endl;
  } else {
    long long t = n / (long long)2;
    long long a = k - (t - (long long)1);
    cout << a << " " << 2 * a << " ";
    long long cnt = 2;
    long long op = 1;
    while (cnt < n) {
      if ((op == a) || (op == 2 * a))
        op += 2;
      else if (((op + 1) == a) || ((op + 1) == 2 * a))
        op += 2;
      else {
        if (n - cnt >= 2) {
          cout << op << " " << (op + 1) << " ";
          op += 2;
          cnt += 2;
        } else {
          cout << op << " ";
          op++;
          cnt++;
        }
      }
    }
  }
  return 0;
}
