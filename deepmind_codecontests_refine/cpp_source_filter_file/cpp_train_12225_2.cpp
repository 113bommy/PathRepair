#include <bits/stdc++.h>
int m[100010] = {};
int ans[100010] = {};
int main() {
  int p, x, ansk = 0;
  int a = 0, b = 0, c = 0;
  int k;
  int min1 = 10;
  scanf("%d%d", &p, &x);
  for (int i = 1; i < 9; i++) {
    a = b = c = 0;
    b = i;
    k = 0;
    int s = p;
    while (s--) {
      m[s] = b;
      if (k > p) break;
      if (b * x >= 10)
        c = b * x / 10;
      else
        c = 0;
      b = (b * x) % 10 + a;
      if (b >= 10) {
        b %= 10;
        c++;
      }
      a = c;
      k++;
    }
    if (a != 0) continue;
    if (m[0] != 0 && b == i)
      if (m[0] < min1) {
        for (int j = 0; j < p; j++) ans[j] = m[j];
        ansk = k;
        min1 = m[0];
      }
  }
  if (ansk == 0)
    printf("Impossible\n");
  else {
    for (int i = 0; i < p; i++) {
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
