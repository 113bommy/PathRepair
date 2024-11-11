#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  double s1 = 0, s2 = 0, sq = 0;
  cin >> a >> b >> c;
  sq = sqrt(b * b - 4 * a * c);
  s1 = (-b + sq) / (2 * a);
  s2 = (-b - sq) / (2 * a);
  if (s1 > s2) {
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    std::cout << s1 << '\n' << s2;
  } else {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << s2 << '\n' << s1;
  }
}
