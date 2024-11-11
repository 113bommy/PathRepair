#include <bits/stdc++.h>
int main() {
  int n, m;
  int aux;
  int pieces = 0;
  std::cin >> n >> m;
  if (m > n) {
    aux = n;
    n = m;
    m = aux;
  }
  pieces += (n / 2) * m;
  if ((n % 2) == 1) {
    pieces += m / 2;
  }
  std::cout << pieces;
}
