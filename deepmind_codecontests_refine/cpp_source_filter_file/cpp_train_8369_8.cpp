#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9;
const long long LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;
long long POW(long long m, long long n) {
  if (n == 1) return m;
  if (n == 0) return 1;
  long long tmp = POW(m, n / 2);
  if (n % 2) return tmp * tmp % mod * m % mod;
  return tmp * tmp % mod;
}
int main() {
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = (int)s.size() - 1; i >= 0; i--) {
    if (s[i] == '0')
      ans = ans * 2 % mod;
    else
      ans = (ans * 2 +
             POW(2, (int)s.size() - 1 - i) * POW(2, (int)s.size() - i - 1)) %
            mod;
  }
  cout << ans << endl;
}
