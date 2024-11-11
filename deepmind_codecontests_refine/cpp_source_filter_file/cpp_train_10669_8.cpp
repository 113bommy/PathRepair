#include <bits/stdc++.h>
int main() {
  int n, a[2000] = {0}, b[2000] = {0}, c[2000] = {0}, t;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t);
    ++a[t - 1];
    c[i] = t;
  }
  for (int i = 1998; i + 1; --i) {
    b[i] = b[i + 1] + a[i];
  }
  for (int i = 0; i < n; ++i) printf("%d ", b[c[i] - 1] - (a[c[i] - 1] - 1));
}
