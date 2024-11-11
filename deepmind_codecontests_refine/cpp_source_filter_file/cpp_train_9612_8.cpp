#include <bits/stdc++.h>
int P = 1e9 + 7, N, a, r = 1;
int main() {
  for (std::cin >> N; --N; a = (r - a) % P) r = 3LL * r % P;
  std::cout << a;
}
