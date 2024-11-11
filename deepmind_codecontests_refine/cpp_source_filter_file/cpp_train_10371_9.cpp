#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T x, T y) {
  if (x < y) swap(x, y);
  while (y > 0) {
    T f = x % y;
    x = y;
    y = f;
  }
  return x;
}
template <typename T>
pair<T, T> exgcd(T x, T y) {
  if (x < y) swap(x, y);
  pair<T, T> r = make_pair(1, 0);
  while (y > 0) {
    T f = x % y;
    r = make_pair(r.second, r.first - (x / y) * r.second);
    x = y;
    y = f;
  }
  return r;
}
int N, T;
double P[1 << 7][1 << 7];
double WP[1 << 10][7];
double DP[1 << 10][7];
void update(int i, int j, int level) {
  WP[i][level] += WP[i][level - 1] * WP[j][level - 1] * P[i][j];
}
void solve(int level, int fr, int to) {
  if (fr == to - 1) return;
  int m = (fr + to) / 2;
  solve(level - 1, fr, m);
  solve(level - 1, m + 1, to);
  for (int i = fr; i <= m; i++)
    for (int j = m + 1; j <= to; j++) update(i, j, level), update(j, i, level);
  for (int i = fr; i <= m; i++)
    for (int j = m + 1; j <= to; j++)
      DP[i][level] = max(DP[i][level], DP[i][level - 1] + DP[j][level - 1] +
                                           WP[i][level] * (1 << level)),
      DP[j][level] = max(DP[j][level], DP[j][level - 1] + DP[i][level - 1] +
                                           WP[j][level] * (1 << level));
}
int main(int argc, char *argv[]) {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> N;
  {
    T = 1 << N;
    memset(WP, 0, sizeof(WP));
    memset(DP, 0, sizeof(DP));
    for (int i = 0; i < T; i++) {
      for (int j = 0; j < T; j++) {
        cin >> P[i][j];
        P[i][j] /= 100;
      }
    }
    for (int i = 0; i < T; i++) {
      WP[i][0] = P[i][i ^ 1];
      DP[i][0] = P[i][i ^ 1];
    }
    solve(N - 1, 0, T - 1);
    double res = 0;
    for (int i = 0; i < T; i++) {
      res = max(res, DP[i][N - 1]);
    }
    printf("%.9lg\n", res);
  }
  return 0;
}
