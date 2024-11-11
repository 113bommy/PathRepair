#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(time(0));
const int N = 55;
int n, ans[N][N], cnt;
void wypisz() {
  printf("!\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d", ans[i][j]);
    printf("\n");
  }
  fflush(stdout);
}
bool pytaj(int x1, int y1, int x2, int y2) {
  printf("? %d %d %d %d\n", x1, y1, x2, y2);
  fflush(stdout);
  int ax = 0;
  scanf("%d", &ax);
  return ax;
}
void wypelnij(int x, int y) {
  for (int i = x + 2; i <= n; i += 2)
    if (pytaj(i - 2, y, i, y))
      ans[i][y] = ans[i - 2][y];
    else
      ans[i][y] = ans[i - 2][y] ^ 1;
  for (int i = y + 2; i <= n; i += 2)
    if (pytaj(x, i - 2, x, i))
      ans[x][i] = ans[x][i - 2];
    else
      ans[x][i] = ans[x][i - 2] ^ 1;
  if (x != n && (x != n - 1 || y != n - 1))
    if (pytaj(x, y, x + 1, y + 1))
      ans[x + 1][y + 1] = ans[x][y];
    else
      ans[x + 1][y + 1] = ans[x][y] ^ 1;
}
bool check(int x, int y, int x2, int y2) { return ans[x][y] == ans[x2][y2]; }
bool check1(int x, int y) {
  return check(x, y, x + 2, y + 1) &&
         (check(x + 1, y, x + 2, y) || check(x, y + 1, x + 1, y + 1));
}
bool check2(int x, int y) {
  return check(x, y, x + 1, y + 2) &&
         (check(x, y + 1, x, y + 2) || check(x + 1, y, x + 1, y + 1));
}
void odwrot() {
  for (int i = 1; i <= n; i++)
    for (int j = i % 2 + 1; j <= n; j += 2) ans[i][j] ^= 1;
}
int main() {
  scanf("%d", &n);
  ans[1][1] = 1;
  ans[2][1] = 1;
  for (int i = 1; i <= n; i++) wypelnij(i, i);
  for (int i = 1; i < n; i++) wypelnij(i + 1, i);
  for (int i = 2; i <= n; i += 2)
    if (pytaj(1, i, 3, i))
      ans[1][i] = ans[3][i];
    else
      ans[1][i] = ans[3][i] ^ 1;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      bool b1 = check1(1 + i, 1 + j);
      odwrot();
      bool b2 = check1(1 + i, 1 + j);
      if (b1 != b2) {
        if (pytaj(1 + i, 1 + j, 3 + i, 2 + j) == b1) odwrot();
        wypisz();
        return 0;
      }
      odwrot();
      b1 = check2(1 + i, 1 + j);
      odwrot();
      b2 = check2(1 + i, 1 + j);
      if (b1 != b2) {
        if (pytaj(1 + i, 1 + j, 2 + i, 3 + j) == b1) odwrot();
        wypisz();
        return 0;
      }
      odwrot();
      b1 = check1(1 + i, 2 + j);
      odwrot();
      b2 = check1(1 + i, 2 + j);
      if (b1 != b2) {
        if (pytaj(1 + i, 2 + j, 3 + i, 3 + j) == b1) odwrot();
        wypisz();
        return 0;
      }
      odwrot();
      b1 = check2(2 + i, 1 + j);
      odwrot();
      b2 = check2(2 + i, 1 + j);
      if (b1 != b2) {
        if (pytaj(2 + i, 1 + j, 3 + i, 3 + j) == b1) odwrot();
        wypisz();
        return 0;
      }
    }
  return 0;
}
