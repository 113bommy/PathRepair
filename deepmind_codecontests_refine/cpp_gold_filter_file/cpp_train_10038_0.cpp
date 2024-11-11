#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[n];
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  int b[m];
  for (int i = 0; i < m; ++i) scanf("%d", b + i);
  sort(a, a + n);
  sort(b, b + m);
  int total = 0;
  for (int i = 0, j = 0; i < m && j < n; ++i) {
    while (i < m && b[i] < a[j]) ++i;
    if (i >= m) break;
    ++j;
    total = j;
  }
  printf("%d\n", n - total);
  return 0;
}
