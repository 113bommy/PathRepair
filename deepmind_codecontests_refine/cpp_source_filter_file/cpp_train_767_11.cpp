#include <bits/stdc++.h>
using namespace std;
const int D[8][2] = {{1, 0},  {0, 1},  {-1, 0},  {0, -1},
                     {1, -1}, {-1, 1}, {-1, -1}, {1, 1}};
int N, M, K, f[600005], F[3005][9005];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
bool can(int& x, int& y) {
  if (!y) y = 2 * M;
  if (y > 2 * M) y = 1;
  return 1 <= x && x <= N && F[x][y];
}
bool check(int x, int y) {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      int x1 = x + D[i][0], y1 = y + D[i][2], x2 = x + D[j][0],
          y2 = y + M + D[j][1];
      if (can(x1, y1) && can(x2, y2) && find(F[x1][y1]) == find(F[x2][y2]))
        return 0;
    }
  return 1;
}
void add(int x, int y, int z) {
  F[x][y] = z;
  for (int i = 0; i < 8; i++) {
    int xx = x + D[i][0], yy = y + D[i][1];
    if (can(xx, yy)) f[find(F[xx][yy])] = find(z);
  }
}
void doit() {
  int ans = 0;
  scanf("%d%d%d", &N, &M, &K);
  if (M == 1) {
    puts("0");
    return;
  }
  for (int i = 1; i <= 2 * K; i++) f[i] = i;
  for (int i = 1, x, y; i <= K; i++) {
    scanf("%d%d", &x, &y);
    if (check(x, y)) add(x, y, i), add(x, y + M, i + K), ans++;
  }
  printf("%d\n", ans);
}
int main() {
  doit();
  return 0;
}
