#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (a > 0) {
    b %= a;
    swap(a, b);
  }
  return b;
}
int main() {
  long long n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  long long g = gcd(a, b);
  b /= g;
  a /= g;
  long long yy = (n / a) * b, xx = (yy * a) / b;
  if (yy > m || xx > n) xx = (m / b) * a, yy = (xx * b) / a;
  long long lx = x - (xx + 1) / 2, ly = y - (yy + 1) / 2;
  if (lx < 0) lx = 0;
  if (lx + xx > n) lx = xx - n;
  if (ly < 0) ly = 0;
  if (ly + yy > m) ly = yy - m;
  cout << lx << " " << ly << " " << lx + xx << " " << ly + yy << "\n";
  return 0;
}
