#include <bits/stdc++.h>
int a[1000000];
int aa[1000000];
int g[1000000];
int gg[1000000];
char ans[1000001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i], &g[i]);
    if (i == 0) {
      aa[i] = a[i];
      gg[i] = g[i];
    } else {
      aa[i] = aa[i - 1] + a[i];
      gg[i] = gg[i - 1] + g[i];
    }
  }
  int tot = 0;
  int i;
  for (i = 0; i < n; ++i) {
    if (tot + a[i] - (gg[n - 1] - gg[i]) <= 500) {
      tot += a[i];
      ans[i] = 'A';
    } else if (tot - g[i] + (aa[n - 1] - aa[i]) >= -500) {
      tot -= g[i];
      ans[i] = 'G';
    } else {
      break;
    }
  }
  ans[n] = '\0';
  if (i != n)
    printf("-1\n");
  else
    printf("%s\n", ans);
  return 0;
}
