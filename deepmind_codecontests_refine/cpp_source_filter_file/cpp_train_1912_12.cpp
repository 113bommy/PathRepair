#include <bits/stdc++.h>
using namespace std;
int a, b, mx, mn, z;
int d[109][10009];
char c[109][10009];
int main() {
  scanf("%d %d", &a, &b);
  for (int i = 0; i < a; i++) scanf("%s", c[i]);
  for (int i = 0; i < a; i++)
    for (int j = 0; j < b; j++) c[i][j + b] = c[i][j];
  mn = 1000000;
  for (int i = 0; i < a; i++)
    for (int j = 0; j < b * 2; j++) d[i][j] = 1000000;
  for (int i = 0; i < a; i++) {
    z = 0;
    mx = 1000000;
    for (int j = 0; j < b * 2; j++) {
      if (c[i][j] == '1') {
        mx = 0;
        z = 1;
      } else
        mx++;
      d[i][j] = mx;
    }
    if (z == 0) {
      printf("-1");
      return 0;
    }
  }
  for (int i = 0; i < a; i++) {
    mx = 1000000;
    for (int j = b * 2 - 1; j >= 0; j--) {
      if (c[i][j] == '1')
        mx = 0;
      else
        mx++;
      d[i][j] = min(d[i][j], mx);
    }
  }
  for (int j = 0; j < b * 2; j++) {
    mx = 0;
    for (int i = 0; i < a; i++) mx += d[i][j];
    if (mn > mx) mn = mx;
  }
  printf("%d", mn);
  getchar();
  getchar();
}
