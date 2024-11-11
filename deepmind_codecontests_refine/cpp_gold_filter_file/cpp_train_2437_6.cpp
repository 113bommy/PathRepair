#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[110];
  int n, t, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  t = a[0];
  a[0] = a[n - 1];
  a[n - 1] = t;
  for (i = 0; i < n; i++) printf("%d ", a[i]);
  return 0;
}
