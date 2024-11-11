#include <bits/stdc++.h>
int main() {
  unsigned int n = 0, m = 0;
  std::cin >> n >> m;
  unsigned int* benches = new unsigned int[n];
  for (unsigned int i = 0; i < n; ++i) std::cin >> benches[i];
  unsigned int mx = 0, sum = 0;
  for (unsigned int i = 0; i < n; ++i) {
    if (benches[i] > mx) mx = benches[i];
    sum += benches[i];
  }
  unsigned int max_k = mx + m;
  unsigned int min_k = std::max(mx, (sum + m - 1) / n + 1);
  std::cout << min_k << ' ' << max_k << '\n';
  delete[] benches;
  return 0;
}
