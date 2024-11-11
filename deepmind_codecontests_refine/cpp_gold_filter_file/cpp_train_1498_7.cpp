#include <bits/stdc++.h>
const int N = 2005;
using LD = long double;
struct problem {
  int timeSmall, timeLarge, scoreSmall, scoreLarge;
  LD probFail;
} p[N];
LD score[N][N], penalty[N][N];
int n, t;
const LD eps = 1e-15;
void update(int i, int j, LD A, LD B) {
  if (A > score[i][j])
    score[i][j] = A, penalty[i][j] = B;
  else if (std::abs(score[i][j] - A) < eps && B < penalty[i][j])
    penalty[i][j] = B;
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n >> t;
  for (int i = 1; i <= n; ++i)
    std::cin >> p[i].scoreSmall >> p[i].scoreLarge >> p[i].timeSmall >>
        p[i].timeLarge >> p[i].probFail;
  std::sort(p + 1, p + n + 1, [](problem i, problem j) {
    return i.timeLarge * i.probFail * (1 - j.probFail) <
           j.timeLarge * j.probFail * (1 - i.probFail);
  });
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= t; ++j) score[i][j] = -1e100;
  score[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= t; ++j) {
      update(i, j, score[i - 1][j], penalty[i - 1][j]);
    }
    for (int j = p[i].timeSmall; j <= t; ++j) {
      update(i, j, score[i - 1][j - p[i].timeSmall] + p[i].scoreSmall,
             penalty[i - 1][j - p[i].timeSmall] + p[i].timeSmall);
    }
    for (int j = p[i].timeSmall + p[i].timeLarge; j <= t; ++j) {
      update(i, j,
             score[i - 1][j - p[i].timeSmall - p[i].timeLarge] +
                 p[i].scoreSmall + (1 - p[i].probFail) * p[i].scoreLarge,
             (1 - p[i].probFail) * j +
                 p[i].probFail *
                     (penalty[i - 1][j - p[i].timeSmall - p[i].timeLarge] +
                      p[i].timeSmall));
    }
  }
  for (int i = 0; i <= t; ++i) update(0, 0, score[n][i], penalty[n][i]);
  std::cout << std::fixed << std::setprecision(18) << score[0][0] << ' '
            << std::fixed << std::setprecision(18) << penalty[0][0] << '\n';
  return 0;
}
