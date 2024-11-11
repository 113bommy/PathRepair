#include <bits/stdc++.h>
using namespace std;
int px[1010], py[1010];
int L, R, H;
int n;
long long det(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (long long)(x2 - x1) * (y3 - y1) - (long long)(x3 - x1) * (y2 - y1);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &px[i], &py[i]);
  L = px[0];
  R = px[1];
  H = py[0];
  if (L > R) swap(L, R);
  for (int i = 1; i < n; i++) {
    int x1 = px[i], x2 = px[(i + 1) % n], y1 = py[i], y2 = py[(i + 1) % n];
    if (det(x1, y1, x2, y2, L, H) > 0 && det(x1, y1, x2, y2, R, H) > 0) {
      printf("0\n");
      return 0;
    }
    if (y1 == y2) continue;
    if (det(x1, y1, x2, y2, L, H) <= 0 && det(x1, y1, x2, y2, R, H) <= 0)
      continue;
    double v = (double)(x2 - x1) * (H - y1) / (y2 - y1) + x1;
    if (det(x1, y1, x2, y2, L, H) > 0) {
      L = (int)v;
      if (det(x1, y1, x2, y2, L, H) > 0) L++;
    } else {
      R = (int)v;
      if (det(x1, y1, x2, y2, R + 1, H) <= 0) R++;
    }
  }
  printf("%d\n", R - L + 1);
}
