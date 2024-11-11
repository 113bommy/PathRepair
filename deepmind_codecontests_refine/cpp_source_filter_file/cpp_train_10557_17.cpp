#include <bits/stdc++.h>
void swap(int v[], int n) {
  int tmp, i;
  for (i = 0; i < n; i += 2) {
    tmp = v[i];
    v[i] = v[i + 1];
    v[i + 1] = tmp;
  }
}
int main() {
  int v[2 * 50000], i, n, k;
  scanf("%d%d", &n, &k);
  for (i = 0; i < 2 * n; i++) v[i] = 2 * n - i;
  swap(v, k);
  for (i = 0; i < 2 * n; i++) printf(i == 2 * n - 1 ? "%d\n" : "%d ", v[i]);
}
