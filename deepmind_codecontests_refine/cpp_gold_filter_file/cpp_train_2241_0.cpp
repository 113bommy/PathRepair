#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, n;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
  int i, x[28];
  for (i = 1; i <= n; i++) scanf("%d", &x[i]);
  char h[110][110];
  memset(h, 0, sizeof(h));
  for (i = 1; i <= b || i <= d; i++)
    for (int j = 1; j <= a + c; j++) h[i][j] = '.';
  int j = 1;
  int v = d, g, nap;
  if (d % 2) {
    g = a + c;
    nap = -1;
  } else {
    g = a + 1;
    nap = 1;
  }
  while (x[n] != 0) {
    if (x[j] == 0) j++;
    h[v][g] = j - 1 + 'a';
    x[j]--;
    if (v != 1 || g != a + 1) {
      if (g >= a + 1) {
        if (nap == 1) {
          g++;
          if (g > a + c) {
            g = a + c;
            v--;
            nap = -1;
          }
        } else {
          g--;
          if (g == a) {
            g = a + 1;
            v--;
            nap = 1;
          }
        }
      } else {
        if (nap == 1) {
          g++;
          if (g == a + 1) {
            g = a;
            v++;
            nap = -1;
          }
        } else {
          g--;
          if (g == 0) {
            g = 1;
            v++;
            nap = 1;
          }
        }
      }
    } else {
      v = 1;
      g = a;
    }
  }
  printf("YES\n");
  for (i = 1; i <= b || i <= d; i++) {
    for (j = 1; j <= a + c; j++) printf("%c", h[i][j]);
    printf("\n");
  }
}
