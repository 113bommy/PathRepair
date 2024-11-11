#include <bits/stdc++.h>
int N, x[2500], y[2500];
double f[2500][2500], g[2500][2500], dis[2500][2500];
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d%d", x + i, y + i);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      dis[i][j] = sqrt((long long)(x[i] - x[j]) * (x[i] - x[j]) +
                       (long long)(y[i] - y[j]) * (y[i] - y[j]));
  for (int i = 0; i < N; i++) {
    f[i][i] = dis[(i + N - 1) % N][i];
    g[i][i] = dis[(i + 1) % N][i];
  }
  for (int i = 2; i < N; i++)
    for (int jl = N - 1, j = 0, jr = 1, kl = i - 2, k = i - 1, kr = i; j < N;
         ++jl == N ? jl = 0 : jl, j++, ++jr == N ? jr = 0 : jr,
             ++kl == N ? kl = 0 : kl, ++k == N ? k = 0 : k,
             ++kr == N ? kr = 0 : kr) {
      f[j][k] = std::max(dis[jl][j] + f[jr][k], dis[jl][k] + g[j][kl]);
      g[j][k] = std::max(dis[kr][j] + f[jr][k], dis[kr][k] + g[j][kl]);
    }
  double O = 0;
  for (int i = 0; i < N; i++)
    O = std::max(O, std::max(f[i + 1 == N ? 0 : i + 1][i ? i - 1 : N - 1],
                             g[i + 1 == N ? 0 : i + 1][i ? i - 1 : N - 1]));
  printf("%.10lf\n", O);
}
