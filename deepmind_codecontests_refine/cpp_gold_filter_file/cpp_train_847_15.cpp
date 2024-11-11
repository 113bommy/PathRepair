#include <bits/stdc++.h>
using namespace std;
long long a, b, mod;
long long fpow(long long x, long long y) {
  long long r = 1LL;
  while (y > 0) {
    if (y & 1) r = r * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  while (cin >> a >> b >> mod) {
    long long x = 0;
    bool se = 1;
    while (x <= min(a, mod)) {
      long long s1 = x * fpow(10, 9) % mod;
      long long s2 = (mod - s1) % mod;
      x++;
      if (s2 <= b && ((s1 + s2) % mod == 0)) continue;
      cout << "1 ";
      string num = to_string(x - 1);
      while ((int)num.size() < 9) num = "0" + num;
      cout << num << '\n';
      se = 0;
      break;
    }
    if (se) cout << "2\n";
  }
  return 0;
}
