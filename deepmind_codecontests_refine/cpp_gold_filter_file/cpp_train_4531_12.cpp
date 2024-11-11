#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long l = 0, r = 2e9;
  while (l + 1 < r) {
    long long m = (l + r) / 2;
    if (6 * m * (m + 1) / 2 <= n)
      l = m;
    else
      r = m;
  }
  if (6 * r * (r + 1) / 2 <= n) l = r;
  n -= 6 * l * (l + 1) / 2;
  long long x = 2 * l, y = 0;
  if (n == 0) return cout << x << " " << y, 0;
  x += 2;
  l++;
  if (n <= l) return cout << x - n << " " << y + 2 * n, 0;
  x -= l;
  y += 2 * l;
  n -= l;
  if (n <= l) return cout << x - 2 * n << " " << y, 0;
  x -= 2 * l;
  n -= l;
  if (n <= l) return cout << x - n << " " << y - 2 * n, 0;
  x -= l;
  y -= 2 * l;
  n -= l;
  if (n <= l) return cout << x + n << " " << y - 2 * n, 0;
  x += l;
  y -= 2 * l;
  n -= l;
  if (n <= l) return cout << x + 2 * n << " " << y, 0;
  x += 2 * l;
  n -= l;
  x += n;
  y += 2 * n;
  cout << x << " " << y;
}
