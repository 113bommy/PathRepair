#include <bits/stdc++.h>
int n, m, i, j, pr[100010], t, x, y, rt;
int fs(int k) {
  if (k != pr[k]) pr[k] = fs(pr[k]);
  return pr[k];
}
int main(int argc, char* const argv[]) {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) pr[i] = i;
  for (i = 1, rt = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    if (fs(x) == fs(y)) rt = (rt + rt) % 1000000009;
    pr[fs(x)] = pr[fs(y)];
    printf("%d\n", (rt - 1));
  }
  return 0;
}
