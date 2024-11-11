#include <bits/stdc++.h>
int soluong(int a[], int n) {
  int dem = 1, khac;
  for (int i = 1; i < n; i++) {
    khac = 3;
    for (int j = 0; j < i; j++) {
      if (a[i] == a[j]) {
        khac = 2;
        break;
      } else
        khac = 1;
    }
    if (khac == 1) dem++;
    return dem;
  }
}
int main() {
  int n, doi, i, o;
  scanf("%d", &n);
  int x[n], y[n];
  for (int z = 0; z < n; z++) scanf("%d%d", &x[z], &y[z]);
  int ngang, doc;
  ngang = soluong(y, n);
  doc = soluong(x, n);
  if (ngang <= doc)
    printf("%d", ngang);
  else
    printf("%d", doc);
  return 0;
}
