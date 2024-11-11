#include <bits/stdc++.h>
using namespace std;
const int N = 1024;
bool vis[N][N];
struct Chess {
  int x, y;
} rook[N], king;
int cnt[8];
int dir[8][2] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1},
                 {-1, 0},  {0, 1},  {1, 0}, {0, -1}};
int Way(Chess s) {
  if (s.x == 500 && s.y == 500) return -1;
  if (s.x == 500) return s.y > 500 ? 5 : 7;
  if (s.y == 500) return s.x > 500 ? 6 : 4;
  if (s.x < 500) return s.y > 500 ? 1 : 0;
  return s.y > 500 ? 2 : 3;
}
int Inv(int x) { return (x + 2) % 4 + ((x < 4) ? 0 : 4); }
void Go(int w) {
  king.x += dir[w][0];
  king.y += dir[w][1];
  if (vis[king.x][king.y]) king.x -= dir[w][0];
  printf("%d %d\n", king.x, king.y);
  fflush(stdout);
  int k;
  scanf("%d", &k);
  if (k <= 0) exit(0);
  vis[rook[k].x][rook[k].y] = false;
  scanf("%d %d", &rook[k].x, &rook[k].y);
  vis[rook[k].x][rook[k].y] = true;
}
int main() {
  scanf("%d %d", &king.x, &king.y);
  for (int i = 1; i <= 666; i++) {
    scanf("%d %d", &rook[i].x, &rook[i].y);
    vis[rook[i].x][rook[i].y] = true;
  }
  while (true) {
    int w = Way(king);
    if (w == -1) break;
    Go(Inv(w));
  }
  for (int i = 1; i <= 666; i++) cnt[Way(rook[i])]++;
  int w = 0;
  for (int i = 1; i < 4; i++)
    if (cnt[i] < cnt[w]) w = i;
  w = Inv(w);
  while (true) Go(w);
  return 0;
}
