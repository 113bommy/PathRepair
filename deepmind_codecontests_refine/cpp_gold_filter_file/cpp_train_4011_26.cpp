#include <bits/stdc++.h>
using namespace std;
long long fun(long long n) {
  long long res = 0;
  while (n) {
    res += (n % 2);
    n >>= 1LL;
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0);
  ;
  long long s, x;
  cin >> s >> x;
  long long temp = s - x;
  long long ans;
  if (temp % 2 == 1 || temp < 0 || (temp / 2 & x))
    ans = 0;
  else {
    ans = 1LL << fun(x);
    if (s == x) ans -= 2;
  }
  cout << ans;
}
