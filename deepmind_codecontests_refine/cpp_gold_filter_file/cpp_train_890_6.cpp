#include <bits/stdc++.h>
int main() {
  int n, m, z;
  std::cin >> n >> m >> z;
  int counter = 0;
  for (int i = 1; i * n <= z; i++) {
    if ((i * n) % m == 0) counter++;
  }
  std::cout << counter;
  return 0;
}
