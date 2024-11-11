#include <bits/stdc++.h>
using namespace std;
const double EPS = 1E-10;
inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
char M[440][440];
int C[440][440];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int main() {
  int N, K;
  cin >> N >> K;
  N += 200;
  for (int i = 200; i < N; i++)
    for (int j = 200; j < N; j++) cin >> M[i][j];
  for (int i = 200; i < N; i++)
    for (int j = 200; j < N; j++)
      if (M[i][j] == '.') {
        for (int d = 0; d < 4; d++) {
          bool ok = 1;
          int y = i, x = j;
          for (int k = 0; k < K && ok; k++, y += dy[d], x += dx[d])
            if (M[y][x] != '.') ok = 0;
          y = i, x = j;
          if (ok)
            for (int k = 0; k < K; k++) C[y][x]++, y += dy[d], x += dx[d];
        }
      }
  int rety = 0, retx = 0, ret = 0;
  for (int i = 200; i < N; i++)
    for (int j = 200; j < N; j++)
      if (ret < C[i][j]) ret = C[i][j], rety = i - 200, retx = j - 200;
  printf("%d %d\n", rety + 1, retx + 1);
  return 0;
}
