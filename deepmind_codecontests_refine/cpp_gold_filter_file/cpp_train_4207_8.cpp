#include <bits/stdc++.h>
using namespace std;
int N;
bool G[1005][1005];
int Calc(int a, int b) { return a + b > 6 ? a + b - 6 : a + b; }
void Add(int x, int y) {
  int i;
  G[1][x] = G[y][x] = G[y][1] = 1;
  for (i = 2; i < x; i++) G[x][i] = G[i][y] = 1;
}
int main() {
  int i, j;
  scanf("%d", &N);
  if (N == 4) {
    puts("-1");
    return 0;
  }
  if (N & 1) {
    G[1][2] = G[2][3] = G[3][1] = 1;
    for (i = 3; i < N; i += 2) Add(i + 1, i + 2);
  } else {
    for (i = 1; i <= 6; i++) {
      G[i][Calc(i, 1)] = 1;
      if (i & 1)
        G[i][Calc(i, 2)] = G[i][Calc(i, 3)] = 1;
      else
        G[i][Calc(i, 4)] = 1;
    }
    for (i = 6; i < N; i += 2) Add(i + 1, i + 2);
  }
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= N; j++) printf("%d ", G[i][j]);
    puts("");
  }
  return 0;
}
