#include <bits/stdc++.h>
const int maxn = 6e4 + 10;
const int inf = 0x3f3f3f3f;
const double eps = 1e-7;
const int mod = 1e9 + 7;
const double pi = acos(-1.0);
using namespace std;
int main() {
  long long s, x;
  cin >> s >> x;
  long long t = s - x;
  if (t < 0 && t & 1) {
    puts("0");
    return 0;
  }
  t /= 2;
  long long cnt = 0, ff = 1, ans = 0;
  if (s == x) ans -= 2;
  while (x) {
    if (x & 1) {
      cnt++;
      if (t & 1) ff = 0;
    }
    if (ff == 0) break;
    x >>= 1;
    t >>= 1;
  }
  if (ff == 0)
    ans = 0;
  else
    ans += (1LL << cnt);
  cout << ans << endl;
  return 0;
}
