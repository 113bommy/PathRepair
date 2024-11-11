#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct pt {
  long long x, y;
  void read() { scanf("%I64d%I64d", &x, &y); }
  pt() {}
  pt(long long _x, long long _y) {
    x = _x;
    y = _y;
  }
  pt next() { return pt(y, -x); }
  double mag() const { return sqrt(x * x + y * y); }
  double operator*(const pt &a) const { return x * a.x + y * a.y; }
  pt operator-(const pt &a) const { return pt(x - a.x, y - a.y); }
} A, B, C;
bool ok(const pt &delta, const pt &C) {
  if (C.x == 0 && C.y == 0) return delta.x == 0 && delta.y == 0;
  long long a = C.x, b = C.y, c = delta.x, d = delta.y;
  long long r = d * a - c * b;
  if (r % (a * a + b * b) == 0) {
    long long y = r / (a * a + b * b);
    if (a != 0) return (c + b * y) % a == 0;
    if (b != 0) return (d - a * y) % b == 0;
  }
  return false;
}
int main() {
  A.read();
  B.read();
  C.read();
  bool ans = false;
  for (int i = 0; i < 4; i++) {
    pt delta = B - A;
    if (ok(delta, C)) {
      ans = true;
      break;
    }
    A = A.next();
  }
  if (ans)
    printf("YES\n");
  else
    printf("NO\n");
}
