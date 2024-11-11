#include <bits/stdc++.h>
int num[1005][1005];
char c;
int a, b;
int n, m, q, aux;
int swapF[1005];
int swapC[1005];
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf(" %d", &num[i][j]);
  for (int i = 1; i <= n; i++) swapF[i] = i;
  for (int i = 1; i <= m; i++) swapC[i] = i;
  while (q--) {
    scanf(" %c %d %d", &c, &a, &b);
    if (c == 'c') {
      aux = swapF[a];
      swapF[a] = swapF[b];
      swapF[b] = aux;
    } else if (c == 'r') {
      aux = swapC[a];
      swapC[a] = swapC[b];
      swapC[b] = aux;
    } else
      printf("%d\n", num[swapF[a]][swapC[b]]);
  }
  return 0;
}
