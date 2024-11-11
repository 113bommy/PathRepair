#include <bits/stdc++.h>
using namespace std;
struct node {
  int xx, yy;
} t;
const int maxn = 2010;
bool ok[maxn];
vector<node> v[maxn];
void init() {
  for (int i = 1; i < maxn; i++) {
    for (int j = 1; j <= i; j++) {
      int tmp = sqrt(i * i + j * j) + 1e-8;
      if (tmp * tmp != i * i + j * j) continue;
      if (tmp < maxn) {
        ok[tmp] = 1;
        t.xx = i;
        t.yy = j;
        v[tmp].push_back(t);
      }
    }
  }
}
int main() {
  init();
  int x, y;
  scanf("%d%d", &x, &y);
  if (x < y) swap(x, y);
  if (ok[x] && ok[y]) {
    for (int i = 0; i < v[x].size(); i++) {
      for (int j = 0; j < v[y].size(); j++) {
        if ((v[x][i].xx + v[y][j].yy) * (v[x][i].xx + v[y][j].yy) +
                    (v[x][i].yy - v[y][j].xx) * (v[x][i].yy - v[y][j].xx) +
                    x * x ==
                y * y ||
            (v[x][i].xx + v[y][j].yy) * (v[x][i].xx + v[y][j].yy) +
                    (v[x][i].yy - v[y][j].xx) * (v[x][i].yy - v[y][j].xx) ==
                x * x + y * y) {
          puts("YES1");
          printf("0 0\n");
          printf("%d %d\n", v[x][i].xx, v[x][i].yy);
          printf("%d %d\n", -v[y][j].yy, v[y][j].xx);
          return 0;
        }
        if ((v[x][i].xx - v[y][j].yy) * (v[x][i].xx - v[y][j].yy) +
                    (v[x][i].yy - v[y][j].xx) * (v[x][i].yy - v[y][j].xx) +
                    x * x ==
                y * y ||
            (v[x][i].xx - v[y][j].yy) * (v[x][i].xx - v[y][j].yy) +
                    (v[x][i].yy - v[y][j].xx) * (v[x][i].yy - v[y][j].xx) ==
                x * x + y * y) {
          puts("YES2");
          printf("0 0\n");
          printf("%d %d\n", v[x][i].xx, v[x][i].yy);
          printf("%d %d\n", v[y][j].yy, v[y][j].xx);
          return 0;
        }
        if ((v[x][i].xx + v[y][j].xx) * (v[x][i].xx + v[y][j].xx) +
                    (v[x][i].yy - v[y][j].yy) * (v[x][i].yy - v[y][j].yy) +
                    x * x ==
                y * y ||
            (v[x][i].xx + v[y][j].xx) * (v[x][i].xx + v[y][j].xx) +
                    (v[x][i].yy - v[y][j].yy) * (v[x][i].yy - v[y][j].yy) ==
                x * x + y * y) {
          puts("YES3");
          printf("0 0\n");
          printf("%d %d\n", v[x][i].xx, v[x][i].yy);
          printf("%d %d\n", -v[y][j].xx, v[y][j].yy);
          return 0;
        }
        if ((v[x][i].xx - v[y][j].xx) * (v[x][i].xx - v[y][j].xx) +
                    (v[x][i].yy - v[y][j].yy) * (v[x][i].yy - v[y][j].yy) +
                    x * x ==
                y * y ||
            (v[x][i].xx - v[y][j].xx) * (v[x][i].xx - v[y][j].xx) +
                    (v[x][i].yy - v[y][j].yy) * (v[x][i].yy - v[y][j].yy) ==
                x * x + y * y) {
          puts("YES4");
          printf("0 0\n");
          printf("%d %d\n", v[x][i].xx, v[x][i].yy);
          printf("%d %d\n", v[y][j].xx, v[y][j].yy);
          return 0;
        }
      }
    }
  }
  puts("NO");
  return 0;
}
