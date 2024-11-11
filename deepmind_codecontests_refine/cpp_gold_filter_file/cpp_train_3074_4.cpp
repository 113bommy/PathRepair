#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
const int logn = 20;
const int inf = (int)1e9;
const long long mod = (int)1e9 + 7;
const long long l_inf = (long long)4e18;
const long double pi = acosl(-1.0);
const long double eps = 1e-9;
bool check(long long s, long long x) {
  for (long long i = 50; i >= 0; i--) {
    if (x & (1ll << i)) continue;
    if (x + 2ll * (1ll << i) <= s) x += 2ll * (1ll << i);
  }
  return x == s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(15);
  cout << fixed;
  srand(566);
  long long s, x;
  cin >> s >> x;
  if (x > s || !check(s, x)) {
    cout << 0;
    exit(0);
  }
  long long cnt = 0;
  for (long long i = 0; (1ll << i) <= x; i++)
    if (x & (1ll << i)) cnt++;
  long long ans = 1ll << cnt;
  if (s == x) ans -= 2;
  cout << ans;
  return 0;
}
