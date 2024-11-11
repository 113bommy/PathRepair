#include <bits/stdc++.h>
const int N = 5000 + 5;
char c1[5][5];
char c2[5][5];
struct point {
  int x, y;
  point(int xi = 0, int yi = 0) : x(xi), y(yi) {}
} nxt[5][5];
int main(int argc, char const *argv[]) {
  scanf("%s", c1[1] + 1);
  scanf("%s", c1[2] + 1);
  scanf("%s", c2[1] + 1);
  scanf("%s", c2[2] + 1);
  nxt[1][1] = point(1, 2);
  nxt[1][2] = point(2, 2);
  nxt[2][2] = point(2, 1);
  nxt[2][1] = point(1, 1);
  bool flag = false;
  for (int r = 0; r < 4; ++r) {
    int x, y;
    for (int i = 1; i <= 2; ++i)
      for (int j = 1; j <= 2; ++j) {
        if (c1[i][j] == 'X') {
          x = i;
          y = j;
          break;
        }
      }
    bool eq = true;
    for (int i = 1; i <= 2; ++i)
      for (int j = 1; j <= 2; ++j) {
        if (c1[i][j] != c2[i][j]) {
          eq = false;
          break;
        }
      }
    if (eq) {
      flag = true;
      break;
    }
    std::swap(c1[x][y], c1[nxt[x][y].x][nxt[x][y].y]);
  }
  puts(flag ? "YES" : "NO");
  return 0;
}
