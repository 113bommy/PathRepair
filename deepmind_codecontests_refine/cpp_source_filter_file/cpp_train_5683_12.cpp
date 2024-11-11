#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
string s;
long long pow_m(long long x, long long y, long long mod) {
  long long t = x;
  long long ret = 1;
  while (y > 0) {
    if (x & 1) {
      ret = (ret * t) % mod;
    }
    t = (t * t) % mod;
    y >>= 1;
  }
  return ret % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  int m;
  cin >> m;
  long long slen = s.size();
  long long x = 0;
  for (int i = 0; i < slen; i++) {
    x = (x * 10 + s[i] - '0') % m;
  }
  long long ten = pow_m(10, slen - 1, m);
  long long ans = x;
  for (long long i = 0; i < slen - 1; i++) {
    x = (x + m - ten * (s[i] - '0') % m) % m;
    x = (x * 10 + s[i] - '0') % m;
    if (s[i + 1] != '0') {
      ans = min(ans, x);
    }
  }
  cout << ans << endl;
  return 0;
}
