#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename S37, typename... Args>
void err(istream_iterator<string> it, S37 a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
const long long N = 300100, mod = 1e9 + 7, mod2 = 1e9 + 9, mod3 = 998244353,
                sq = 450, base = 727, lg = 25, inf = 1e18 + 10;
long long n, m, x, y, w, z, t, k, d, q, ans;
string s;
long long fun(long long xx, char c) {
  long long yy, zz = __builtin_ctzll(xx);
  if (zz == 0 && c != 'U') return xx;
  yy = xx;
  if (c == 'U') {
    yy -= (1LL << zz);
    yy |= (1LL << (zz + 1));
    if (yy > n) return xx;
    return yy;
  }
  yy += (1LL << (zz - 1));
  if (c == 'L') yy -= (1LL << zz);
  return yy;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> t;
  while (t--) {
    cin >> m >> s;
    for (int i = 0; i < s.size(); i++) m = fun(m, s[i]);
    cout << m << endl;
  }
  return 0;
}
