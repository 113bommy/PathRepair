#include <bits/stdc++.h>
using namespace std;
int n, p, q, x, y, now, dir;
char typ[10];
bool ask(int x, int y) {
  printf("%d %d\n", x, y);
  fflush(stdout);
  scanf("%s", typ);
  return typ[0] == 'b';
}
int main() {
  scanf("%d", &n);
  p = ask(0, 0);
  now = 1 << 28;
  x = now, y = now;
  dir = 1;
  for (int i = (1); i <= (n - 1); i++) {
    q = ask(x, y);
    now >>= 1;
    if (p == q)
      x += dir * now, y += dir * now;
    else
      x -= dir * now, y -= dir * now, dir = -dir;
    p = q;
  }
  printf("%d %d %d %d\n", x + dir, y, x, y + dir);
  fflush(stdout);
  return 0;
}
