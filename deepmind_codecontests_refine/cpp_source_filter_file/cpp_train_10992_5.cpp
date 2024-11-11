#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long power(long long x, long long y, long long m = MOD) {
  x %= m;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % m;
    x = x * x % m;
    y >>= 1;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  while (T--) {
    string s;
    cin >> s;
    long long n = s.size();
    long long res = 0, a = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'a')
        a++;
      else
        res += power(2, a) - 1;
    }
    cout << res << '\n';
  }
  return 0;
}
