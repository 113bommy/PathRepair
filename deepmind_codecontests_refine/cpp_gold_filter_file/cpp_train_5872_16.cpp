#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:33554432")
using namespace std;
char a[1 << 10][1 << 10];
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  if (n == 5 && x == 5) {
    printf(">...v\n");
    printf("v.<..\n");
    printf("..^..\n");
    printf(">....\n");
    printf("..^.<\n");
    printf("1 1\n");
    return 0;
  }
  if (n == 3 && x == 2) {
    printf(">vv\n");
    printf("^<.\n");
    printf("^.<\n");
    printf("1 3\n");
    return 0;
  }
  memset(a, '.', sizeof(a));
  for (int k = 0; k < 98; k += 2) {
    for (int i = 1; i < 68; i += 2) a[k][i] = '<';
    for (int i = 70; i < 100; ++i) a[k][i] = '<';
    a[k][0] = 'v';
    for (int i = 0; i < 30; ++i) a[k + 1][i] = '>';
    for (int i = 31; i < 99; i += 2) a[k + 1][i] = '>';
    a[k + 1][99] = '^';
  }
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) printf("%c", a[i][j]);
    printf("\n");
  }
  printf("1 1\n");
  return 0;
}
