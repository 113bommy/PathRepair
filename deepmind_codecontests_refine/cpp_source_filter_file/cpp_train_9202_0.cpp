#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:33554432")
using namespace std;
bool pl[3][10010];
char c;
unsigned int res[8][10010], n, X, Y;
void calc(int pos, int bit, int mask, int next_mask) {
  if (bit >= 3) {
    res[next_mask][pos + 1] += res[mask][pos];
    res[next_mask][pos + 1] %= 1000000007;
    return;
  }
  int my_mask = 1 << bit;
  if (pl[bit][pos] == 1 || (mask & my_mask)) {
    calc(pos, bit + 1, mask, next_mask);
    return;
  }
  if (pl[bit][pos + 1] == 1) {
    if (bit + 1 < 3 && !(mask & (my_mask << 1)) && pl[bit + 1][pos] == 0)
      calc(pos, bit + 2, mask, next_mask);
    return;
  }
  calc(pos, bit + 1, mask, next_mask | my_mask);
  if (bit + 1 < 3 && !(mask & (my_mask << 1)) && pl[bit + 1][pos] == 0)
    calc(pos, bit + 2, mask, next_mask);
  return;
}
void work() {
  for (int i = 0; i < 8; i++) memset(res[i], 0, (n << 2) + 4);
  res[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < 8; mask++) {
      calc(i, 0, mask, 0);
    }
  }
  return;
}
int main() {
  scanf("%d%c", &n, &c);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%c", &c);
      if (c == 'X')
        pl[i][j] = 1;
      else
        pl[i][j] = 0;
      if (c == 'O') X = i, Y = j;
    }
    pl[i][n] = 0;
    scanf("%c", &c);
  }
  long long ans = 0;
  bool uord = 0, left = 0;
  if (X == 0 && pl[1][Y] == 0 && pl[2][Y] == 0)
    pl[0][Y] = pl[1][Y] = pl[2][Y] = 1, work(), ans += res[0][n],
    ans %= 1000000007, pl[0][Y] = pl[1][Y] = pl[2][Y] = 0, uord = 1;
  if (X == 2 && pl[1][Y] == 0 && pl[0][Y] == 0)
    pl[0][Y] = pl[1][Y] = pl[2][Y] = 1, work(), ans += res[0][n],
    ans %= 1000000007, pl[0][Y] = pl[1][Y] = pl[2][Y] = 0, uord = 1;
  if (Y >= 2 && pl[X][Y - 1] == 0 && pl[X][Y - 2] == 0) {
    pl[X][Y] = pl[X][Y - 1] = pl[X][Y - 2] = 1, work(), ans += res[0][n],
    ans %= 1000000007, pl[X][Y] = pl[X][Y - 1] = pl[X][Y - 2] = 0, left = 1;
    if (uord == 1) {
      pl[0][Y] = pl[1][Y] = pl[2][Y] = pl[X][Y] = pl[X][Y - 1] = pl[X][Y - 2] =
          1;
      work();
      ans -= res[0][n];
      ans %= 1000000007;
      pl[0][Y] = pl[1][Y] = pl[2][Y] = pl[X][Y] = pl[X][Y - 1] = pl[X][Y - 2] =
          0;
    }
  }
  if (Y + 2 < n && pl[X][Y + 1] == 0 && pl[X][Y + 2] == 0) {
    pl[X][Y] = pl[X][Y + 1] = pl[X][Y + 2] = 1, work(), ans += res[0][n],
    ans %= 1000000007, pl[X][Y] = pl[X][Y + 1] = pl[X][Y + 2] = 0;
    if (uord == 1) {
      pl[0][Y] = pl[1][Y] = pl[2][Y] = pl[X][Y] = pl[X][Y + 1] = pl[X][Y + 2] =
          1;
      work();
      ans -= res[0][n];
      ans %= 1000000007;
      pl[0][Y] = pl[1][Y] = pl[2][Y] = pl[X][Y] = pl[X][Y + 1] = pl[X][Y + 2] =
          0;
    }
    if (left == 1) {
      pl[X][Y] = pl[X][Y - 1] = pl[X][Y - 2] = pl[X][Y] = pl[X][Y + 1] =
          pl[X][Y + 2] = 1;
      work();
      ans -= res[0][n];
      ans %= 1000000007;
      pl[X][Y] = pl[X][Y - 1] = pl[X][Y - 2] = pl[X][Y] = pl[X][Y + 1] =
          pl[X][Y + 2] = 0;
    }
    if (left && uord) {
      pl[0][Y] = pl[1][Y] = pl[2][Y] = pl[X][Y] = pl[X][Y - 1] = pl[X][Y - 2] =
          pl[X][Y] = pl[X][Y + 1] = pl[X][Y + 2] = 1;
      work();
      ans += res[0][n];
      ans %= 1000000007;
      pl[0][Y] = pl[1][Y] = pl[2][Y] = pl[X][Y] = pl[X][Y - 1] = pl[X][Y - 2] =
          pl[X][Y] = pl[X][Y + 1] = pl[X][Y + 2] = 0;
    }
  }
  if (ans >= 0)
    printf("%d\n", ans);
  else
    printf("%d\n", 1000000007 - ans);
  return 0;
}
