#include <bits/stdc++.h>
const int MAXN = 1e3 + 7;
const int HA = 1e9 + 7;
int n, p[MAXN], f[MAXN];
int main(int argc, char *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", p + i);
  }
  f[1] = 1;
  for (int i = 2; i <= n + 1; i++) {
    f[i] = (2LL * f[i - 1] % HA - f[p[i - 1]] + 2LL) % HA;
  }
  printf("%d", (f[n + 1] - 1 + HA) % HA);
  return 0;
}
