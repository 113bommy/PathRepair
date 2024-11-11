#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long bestPos(long long l, long long x, long long n) {
  if (x <= (l + 1) / 2)
    return 0;
  else if (x >= n - (l + 1) / 2)
    return n - l;
  else
    return x - (l + 1) / 2;
}
int main() {
  long long n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  long long g = gcd(a, b);
  long long A = a / g, B = b / g;
  long long k = min(n / A, m / B);
  long long maxX = A * k;
  long long maxY = B * k;
  long long _x = bestPos(maxX, x, n);
  long long _y = bestPos(maxY, y, m);
  cout << _x << ' ' << _y << ' ' << _x + maxX << ' ' << _y + maxY;
  return 0;
}
