#include <bits/stdc++.h>
int main() {
  int a, b, hours = 0, rem = 0;
  std::cin >> a >> b;
  while (a > 0) {
    hours += a;
    int d = (a + rem) / b;
    rem = a % b;
    a = d;
  }
  std::cout << hours << "\n";
}
