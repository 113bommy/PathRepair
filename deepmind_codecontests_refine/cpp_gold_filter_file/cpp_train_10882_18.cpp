#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100001];
int x[100000];
int indice;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  indice = 1;
  int poz = 1;
  while (m >= indice) {
    if (a[poz] == indice) {
      indice++;
      poz++;
    } else if (a[poz] > indice && m >= indice) {
      x[++x[0]] = indice;
      m -= indice;
      indice++;
    } else {
      if (m >= indice) {
        m -= indice;
        x[++x[0]] = indice;
        indice++;
      }
    }
  }
  printf("%d\n", x[0]);
  for (int i = 1; i <= x[0]; i++) printf("%d ", x[i]);
  return 0;
}
