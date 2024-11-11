#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T x, T y) {
  return y == 0 ? x : gcd(y, x % y);
}
template <typename T>
T lcm(const T &a, const T &b) {
  return (a * b) / gcd(a, b);
}
long long int ax, ay, bx, by, cx, cy;
long long int d1, d2, dx1, dx2;
long double m1, m2;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  d1 = (by - ay) * (by - ay) + (bx - ax) * (bx - ax);
  d2 = (cy - by) * (cy - by) + (cx - bx) * (cx - bx);
  dx1 = (bx - ax);
  dx2 = (cx - bx);
  if (dx1 == 0 && dx2 == 0) {
    cout << "NO\n";
    return 0;
  }
  if ((dx1 == 0 && dx2 != 0) || (dx1 == 0 && dx2 != 0)) {
    if (d1 == d2) {
      cout << "YES\n";
    } else
      cout << "NO\n";
    return 0;
  }
  m1 = ((double)(by - ay) / (bx - ax));
  m2 = ((double)(cy - by) / (cx - bx));
  cout << ((m1 != m2 && d1 == d2) ? "YES\n" : "NO\n");
  return 0;
}
