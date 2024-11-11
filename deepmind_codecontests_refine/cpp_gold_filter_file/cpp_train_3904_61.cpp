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
    if (x <= 5 || x >= n - 4 || y <= 5 || y >= m - 4) have = 1;
  }
  if (have)
    printf("YES");
  else
    printf("NO");
  return 0;
}
