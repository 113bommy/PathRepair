#include <bits/stdc++.h>
const long long M = 10004205361450474ll;
const int Q_LIM = 5, K_LIM = 10000;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  static long long f[Q_LIM][K_LIM + 1];
  for (int i = 1; i < Q_LIM; ++i) {
    for (int j = 1; j <= K_LIM; ++j) {
      f[i][j] = f[i - 1][j];
      long long now = j + f[i][j] + 1;
      for (int k = 0; k < j; ++k) {
        if (now >= K_LIM) {
          f[i][j] += (f[i - 1][K_LIM] + 1) * (j - k);
          break;
        }
        f[i][j] += f[i - 1][now] + 1;
        now = j + f[i][j] + 1;
      }
    }
  }
  long long j = 1;
  for (int i = Q_LIM; i >= 1; --i) {
    std::vector<long long> pos;
    long long p = f[i - 1][std::min<long long>(j, K_LIM)];
    long long now = j + p;
    for (int k = 0; k < j && k < K_LIM; ++k) {
      if (now > M) {
        break;
      }
      pos.push_back(now);
      p += f[i - 1][std::min<long long>(now, K_LIM)] + 1;
      now = j + p;
    }
    std::cout << pos.size() << " ";
    for (long long p : pos) {
      std::cout << p << " ";
    }
    std::cout << std::endl;
    int res;
    std::cin >> res;
    if (res < 0) {
      return 0;
    }
    if (res > 0) {
      j = pos[res - 1] + 1;
    }
  }
}
