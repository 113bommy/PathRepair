#include <bits/stdc++.h>
using namespace std;
long long licz1(long long x) {
  if (x < 0) return 0;
  return x * (x - 1) + x;
}
long long licz2(long long x) {
  if (x < 0) return 0;
  return (1 + x) * x / 2;
}
long long Ile(long long n, long long x, long long y, long long t) {
  long long il = 2 * t * t + 2 * t + 1;
  il -= licz1(t + 1 - x);
  il -= licz1(t + 1 - y);
  il -= licz1(t + 1 - (n - x + 1));
  il -= licz1(t + 1 - (n - y + 1));
  il += licz2(t + 1 - x - (n - y + 1));
  il += licz2(t + 1 - x - y);
  il += licz2(t + 1 - (n - x + 1) - (n - y + 1));
  il += licz2(t + 1 - (n - x + 1) - y);
  return il;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long n, x, y, c;
  cin >> n >> x >> y >> c;
  long long l = 0, p = n, s, r = -1;
  while (l <= p) {
    s = (l + p) / 2;
    if (Ile(n, x, y, s) >= c) {
      r = s;
      p = s - 1;
    } else
      l = s + 1;
  }
  cout << r;
  return 0;
}
