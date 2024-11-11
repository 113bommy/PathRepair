#include <bits/stdc++.h>
const static int N = 50;
using namespace std;
int f[N][N][N][N][2];
char a[30][30];
int n, m;
int F(int x1, int y1, int x2, int y2, int odd) {
  int& res = f[x1][y1][x2][y2][odd];
  if (res != -1) return res;
  set<int> app;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++)
      if (((i + j) & 1) == odd) {
        int x = i + j, y = n - i + j + 1;
        if (!(x1 <= x && x <= x2 && y1 <= y && y <= y2)) continue;
        switch (a[i][j]) {
          case 'L':
            app.insert(F(x1, y1, x - 1, y2, odd) ^ F(x + 1, y1, x2, y2, odd));
            break;
          case 'R':
            app.insert(F(x1, y1, x2, y - 1, odd) ^ F(x1, y + 1, x2, y2, odd));
            break;
          case 'X':
            app.insert(
                F(x1, y1, x - 1, y - 1, odd) ^ F(x1, y + 1, x - 1, y2, odd) ^
                F(x + 1, y1, x2, y - 1, odd) ^ F(x + 1, y + 1, x2, y2, odd));
            break;
        }
      }
  res = 0;
  while (app.count(res)) res++;
  return res;
}
int main() {
  scanf("%d %d\n", &n, &m);
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (m); j++) a[i][j] = getchar();
    getchar();
  }
  memset(f, -1, sizeof(f));
  if (F(2, 2, n + m, n + m, 0) ^ F(2, 2, n + m, n + m, 1))
    puts("WIN");
  else
    puts("LOSS");
  return 0;
}
