#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, minx, miny, maxx, maxy;
  scanf("%d %d", &a, &b);
  char test[55][55];
  for (int i = 0; i < (int)(a); i++) scanf("%s", &test[i]);
  minx = a, miny = b, maxx = -1, maxy = -1;
  for (int i = 0; i < (int)(a); i++) {
    for (int j = 0; j < (int)(b); j++) {
      if (test[i][j] == '*') {
        minx = min(minx, i);
        miny = min(miny, j);
        maxx = max(maxx, i);
        maxy = max(maxy, j);
      }
    }
  }
  for (int i = minx; i <= maxx; i++) {
    for (int j = miny; j <= maxy; j++) {
      cout << test[i][j];
    }
    printf("\n");
  }
  return 0;
}
