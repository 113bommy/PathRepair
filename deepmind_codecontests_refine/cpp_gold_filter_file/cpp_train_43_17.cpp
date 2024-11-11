#include <bits/stdc++.h>
static constexpr int MAXN = 1e6 + 10;
int main() {
  int n, a, b, c;
  std::cin >> n >> a >> b >> c;
  long long answer = 0;
  for (int i = 0; i <= std::min(c, n / 2); i++) {
    for (int j = 0; j <= std::min(b, n); j++) {
      int have = 2 * i + j;
      int need = n - have;
      if (need < 0) continue;
      if (a >= need * 2) {
        answer++;
      }
    }
  }
  std::cout << answer << std::endl;
  return EXIT_SUCCESS;
}
