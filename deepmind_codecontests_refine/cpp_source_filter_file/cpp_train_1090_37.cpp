#include <bits/stdc++.h>
using namespace std;
long long h, n, ans;
long long f(long long h, long long n, bool napr) {
  if (h == 0) return 0;
  if (n <= (1 << (h - 1))) {
    if (!napr)
      return 1ll + f(h - 1ll, n, !napr);
    else
      return (1ll << h) + f(h - 1ll, n, napr);
  } else {
    if (napr)
      return 1ll + f(h - 1ll, n - (1ll << (h - 1ll)), !napr);
    else
      return (1ll << h) + f(h - 1ll, n - (1ll << (h - 1ll)), napr);
  }
}
int main() {
  cin >> h >> n;
  cout << f(h, n, false);
  return 0;
}
