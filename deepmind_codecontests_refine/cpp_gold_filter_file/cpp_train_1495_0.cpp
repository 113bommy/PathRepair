#include <bits/stdc++.h>
using namespace std;
long long f(long long l) {
  if (l < 10ll) return l;
  long long L = l, t = 1ll, ans = 0ll;
  int x = 0, last;
  while (L) {
    x++;
    last = L % 10;
    L /= 10;
  }
  for (int i = 1; i < x; i++) {
    ans += 9ll * t;
    if (i >= 2) t *= 10ll;
  }
  ans += (last - 1ll) * t;
  if (x >= 2) t *= 10ll;
  l -= t * 1ll * last;
  ans += l / 10ll;
  if (l % 10 >= last) ans++;
  return ans;
}
int main() {
  long long l, r;
  cin >> l >> r;
  cout << f(r) - f(l - 1);
  return 0;
}
