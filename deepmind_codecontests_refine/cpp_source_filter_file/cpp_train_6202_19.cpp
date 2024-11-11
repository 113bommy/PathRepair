#include <bits/stdc++.h>
int sgn(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
int main(void) {
  int s, x1, x2;
  int t1, t2;
  int p, d;
  std::cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
  int byfoot = abs(x1 - x2);
  int bytram = abs(x1 - x2);
  if (sgn(d) == sgn(x2 - x1)) {
    if (d == 1) {
      if (p < x1) {
        bytram += abs(x1 - p);
      } else {
        bytram += s - p + s - x1;
      }
    } else {
      if (p > x1) {
        bytram += p - x1;
      } else {
        bytram += p + s + s - x1;
      }
    }
  } else {
    if (d == 1) {
      bytram += s - x1 + (s - p);
    } else {
      bytram += x1 + p;
    }
  }
  std::cout << std::min(t2 * byfoot, t1 * bytram) << std::endl;
  return 0;
}
