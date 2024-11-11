#include <bits/stdc++.h>
using namespace std;
long long d[3333][3333], a[3333], b[3333];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    a[i] -= i;
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  int bn = unique(b + 1, b + 1 + n) - b - 1;
  memset(d, 127, sizeof(d));
  for (int i = 1; i <= bn; ++i) {
    d[1][i] = min(d[1][i - 1], abs(a[1] - b[i]));
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= bn; ++j) {
      d[i][j] = min(d[i][j - 1], d[i - 1][j] + abs(a[i] - b[j]));
    }
  }
  printf("%I64dd", d[n][bn]);
  return 0;
}
