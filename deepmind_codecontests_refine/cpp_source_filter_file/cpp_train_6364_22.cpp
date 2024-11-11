#include <bits/stdc++.h>
int main() {
  int N;
  std::cin >> N;
  std::vector<int> V(N);
  for (int i = 0; i < N; i++) std::cin >> V[i];
  int sol = 0;
  int cost = 101 * 1001;
  for (int i = 0; i < 101; i++) {
    int ca = 0;
    for (int v : V) {
      if (std::abs(v - i) <= 1) continue;
      if (v > i)
        ca += (v - i - 1);
      else
        ca += (i - v - 1);
    }
    if (ca < cost) {
      sol = i;
      cost = ca;
    }
  }
  std::cout << sol << " " << cost << std::endl;
  return 0;
}
