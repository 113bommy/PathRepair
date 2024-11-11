#include <bits/stdc++.h>
int main() {
  int n, m;
  std::cin >> n >> m;
  int *size = new int[n];
  for (int i = 0; i < n; ++i) std::cin >> size[i];
  std::sort(size, size + n);
  int cnt = 0;
  int sum_size = 0;
  for (int i = n - 1; i >= 0; ++i) {
    sum_size += size[i];
    cnt++;
    if (sum_size >= m) break;
  }
  std::cout << cnt;
  return 0;
}
