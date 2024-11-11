#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 100;
const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int n, r, c, t;
bool Del[3030][6060];
int fa[N];
int Num(int x, int y) { return (x - 1) * c * 2 + y; }
bool OK(int &x, int &y) {
  if (y == 0)
    y = 2 * c;
  else if (y == 2 * c + 1)
    y = 1;
  return (x > 0 && x <= r && Del[x][y]);
}
int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
bool Check(int x, int y) {
  int xx = x, yy = y + c;
  for (int i = 0; i < 8; i++) {
    int X = x + dx[i], Y = y + dy[i];
    if (!OK(X, Y)) continue;
    for (int j = 0; j < 8; j++) {
      int XX = xx + dx[j], YY = yy + dy[j];
      if (!OK(XX, YY)) continue;
      if (getfa(Num(X, Y)) == getfa(Num(XX, YY))) return 0;
    }
  }
  return 1;
}
void merge(int x, int y) { fa[getfa(x)] = getfa(y); }
void Merge(int x, int y) {
  int xx = x, yy = y + c;
  for (int i = 0; i < 8; i++) {
    int X = x + dx[i], Y = y + dy[i];
    if (OK(X, Y)) merge(Num(x, y), Num(X, Y));
    int XX = xx + dx[i], YY = yy + dy[i];
    if (OK(XX, YY)) merge(Num(XX, YY), Num(xx, yy));
  }
  Del[x][y] = 1;
  Del[xx][yy] = 1;
}
void work() {
  int ans = 0;
  scanf("%d %d %d", &r, &c, &n);
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= 2 * c; j++) fa[Num(i, j)] = Num(i, j);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (Check(x, y)) Merge(x, y), ans++;
  }
  if (c == 1) ans = 0;
  printf("%d\n", ans);
  memset(Del, 0, sizeof Del);
}
int main() {
  work();
  return 0;
}
