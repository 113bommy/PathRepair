#include <bits/stdc++.h>
int main() {
  int arr[555][555];
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  int w, r, m;
  for (w = 0; w < c; w++) {
    scanf("%d%d", &r, &m);
    arr[r - 1][m - 1] = 1;
  }
  int x, y, z, e, f, g, h, i;
  int cnt = 0, sum = 0;
  for (x = 0; x < a; x++) {
    for (y = 0; y < b; y++) {
      for (z = x; z < a; z++) {
        for (e = y; e < b; e++) {
          for (f = x; f <= z; f++) {
            for (g = y; g <= e; g++) {
              if (arr[f][g] == 1) sum++;
            }
          }
          if (sum >= d) cnt++;
          sum = 0;
        }
      }
    }
  }
  printf("%d", cnt);
}
