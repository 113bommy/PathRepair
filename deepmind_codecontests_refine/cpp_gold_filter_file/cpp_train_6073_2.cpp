#include <bits/stdc++.h>
bool flag[1000000];
int ans[12005], ed;
int main() {
  int i, j, t, k;
  memset(flag, true, sizeof(flag));
  flag[0] = flag[1] = 0;
  ed = 0;
  for (i = 2; i < 1000000; ++i) {
    if (flag[i]) {
      for (j = 2; j * i < 1000000; ++j) {
        flag[i * j] = false;
      }
      if (i > 10) {
        k = i;
        t = 0;
        while (k) {
          t *= 10;
          t += k % 10;
          k /= 10;
        }
        if (t == i) continue;
        for (k = 2; k * k <= t; ++k) {
          if (t % k == 0) break;
        }
        if (k * k > t) ans[ed++] = i;
        if (ed > 11183) break;
      }
    }
  }
  scanf("%d", &i);
  printf("%d\n", ans[i - 1]);
}
