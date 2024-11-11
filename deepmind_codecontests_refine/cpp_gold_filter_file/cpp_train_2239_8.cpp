#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, m, x1, x2, x3, x4;
  std::cin >> a >> b >> c;
  x1 = 2 * (a + b);
  x2 = c + a + b;
  x3 = 2 * (a + c);
  x4 = 2 * (b + c);
  m = min({x1, x2, x3, x4});
  std::cout << m << std::endl;
}
