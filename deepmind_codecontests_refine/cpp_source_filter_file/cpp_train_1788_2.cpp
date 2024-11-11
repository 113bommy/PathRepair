#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
char ma[maxn * 2][maxn * 2];
long long sum[maxn * 2][maxn * 2], ex[50];
int N, M, Q;
long long Get(int x, int y) {
  if (x == 0 || y == 0) return 0;
  if (x <= 2 * N && y <= 2 * M) return sum[x - 1][y - 1];
  int t = upper_bound(ex, ex + 35, max(x / N, y / M)) - ex;
  int s;
  if (x == ex[t] * N || y == ex[t] * M || x == ex[t - 1] * N ||
      y == ex[t - 1] * M)
    s = 1LL * x * y / 2;
  else if (x > ex[t - 1] * N && y > ex[t - 1] * M) {
    s = ex[t - 1] * N * ex[t - 1] * M / 2;
    s += ex[t - 1] * N * (y - ex[t - 1] * M) / 2;
    s += ex[t - 1] * M * (x - ex[t - 1] * N) / 2;
    s += Get(x - ex[t - 1] * N, y - ex[t - 1] * M);
  } else if (x > ex[t - 1] * N) {
    s = ex[t - 1] * N * y / 2;
    s += (x - ex[t - 1] * N) * y - Get(x - ex[t - 1] * N, y);
  } else {
    s = ex[t - 1] * M * x / 2;
    s += (y - ex[t - 1] * M) * x - Get(x, y - ex[t - 1] * M);
  }
  return s;
}
int main() {
  for (int i = 0; i < 35; i++) ex[i] = 1LL << i;
  scanf("%d%d%d", &N, &M, &Q);
  for (int i = 0; i < N; i++) scanf("%s", ma[i]);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      ma[i + N][j] = ma[i][j + M] = ma[i][j] == '0' ? '1' : '0';
      ma[i + N][j + M] = ma[i][j];
    }
  for (int i = 0; i < 2 * N; i++) {
    int t = 0;
    for (int j = 0; j < 2 * M; j++) {
      t += ma[i][j] - '0';
      sum[i][j] = i == 0 ? 0 : sum[i - 1][j];
      sum[i][j] += t;
    }
  }
  while (Q--) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%lld\n", Get(x2, y2) + Get(x1 - 1, y1 - 1) - Get(x2, y1 - 1) -
                         Get(x1 - 1, y2));
  }
}
