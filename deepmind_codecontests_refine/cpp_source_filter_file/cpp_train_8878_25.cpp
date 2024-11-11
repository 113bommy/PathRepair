#include <bits/stdc++.h>
using namespace std;
long long foo(long long x) {
  long long z = 0;
  long long i = 1;
  while (x) {
    long long y = x % 10;
    if ((y == 7) || (y == 4)) {
      z += i * y;
      i *= 10;
    }
    x /= 10;
  }
  return z;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, x, t, m, y, z, k;
  cin >> x >> y;
  while (foo(x) != y) x++;
  cout << x;
  return 0;
}
