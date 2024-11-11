#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int n, v;
  std::cin >> n >> v;
  int cost = std::min(n, v);
  int cur = v + 1;
  int i = 2;
  while (cur < n) {
    cost += i;
    i++;
    cur++;
  }
  std::cout << cost;
  return 0;
}
