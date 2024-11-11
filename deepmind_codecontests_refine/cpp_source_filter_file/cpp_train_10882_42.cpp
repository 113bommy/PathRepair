#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, g[1000009];
  int ans[1000009], t = 1, tt = 1;
  bool f[1000009];
  memset(f, false, sizeof(f));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int o;
    scanf("%d", &o);
    g[tt++] = o;
  }
  sort(g, g + n);
  int sum = 0, ttt = 1;
  for (int i = 1;; i++) {
    if (g[ttt] == i && ttt < tt) {
      ttt++;
      continue;
    }
    sum += i;
    if (sum <= m) {
      ans[t] = i;
      t++;
    } else {
      break;
    }
  }
  printf("%d\n", t - 1);
  for (int i = 1; i < t; i++) printf("%d ", ans[i]);
  return 0;
}
