#include <bits/stdc++.h>
using namespace std;
long long power_up(long long a, long long n) {
  if (n == 1) return a;
  long long ret = power_up(a, n / 2);
  ret = (ret * ret) % 1000000007;
  if (n % 2 == 1) ret = (ret * a) % 1000000007;
  return ret;
}
int main() {
  long long m, n;
  cin >> n >> m;
  if (m == 1) {
    cout << 1 << endl;
    return 0;
  }
  long long ans = power_up(m, n);
  long long temp = (m * power_up(m - 1, 1000000007 - 2)) % 1000000007;
  long long vemp = power_up(m + m - 1, n);
  vemp = (vemp - ans) % 1000000007;
  if (vemp < 0) vemp += 1000000007;
  temp = (temp * vemp) % 1000000007;
  ans = (ans + temp) % 1000000007;
  cout << ans << endl;
  return 0;
}
