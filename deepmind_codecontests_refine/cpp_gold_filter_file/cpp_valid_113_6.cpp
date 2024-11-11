#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int32_t n;
  std::cin >> n;
  int64_t* arr = new int64_t[n];
  for (int32_t i = 0; i < n; i++) std::cin >> arr[i];
  std::sort(arr, arr + n);
  int64_t sum = 0;
  for (int32_t i = 0; i < n; i++) sum += arr[i];
  int32_t m;
  std::cin >> m;
  for (int32_t i = 0; i < m; i++) {
    int64_t x, y;
    std::cin >> x >> y;
    int64_t answer = INT64_MAX;
    int32_t attacks = std::lower_bound(arr, arr + n, x) - arr;
    if (attacks < n)
      answer = std::min(answer, std::max((int64_t)0, y - (sum - arr[attacks])));
    attacks--;
    if (attacks >= 0)
      answer =
          std::min(answer, x - arr[attacks] +
                               std::max((int64_t)0, y - (sum - arr[attacks])));
    std::cout << answer << "\n";
  }
  return 0;
}
