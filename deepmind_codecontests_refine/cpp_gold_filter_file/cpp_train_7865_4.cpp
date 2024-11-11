#include <bits/stdc++.h>
char w[50000010], np[50000010];
int main(void) {
  int n, x;
  scanf("%d%d", &n, &x);
  while (n--) {
    int v;
    scanf("%d", &v);
    if (v < 50000010) {
      w[v] = 1;
    }
  }
  int res = 0;
  for (int i = 2; i < x; i++) {
    if (!np[i]) {
      if (!w[i]) {
        res = -1;
        break;
      }
      res++;
      for (long long j = (long long)i * i; j <= x && j < 50000010; j += i) {
        np[j] = 1;
      }
    }
  }
  if (w[1] && res != 0) {
    res = 1;
  }
  printf("%d", res);
  return 0;
}
