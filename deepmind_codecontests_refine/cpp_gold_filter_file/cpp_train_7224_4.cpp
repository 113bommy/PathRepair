#include <bits/stdc++.h>
int h[1001], l[1001], n, m;
void ini() {
  int x, y;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    h[x] = l[y] = 1;
  }
}
void work() {
  int maxx = 0, maxy = 0;
  for (int i = 2; i < n; i++) {
    maxx += h[i];
    maxy += l[i];
  }
  int sol = 2 * (n - 2) - maxx - maxy;
  if (n % 2 && !h[n / 2 + 1] && !l[n / 2 + 1]) sol--;
  printf("%d\n", sol);
}
int main() {
  ini();
  work();
  return 0;
}
