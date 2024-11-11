#include <bits/stdc++.h>
using namespace std;
int n, v[105], rm[105];
int main() {
  scanf("%d", &n);
  int ans1 = 0, ans2 = 0, m = 0, l;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &l);
    for (int j = 1; j <= l; j++) scanf("%d", &v[j]);
    for (int j = 1; j <= l / 2; j++) ans1 += v[j], ans2 += v[l - j];
    if (l % 2 == 1) rm[++m] = -v[(l + 1) / 2];
  }
  sort(rm + 1, rm + 1 + m);
  for (int i = 1; i <= m; i++)
    if (i & 1)
      ans1 -= rm[i];
    else
      ans2 -= rm[i];
  printf("%d %d\n", ans1, ans2);
  return 0;
}
