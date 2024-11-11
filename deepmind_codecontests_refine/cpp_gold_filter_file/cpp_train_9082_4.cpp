#include <bits/stdc++.h>
void SolveTest() {
  long long int l, r, m;
  std::cin >> l >> r >> m;
  for (long long int a = l; a <= r; ++a) {
    for (long long int n = m / a; n <= m / a + 1; ++n) {
      if (n > 0 && abs(m - a * n) <= r - l) {
        long long int b, c;
        if (m - a * n <= 0) {
          c = r;
        } else {
          c = l;
        }
        b = m - a * n + c;
        std::cout << a << " " << b << " " << c << std::endl;
        return;
      }
    }
  }
}
int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    SolveTest();
  }
  return 0;
}
