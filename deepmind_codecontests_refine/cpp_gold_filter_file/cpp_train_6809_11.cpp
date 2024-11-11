#include <bits/stdc++.h>
using namespace std;
int n, m, k, v, v1, v2, x;
int appear[1000], a[1000];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if ((n == k) || ((n - 1) * (n - 1 - 1) / 2 + n - k < m)) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", &x);
    appear[x] = 1;
    if (i == 1) v1 = x;
    if (i == 2) v2 = x;
  }
  v = 1;
  while (appear[v]) v++;
  a[1] = v1;
  a[2] = v;
  a[3] = v2;
  int sz = 4;
  for (int i = 1; i <= n; i++)
    if (i != v && i != v1 && i != v2) {
      a[sz] = i;
      sz++;
    }
  for (int i = 1; i < n; i++) printf("%d %d\n", a[i], a[i + 1]);
  m -= (n - 1);
  for (int i = 2; i < n; i++)
    for (int j = i + 2; j <= n; j++)
      if (m) {
        m--;
        printf("%d %d\n", a[i], a[j]);
      }
  for (int i = 3; i <= n; i++)
    if (m && !appear[a[i]]) {
      m--;
      printf("%d %d\n", a[1], a[i]);
    }
  return 0;
}
