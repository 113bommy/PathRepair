#include <bits/stdc++.h>
using namespace std;
int cnt, c[7][7];
char p[10005];
int q[10005];
void init() {
  char st[7];
  for (int i = 0; i < 6; ++i) {
    scanf("%s", st);
    for (int j = 0; j < 6; ++j) c[i][j] = st[j] - (st[j] <= '9' ? 48 : 55);
  }
}
void write() {
  for (int i = 0; i < 6; puts(""), ++i)
    for (int j = 0; j < 6; ++j)
      printf("%c", c[i][j] + (c[i][j] < 10 ? 48 : 55));
  puts("");
}
void U(int x) {
  char t = c[0][x];
  for (int i = 0; i < 5; ++i) c[i][x] = c[i + 1][x];
  c[5][x] = t;
  p[++cnt] = 'U';
  q[cnt] = x;
}
void D(int x) {
  char t = c[5][x];
  for (int i = 5; i; --i) c[i][x] = c[i - 1][x];
  c[0][x] = t;
  p[++cnt] = 'D';
  q[cnt] = x;
}
void L(int x) {
  char t = c[x][0];
  for (int i = 0; i < 5; ++i) c[x][i] = c[x][i + 1];
  c[x][5] = t;
  p[++cnt] = 'L';
  q[cnt] = x;
}
void R(int x) {
  char t = c[x][5];
  for (int i = 5; i; --i) c[x][i] = c[x][i - 1];
  c[x][0] = t;
  p[++cnt] = 'L';
  q[cnt] = x;
}
void find(int &x, int &y, int z) {
  for (x = 0; x < 6; ++x)
    for (y = 0; y < 6; ++y)
      if (c[x][y] == z) return;
}
void work1() {
  for (int i = 5; i; --i)
    for (int j = 5; j; --j) {
      int k, l;
      find(k, l, i * 6 + j);
      if (k == i && l == j) continue;
      if (k != i) {
        for (; l; --l) L(k);
        for (; k < i; ++k) D(0);
        for (; k > i; --k) U(0);
      }
      D(j);
      D(l);
      for (int m = 0; m < 6; ++m) {
        if ((j + m) % 6 == l) U(l);
        if ((l + m) % 6 == j) U(j);
        R(i);
      }
    }
}
void work2() {
  int i, j;
  for (j = 5; j > 1; --j) {
    int k, l;
    find(k, l, j);
    if (k == 0 && l == j) continue;
    for (int m = 0; m < 6; ++m) {
      if (k == 0) {
        if (l == m) U(0);
        if (j == m) D(0);
      } else if (j == m)
        for (; k; --k) U(0);
      L(0);
    }
  }
  for (i = 5; i; --i) {
    int k, l;
    find(k, l, i * 6);
    if (k == i && l == 0) continue;
    for (int m = 0; m < 6; ++m) {
      if (l == 0) {
        if (k == m) L(0);
        if (i == m) R(0);
      } else if (i == m)
        L(0), D(0), R(0), U(0);
      U(0);
    }
  }
}
void work3() {
  if (c[0][0]) {
    U(0);
    L(0);
    U(0);
    R(0);
    U(0);
    L(0);
    U(0);
    R(0);
    U(0);
    L(0);
    U(0);
    R(0);
    U(0);
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; ++i) printf("%c%d\n", p[i], q[i] + 1);
}
int main() {
  init();
  work1();
  work2();
  work3();
  return 0;
}
