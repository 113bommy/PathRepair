#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} maps[1005];
int main() {
  int n;
  scanf("%d", &n);
  int xx, yy;
  int num = 0, R = 0, C = 0;
  for (int i = 1; i <= n + 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (i == 1) {
      xx = x, yy = y;
      continue;
    }
    if (xx == x) {
      if (yy < y) {
        if (R == 1) num++;
        C = 0;
      } else {
        if (R == 0) num++;
        C = 1;
      }
      R = 0;
    } else {
      if (xx < x) {
        if (C == 1) num++;
        R = 1;
      } else {
        if (C == 0) num++;
        R = 0;
      }
      C = 0;
    }
    xx = x, yy = y;
  }
  printf("%d\n", num);
}
