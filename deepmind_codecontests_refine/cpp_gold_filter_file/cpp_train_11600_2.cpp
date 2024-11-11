#include <bits/stdc++.h>
char s[100012];
int m, l, r;
int x[100010], y[100010], z[100010];
using namespace std;
int main() {
  scanf("%s%*c", s);
  scanf("%d%*c", &m);
  x[0] = y[0] = z[0] = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    x[i + 1] = x[i];
    y[i + 1] = y[i];
    z[i + 1] = z[i];
    if (s[i] == 'x') {
      x[i + 1]++;
    } else if (s[i] == 'y') {
      y[i + 1]++;
    } else {
      z[i + 1]++;
    }
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d%*c", &l, &r);
    int maior, dx, dy, dz;
    dx = x[r] - x[l - 1];
    dy = y[r] - y[l - 1];
    dz = z[r] - z[l - 1];
    maior = max(max(dx, dy), dz);
    dx = maior - dx;
    dy = maior - dy;
    dz = maior - dz;
    if ((r - (l - 1)) < 3) {
      printf("YES\n");
    } else if (dx > 1 || dy > 1 || dz > 1) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
}
