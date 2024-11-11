#include <bits/stdc++.h>
int n, m, k;
int kex[101][101] = {0};
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int i;
  int x, y;
  int have = 0;
  for (i = 0; i < k; i++) {
    scanf("%d%d", &x, &y);
    if (x <= 2 || x >= n - 1 || y <= 2 || y >= m - 1) have = 1;
  }
  if (have)
    printf("YES");
  else
    printf("NO");
  return 0;
}
