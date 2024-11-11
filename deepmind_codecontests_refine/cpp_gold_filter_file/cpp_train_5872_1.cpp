#include <bits/stdc++.h>
using namespace std;
int n, m;
char mp[200][200];
int main() {
  scanf("%d%d", &n, &m);
  if (n == 3) {
    printf(">vv\n");
    printf("^<.\n");
    printf("^.<\n");
    printf("1 3\n");
    return 0;
  }
  if (n == 5) {
    printf(">...v\n");
    printf("v.<..\n");
    printf("..^..\n");
    printf(">....\n");
    printf("..^.<\n");
    printf("1 1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) mp[i][j] = '.';
  for (int i = 1; i <= n; i++) mp[i][1] = '^';
  mp[1][1] = '>';
  for (int i = 1; i <= n; i++) mp[i][n] = 'v';
  mp[n][n] = '<';
  for (int i = 1; i <= n; i++) {
    if (i % 2) {
      for (int j = 2; j <= 34; j++) mp[i][j] = '>';
      for (int j = 36; j <= 99; j += 2) mp[i][j] = '>';
    } else {
      for (int j = 100; j >= 68; j--) mp[i][j] = '<';
      for (int j = 66; j >= 2; j -= 2) mp[i][j] = '<';
      if (i < 100) mp[i][2] = 'v';
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      printf("%c", mp[i][j]);
      if (j == n) printf("\n");
    }
  printf("%d %d\n", 1, 1);
  return 0;
}
