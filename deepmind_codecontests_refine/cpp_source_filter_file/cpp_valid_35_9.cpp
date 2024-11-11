#include <bits/stdc++.h>
using pii = std::pair<int, int>;
void run() {
  int n, m;
  std::cin >> n >> m;
  int ans = 0;
  for (int i = 30; i >= 0; --i) {
    if (((n >> i) & 1) == 1 && ((m >> i) & 1) == 1)
      continue;
    else if ((n >> i) & 1)
      break;
    else if ((m >> i) & 1)
      ans ^= (1 << i);
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  std::cin >> t;
  while (t--) run();
  return 0;
}
