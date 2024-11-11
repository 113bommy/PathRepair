#include <bits/stdc++.h>
using namespace std;
int _3[4][4], _6[7][7];
int e[1010][1010], n, now;
void extend() {
  e[now + 1][now + 2] = 1;
  for (int i = 1; i <= now; i++) e[now + 2][i] = 1;
  for (int i = 1; i <= now; i++) e[i][now + 1] = 1;
  now += 2;
}
void build() {
  _3[1][2] = _3[2][3] = _3[3][1] = 1;
  _6[1][2] = _6[1][3] = _6[1][4] = _6[2][3] = _6[2][4] = _6[2][5] = 1;
  _6[3][4] = _6[3][5] = _6[3][6] = _6[4][5] = _6[4][6] = _6[5][1] = _6[5][6] =
      _6[6][1] = _6[6][2] = 1;
}
int main() {
  scanf("%d", &n);
  if (n == 4) return printf("1"), 0;
  build();
  if (n & 1) {
    now = 3;
    for (int i = 1; i <= 3; i++)
      for (int j = 1; j <= 3; j++) e[i][j] = _3[i][j];
    while (now < n) extend();
  } else {
    now = 6;
    for (int i = 1; i <= 6; i++)
      for (int j = 1; j <= 6; j++) e[i][j] = _6[i][j];
    while (now < n) extend();
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d ", e[i][j]);
    puts("");
  }
  return 0;
}
