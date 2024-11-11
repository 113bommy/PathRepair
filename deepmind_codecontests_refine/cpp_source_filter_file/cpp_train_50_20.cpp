#include <bits/stdc++.h>
const int MAXN = 105;
int a[MAXN];
int main() {
  memset(a, 0, sizeof(a));
  int n, m, x, y;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    for (int j = 0; j < x; j++) {
      scanf("%d", &y);
      a[y] = 1;
    }
  }
  bool isOk = false;
  for (int i = 1; i <= m; i++) {
    if (!a[i]) {
      isOk = true;
      break;
    }
  }
  if (isOk)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
