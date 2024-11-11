#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / (gcd(a, b))); }
int power(int x, int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0) {
    int y = power(x, n / 2);
    return y * y;
  } else
    return x * power(x, n - 1);
}
int big_mod(int base, int power, int mod) {
  if (power == 0)
    return 1;
  else if (power % 2 == 0) {
    int y = (big_mod(base, power / 2, mod)) % mod;
    return (y * y) % mod;
  } else {
    int y1 = base % mod;
    int y2 = (big_mod(base, power - 1, mod)) % mod;
    return (y1 * y2) % mod;
  }
}
int main() {
  double x, y, z, t1, t2;
  scanf("%lf %lf %lf", &x, &y, &z);
  t1 = y;
  t2 = y + z;
  t1 /= t2;
  printf("%0.10lf\n", t1 * x);
}
