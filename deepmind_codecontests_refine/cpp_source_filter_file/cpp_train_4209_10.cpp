#include <bits/stdc++.h>
int n, k, i, H[105][105], a, s = 1;
int top;
int main() {
  scanf("%d %d", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a);
    H[a][i % k]++;
  }
  for (i = 1; i <= k; i++) top += (H[1][i] < H[2][i] ? H[1][i] : H[2][i]);
  printf("%d\n", top);
  return 0;
}
