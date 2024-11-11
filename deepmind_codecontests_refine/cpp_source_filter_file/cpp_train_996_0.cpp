#include <bits/stdc++.h>
using namespace ::std;
int a, b, c, d;
int ExtendGcd(int a, int b, int &x, int &y) {
  int d = a;
  if (b != 0) {
    d = ExtendGcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
void solve() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  int x, y;
  int g = ExtendGcd(a, c, x, y);
  if ((d - b) % g) {
    puts("-1");
    return;
  }
  x *= (d - b) / g;
  int mod = c / g;
  x = (x % mod + mod) % mod;
  while (a * x + b <= d) {
    x += mod;
  }
  printf("%d\n", a * x + b);
}
int main() {
  solve();
  return 0;
}
