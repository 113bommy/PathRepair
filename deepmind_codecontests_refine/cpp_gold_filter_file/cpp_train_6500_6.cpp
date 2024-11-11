#include <bits/stdc++.h>
using namespace std;
long long s1[100020], s2[100020], a[100020];
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
      printf("%I64d\n", s1[z] - s1[y - 1]);
    else
      printf("%I64d\n", s2[z] - s2[y - 1]);
  }
  return 0;
}
