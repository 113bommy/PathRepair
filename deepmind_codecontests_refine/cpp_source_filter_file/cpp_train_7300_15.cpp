#include <bits/stdc++.h>
inline int cmp(double x, double y = 0, double tol = 1e-9) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
unsigned long long int candidate, greedy, size, test, aux, min, n;
unsigned long long int c[500];
int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> c[i];
  unsigned long long int min = -1;
  for (int i = 1; i < n - 1; ++i) {
    aux = c[i - 1] - 1;
    candidate = 0;
    size = 1;
    for (int j = i; j < n; ++j) {
      if (c[j] <= aux) {
        candidate += c[j] * (aux / c[j]);
        size += aux / c[j];
        aux %= c[j];
      }
      test = candidate + c[j];
      greedy = 0;
      for (int k = i - 1; test != 0; ++k)
        if (c[k] <= test) {
          greedy += test / c[k];
          test %= c[k];
          if (greedy > size) {
            min = std::min(min, candidate + c[j]);
            break;
          }
        }
    }
  }
  std::cout << (long long int)(min) << std::endl;
  return 0;
}
