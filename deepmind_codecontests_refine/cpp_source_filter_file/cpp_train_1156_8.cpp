#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n, m;
  cin >> n;
  m = n;
  ll mt = 0, r = 0, x = 1, t = 0;
  for (ll i = 2; i * i <= n; i++) {
    t = 0;
    while (n % i == 0) n /= i, t++;
    if (t) x *= i;
    if (mt != 0 && t != mt) r = 1;
    mt = max(t, mt);
  }
  if (n == m) return cout << m << ' ' << 0, 0;
  if (n != 1) {
    t = 1;
    x *= n;
    if (t != mt) r = 1;
    mt = max(t, mt);
  }
  if (mt == 1) return cout << m << ' ' << 0, 0;
  if (__builtin_popcount(mt) == 1)
    return cout << x << ' ' << __builtin_ctz(mt) + r, 0;
  while (mt != (mt & -mt)) mt -= mt & -mt;
  mt <<= 1;
  cout << x << ' ' << __builtin_ctz(mt) + 1;
}
