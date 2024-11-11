#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline char smax(A &a, const B &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename A, typename B>
inline char smin(A &a, const B &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename I>
inline void read(I &x) {
  int f = 0, c;
  while (!isdigit(c = getchar())) c == '-' ? f = 1 : 0;
  x = c & 15;
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
  f ? x = -x : 0;
}
const int N = 60;
int n;
int a[N][N];
inline bool ask(int x1, int y1, int x2, int y2) {
  printf("? %d %d %d %d\n", x1, y1, x2, y2);
  fflush(stdout);
  int t;
  scanf("%d", &t);
  return t;
}
inline int get0(int x, int y) {
  if (x > n || y > n - 3) return -1;
  return a[x][y] ^ a[x][y + 1] ^ a[x][y + 2] ^ a[x][y + 3];
}
inline int get1(int x, int y) {
  if (x > n - 1 || y > n - 2) return -1;
  return a[x][y] ^ a[x][y + 1] ^ a[x][y + 2] ^ a[x + 1][y + 2];
}
inline int get2(int x, int y) {
  if (x > n - 1 || y > n - 2) return -1;
  return a[x][y] ^ a[x][y + 1] ^ a[x + 1][y + 1] ^ a[x + 1][y + 2];
}
inline int get3(int x, int y) {
  if (x > n - 2 || y > n - 1) return -1;
  return a[x][y] ^ a[x][y + 1] ^ a[x + 1][y + 1] ^ a[x + 2][y + 1];
}
inline int get4(int x, int y) {
  if (x > n - 1 || y > n - 2) return -1;
  return a[x][y] ^ a[x + 1][y] ^ a[x + 1][y + 1] ^ a[x + 1][y + 2];
}
inline int get5(int x, int y) {
  if (x > n - 2 || y > n - 1) return -1;
  return a[x][y] ^ a[x + 1][y] ^ a[x + 1][y + 1] ^ a[x + 2][y + 1];
}
inline int get6(int x, int y) {
  if (x > n - 2 || y > n - 1) return -1;
  return a[x][y] ^ a[x + 1][y] ^ a[x + 2][y] ^ a[x + 2][y + 1];
}
inline int get7(int x, int y) {
  if (x > n - 3 || y > n) return -1;
  return a[x][y] ^ a[x + 1][y] ^ a[x + 2][y] ^ a[x + 3][y];
}
inline void work() {
  a[1][1] = 1, a[n][n] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      if ((i + j) & 1) continue;
      if (i == 1 && j == 1) continue;
      if (i == n && j == n) continue;
      if (i != 1 && j != 1)
        a[i][j] = a[i - 1][j - 1] ^ ask(i - 1, j - 1, i, j) ^ 1;
      else if (i == 1)
        a[i][j] = a[i][j - 2] ^ ask(i, j - 2, i, j) ^ 1;
      else
        a[i][j] = a[i - 2][j] ^ ask(i - 2, j, i, j) ^ 1;
    }
  a[1][2] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 2; j <= n; ++j)
      if ((i + j) & 1) {
        if (i == 1 && j == 2) continue;
        if (i == 1)
          a[i][j] = a[i][j - 2] ^ ask(i, j - 2, i, j) ^ 1;
        else
          a[i][j] = a[i - 1][j - 1] ^ ask(i - 1, j - 1, i, j) ^ 1;
      }
    if (!(i & 1)) a[i][1] = a[i][3] ^ ask(i, 1, i, 3) ^ 1;
  }
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0, flag = 0;
  for (int i = 1; i <= n && !x1; ++i)
    for (int j = 1; j <= n && !x1; ++j) {
      if (!get0(i, j))
        x1 = i, y1 = j, x2 = i, y2 = j + 3;
      else if (!get1(i, j))
        x1 = i, y1 = j, x2 = i + 1, y2 = j + 2;
      else if (!get2(i, j))
        x1 = i, y1 = j, x2 = i + 1, y2 = j + 2;
      else if (!get3(i, j))
        x1 = i, y1 = j, x2 = i + 2, y2 = j + 1;
      else if (!get4(i, j))
        x1 = i, y1 = j, x2 = i + 1, y2 = j + 2;
      else if (!get5(i, j))
        x1 = i, y1 = j, x2 = i + 2, y2 = j + 1;
      else if (!get6(i, j))
        x1 = i, y1 = j, x2 = i + 2, y2 = j + 1;
      else if (!get7(i, j))
        x1 = i, y1 = j, x2 = i + 3, y2 = j;
    }
  flag = ask(x1, y1, x2, y2) != (a[x1][y1] == a[x2][y2]);
  printf("!\n");
  for (int i = 1; i <= n; ++i, puts(""))
    for (int j = 1; j <= n; ++j)
      if ((i + j) & 1)
        printf("%d ", a[i][j] ^ flag);
      else
        printf("%d ", a[i][j]);
}
inline void init() {
  scanf("%d", &n);
  assert(n & 1);
}
int main() {
  init();
  work();
  fclose(stdin), fclose(stdout);
  return 0;
}
