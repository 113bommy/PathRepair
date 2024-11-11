#include <bits/stdc++.h>
void process(int a, int b, int c) {
  double D = sqrt(b * b - 4 * a * c);
  double x1 = (0.0 - b - D) / 2 * a;
  double x2 = (0.0 - b + D) / 2 * a;
  double temp;
  if (x1 < x2) {
    temp = x1;
    x1 = x2;
    x2 = temp;
  }
  std::cout << std::setprecision(14) << x1 << std::endl << x2 << std::endl;
}
int main() {
  int a, b, c;
  while (std::cin >> a >> b >> c) {
    process(a, b, c);
  }
}
