#include <bits/stdc++.h>
using namespace std;
long long int res, n, m, x, y, dx = 1, dy = 1, X, Y, Dx, Dy, nx, ny,
                               INF = 10000000000000;
char in[5];
set<pair<long long int, long long int> > s;
void Change_Direction() {
  if (x == n)
    dx = -1;
  else if (x == 1)
    dx = 1;
  if (y == m)
    dy = -1;
  else if (y == 1)
    dy = 1;
}
int main() {
  scanf("%I64d %I64d %I64d %I64d", &n, &m, &X, &Y);
  scanf("%s", in);
  x = X, y = Y;
  if (in[0] == 'U') dx = -1;
  if (in[1] == 'L') dy = -1;
  Change_Direction();
  Dx = dx, Dy = dy;
  for (;;) {
    s.insert(make_pair(x, y));
    long long int moves = INF;
    if (dx == 1)
      moves = min(moves, n - x);
    else
      moves = min(moves, x - 1);
    if (dy == 1)
      moves = min(moves, m - y);
    else
      moves = min(moves, y - 1);
    x += (moves * dx), y += (moves * dy);
    Change_Direction();
    if (s.size() == n + m - 2) break;
    if (x == X && y == Y && dx == Dx && dy == Dy) break;
    res += moves;
  }
  if (s.size() == n + m - 2)
    printf("%I64d", res + 1);
  else
    printf("-1");
  return 0;
}
