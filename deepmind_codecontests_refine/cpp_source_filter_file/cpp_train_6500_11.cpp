#include <bits/stdc++.h>
using namespace std;
long long s1[10020], s2[10020], a[10020];
int x, y, z, n, m;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    s1[i] = s1[i - 1] + a[i];
  }
  scanf("%d", &m);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) s2[i] = s2[i - 1] + a[i];
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    if (x == 1)
      printf("%I64d\n", s1[y] - s1[x - 1]);
    else
      printf("%I64d\n", s2[y] - s2[x - 1]);
  }
  return 0;
}
