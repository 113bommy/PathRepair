#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e9 + 7;
long long powermod(long long A, long long B) {
  long long ret = 1;
  A %= MAX;
  B %= MAX - 1;
  while (B > 0) {
    if (B % 2 > 0) ret = ret * A % MAX;
    A = A * A % MAX;
    B /= 2;
  }
  return ret;
}
long long power(long long c, long long d) {
  if (d == 0) return 1;
  long long temp1 = power(c, d / 2);
  if (d % 2 == 0)
    return temp1 * temp1;
  else
    return c * temp1 * temp1;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t, x0, n;
  cin >> t;
  while (t--) {
    cin >> x0 >> n;
    if (x0 % 2 == 0) {
      if (n % 4 == 0)
        cout << x0 << endl;
      else if (n % 2 == 0)
        cout << x0 + 1 << endl;
      else if ((n + 1) % 4 == 0)
        cout << x0 + n + 1 << endl;
      else if ((n + 1) % 2 == 0)
        cout << x0 - n << endl;
    } else {
      if (n % 4 == 0)
        cout << x0 << endl;
      else if (n % 2 == 0)
        cout << x0 - 1 << endl;
      else if ((n + 1) % 4 == 0)
        cout << -n << endl;
      else if ((n + 1) % 2 == 0)
        cout << x0 + n << endl;
    }
  }
  return 0;
}
