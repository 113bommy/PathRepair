#include <bits/stdc++.h>
using namespace std;
int Mod;
long long int u, v;
int calculate(long long int a, long long int d, long long int n,
              long long int l, long long int r) {
  if (v < a || u > a + d * (n - 1)) return 0;
  if (l == 1 && r == n) {
    if (u <= a)
      l = 1;
    else
      l = (u - a - 1) / d + 2;
    if (v >= a + d * (n - 1))
      r = n;
    else
      r = (v - a) / d + 1;
    long long int x = a * 2 + (l + r - 2) * d, y = r - l + 1;
    if (x & 1)
      y >>= 1;
    else
      x >>= 1;
    return x % Mod * (y % Mod) % Mod;
  }
  long long int mid = (n + 1) >> 1;
  if (r <= mid) return calculate(a, d << 1, mid, l, r);
  if (l > mid) return calculate(a + d, d << 1, n - mid, l - mid, r - mid);
  return (calculate(a, d << 1, mid, l, mid) +
          calculate(a + d, d << 1, n - mid, 1, r - mid)) %
         Mod;
}
int main() {
  int m;
  long long int n, l, r;
  cin >> n >> m >> Mod;
  while (m--) {
    cin >> l >> r >> u >> v;
    cout << calculate(1, 1, n, l, r);
  }
  return 0;
}
