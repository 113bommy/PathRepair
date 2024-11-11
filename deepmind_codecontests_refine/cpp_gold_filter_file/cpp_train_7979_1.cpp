#include <bits/stdc++.h>
using namespace std;
int n, m, i, t = 2e9, x, a[1111111];
int main() {
  for (scanf("%d%d", &n, &m); i < m; i++) scanf("%d", &x), a[x]++;
  for (i = 1; i <= n; i++) t = min(t, a[i]);
  printf("%d", t);
}
