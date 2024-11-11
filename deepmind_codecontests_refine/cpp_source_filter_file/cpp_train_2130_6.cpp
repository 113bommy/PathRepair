#include <bits/stdc++.h>
using namespace std;
int a[8][3];
long long dist(int x, int y) {
  return 1LL * (a[x][0] - a[y][0]) * (a[x][0] - a[y][0]) +
         (a[x][1] - a[y][1]) * (a[x][1] - a[y][1]) +
         (a[x][2] - a[y][2]) * (a[x][2] - a[y][2]);
}
void check(void) {
  long long d[8], dd[8];
  for (int i = 1; i < 8; ++i) d[i] = dist(0, i);
  long long mn = d[1];
  for (int i = 2; i < 8; ++i)
    if (mn > d[i]) mn = d[i];
  int k1 = 0, k2 = 0, k3 = 0;
  for (int i = 1; i < 8; ++i) {
    if (d[i] == mn) ++k1;
    if (d[i] == 2 * mn) ++k2;
    if (d[i] == 3 * mn) ++k3;
  }
  if (k1 == 3 && k2 == 3 && k3 == 1) {
    printf("YES\n");
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 3; ++j) printf("%d ", a[i][j]);
      printf("\n");
    }
    exit(0);
  }
}
void rec(int x) {
  int fl = 0;
  if (x == 8) {
    check();
    return;
  }
  int b[3];
  b[0] = a[x][0];
  b[1] = a[x][1];
  b[2] = a[x][2];
  a[x][0] = b[0];
  a[x][1] = b[1];
  a[x][2] = b[2];
  fl = 0;
  for (int i = 0; i < x; ++i)
    if (a[i][0] == a[x][0])
      if (a[i][1] == a[x][1])
        if (a[i][2] == a[x][2]) fl = 1;
  if (fl == 0) rec(x + 1);
  a[x][0] = b[0];
  a[x][1] = b[2];
  a[x][2] = b[1];
  fl = 0;
  for (int i = 0; i < x; ++i)
    if (a[i][0] == a[x][0])
      if (a[i][1] == a[x][1])
        if (a[i][2] == a[x][2]) fl = 1;
  if (fl == 0) rec(x + 1);
  a[x][0] = b[1];
  a[x][1] = b[0];
  a[x][2] = b[2];
  fl = 0;
  for (int i = 0; i < x; ++i)
    if (a[i][0] == a[x][0])
      if (a[i][1] == a[x][1])
        if (a[i][2] == a[x][2]) fl = 1;
  if (fl == 0) rec(x + 1);
  a[x][0] = b[1];
  a[x][1] = b[2];
  a[x][2] = b[0];
  fl = 0;
  for (int i = 0; i < x; ++i)
    if (a[i][0] == a[x][0])
      if (a[i][1] == a[x][1])
        if (a[i][2] == a[x][2]) fl = 1;
  if (fl == 0) rec(x + 1);
  a[x][0] = b[2];
  a[x][1] = b[0];
  a[x][2] = b[1];
  fl = 0;
  for (int i = 0; i < x; ++i)
    if (a[i][0] == a[x][0])
      if (a[i][1] == a[x][1])
        if (a[i][2] == a[x][2]) fl = 1;
  if (fl == 0) rec(x + 1);
  a[x][0] = b[2];
  a[x][1] = b[1];
  a[x][2] = b[0];
  fl = 0;
  for (int i = 0; i < x; ++i)
    if (a[i][0] == a[x][0])
      if (a[i][1] == a[x][1])
        if (a[i][2] == a[x][2]) fl = 1;
  if (fl == 0) rec(x + 1);
}
int main() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 3; ++j) scanf("%d", &a[i][j]);
  }
  rec(0);
  printf("NO");
  return 0;
}
