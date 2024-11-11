#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[1000];
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int j = n - 1; j >= n - m; j--)
    if (k < a[j]) a[j] = k;
  int res = 0;
  for (int i = 0; i < n; i++) res += a[i];
  printf("%d\n", res);
  return 0;
}
