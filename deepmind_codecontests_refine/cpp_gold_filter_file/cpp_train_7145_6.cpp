#include <bits/stdc++.h>
using namespace std;
long long c[50], d[50];
int main() {
  int n, L;
  scanf("%d%d", &n, &L);
  int a[50];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &c[i]);
    if (i != 0)
      d[i] = min(c[i], 2 * d[i - 1]);
    else
      d[i] = c[i];
  }
  for (int i = n; i <= 30; i++) {
    d[i] = 2 * d[i - 1];
  }
  int cnt = 0;
  while (L != 0) {
    a[cnt++] = L % 2;
    L /= 2;
  }
  long long ans = 0;
  for (int i = 0; i <= 30; i++) {
    if (a[i] == 1)
      ans += d[i];
    else
      ans = min(d[i], ans);
  }
  printf("%I64d\n", ans);
  return 0;
}
