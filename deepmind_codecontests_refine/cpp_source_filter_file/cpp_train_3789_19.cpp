#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  long long *mas;
  mas = new long long[n];
  for (int i = 0; i < n; ++i) scanf("%I64d", &mas[i]);
  int t, v, x;
  long long shift = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d", &v, &x);
      mas[v - 1] = x;
    } else if (t == 2) {
      scanf("%d", &x);
      shift += x;
    } else {
      scanf("%d", &v);
      printf("%I64d\n", shift + (long long)mas[v - 1]);
    }
  }
  delete[] mas;
  return 0;
}
