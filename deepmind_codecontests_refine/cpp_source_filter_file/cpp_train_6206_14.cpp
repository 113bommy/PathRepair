#include <bits/stdc++.h>
using namespace std;
int g[50][50];
int b[50], h[50];
int i, j, k, m, n, s, t, x, y;
int main() {
  srand((int)time(0));
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) scanf("%d", &g[i][j]);
  for (i = 1; i <= n; i++) h[i] = i;
  for (k = 1; k <= 1000; k++) {
    for (i = 1; i <= n; i++) {
      x = rand() % n + 1, y = rand() % n + 1;
      swap(h[x], h[y]);
    }
    memset(b, 0, sizeof(b)), t = 0;
    for (i = 1; i <= n; i++) {
      b[h[i]] = 1, t++;
      for (j = 1; (b[h[i]]) && (j < i); j++)
        if ((b[h[j]]) && (!g[h[i]][h[j]])) b[h[i]] = 0, t--;
    }
    s = max(s, t);
  }
  printf("%.12lf", 1.0 * m * m * (s * (s - 1) / 2) / (s * s));
  return 0;
}
