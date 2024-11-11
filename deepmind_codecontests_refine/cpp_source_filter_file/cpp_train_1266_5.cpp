#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename S37, typename... Args>
void err(istream_iterator<string> it, S37 a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
const long long N = 300010, mod = 1e9 + 7, mod2 = 1e9 + 9, mod3 = 998244353,
                sq = 450, base = 727, lg = 25, inf = 1e18 + 10;
long long n, m, x, y, w, z, t, k, ans, a[N];
string s, f[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  x = 2;
  ans = 1;
  y = 1;
  while (y < n) {
    y++;
    ans += x * 2;
    x *= 2;
  }
  cout << ans;
  return 0;
}
