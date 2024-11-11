#include <bits/stdc++.h>
int main() {
  long n, i, j, vis[100010] = {0};
  long long s = 0, k;
  char a[2][100010];
  scanf("%s", a[1]);
  n = strlen(a[1]);
  for (i = 0; i < n; i++) {
    k = 0;
    if (vis[i] == 0) {
      for (j = i; j < n; j++)
        if (a[1][j] == a[1][i]) {
          k++;
          vis[j] = 1;
        }
    }
    s += k * k;
  }
  printf("%lld\n", s);
  return 0;
}
