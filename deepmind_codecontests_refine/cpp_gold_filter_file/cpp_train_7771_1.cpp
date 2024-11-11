#include <bits/stdc++.h>
int main() {
  int n, *toado, x, y, t = 0;
  scanf("%d", &n);
  toado = (int*)malloc(n * sizeof(int));
  for (int i = 1; i <= n; i++) toado[i] = 0;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    toado[x]++;
    toado[y]++;
  }
  for (int i = 1; i <= n; i++)
    if (toado[i] == 1) t++;
  printf("\n%d", t);
  return 0;
}
