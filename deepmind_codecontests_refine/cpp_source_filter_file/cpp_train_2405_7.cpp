#include <bits/stdc++.h>
using namespace std;
struct vect {
  long long x, y;
  vect() {}
  vect(long long a, long long b) {
    x = a;
    y = b;
  }
};
vect operator+(const vect& a, const vect& b) {
  return vect(a.x + b.x, a.y + b.y);
}
vect operator-(const vect& a, const vect& b) {
  return vect(a.x - b.x, a.y - b.y);
}
vect mul(const vect& a) { return vect(-a.y, a.x); }
bool solve(vect c, vect d) {
  if (c.x == 0) {
    if (c.y != 0) {
      if (d.x % c.y == 0 && d.y % c.y == 0) return true;
      return false;
    } else
      return d.x == 0 && d.y == 0;
  }
  long long p = d.y * c.x - c.y * d.x;
  long long q = c.x * c.x + c.y * c.y;
  if (p % q) return false;
  long long b = p / q;
  if ((d.x - b) % c.x) return false;
  return true;
}
int main() {
  vect a, b, c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  if (solve(c, b - a) || solve(c, b - mul(a)) || solve(c, b + a) ||
      solve(c, b + mul(a)))
    printf("YES");
  else
    printf("NO");
  return 0;
}
