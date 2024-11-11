#include <bits/stdc++.h>
int m[5], w[5], hs, hu, score;
int main() {
  for (int i = 0; i < 5; i++) {
    std::cin >> m[i];
  }
  for (int i = 0; i < 5; i++) {
    std::cin >> w[i];
    score += (((1 - m[i] / 250.0) * 500 * (i + 1) - 50 * w[i]) >
                      (0.3 * 500 * (i + 1))
                  ? ((1 - m[i] / 250.0) * 500 * (i + 1) - 50 * w[i])
                  : (0.3 * 500 * (i + 1)));
  }
  std::cin >> hs >> hu;
  std::cout << score + 100 * hs - 50 * hu;
}
