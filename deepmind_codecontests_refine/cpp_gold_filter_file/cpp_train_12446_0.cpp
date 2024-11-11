#include <bits/stdc++.h>
using namespace std;
long long exgcd(long long A, long long B, long long& x, long long& y) {
  if (!B) {
    x = 1, y = 0;
    return A;
  }
  long long gcd = exgcd(B, A % B, y, x);
  y -= A / B * x;
  return gcd;
}
void gao(long long& x, long long& y, long long k1, long long k2) {
  if (x < 0) {
    long long t = (-x + k1 - 1) / k1;
    x += t * k1;
    y -= t * k2;
  } else {
    long long t = x / k1;
    x -= t * k1;
    y += t * k2;
  }
  if (y < 0) {
    long long t = (-y - k2 - 1) / (-k2);
    x += t * k1;
    y -= t * k2;
  }
}
long long calc(long long l, long long r, long long d) {
  if (l > r) return 0;
  return (r - l) / d + 1;
}
int main() {
  long long a1, b1, a2, b2, l, r, x, y;
  cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
  long long A = a1, B = -a2, C = b2 - b1;
  long long gcd = exgcd(A, B, x, y);
  if (C % gcd) return puts("0"), 0;
  x = C / gcd * x;
  y = C / gcd * y;
  long long k1 = B / gcd;
  long long k2 = A / gcd;
  if (k1 < 0) k1 = -k1, k2 = -k2;
  gao(x, y, k1, k2);
  long long T = a1 * x + b1;
  cout << calc(T, r, a1 * k1) - calc(T, l - 1, a1 * k1);
}
