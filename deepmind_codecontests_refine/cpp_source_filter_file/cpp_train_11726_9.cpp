#include <bits/stdc++.h>
using namespace std;
const int NMAX = 6;
int v[NMAX];
int x[NMAX];
int y[NMAX];
int main() {
  int n;
  scanf("%d", &n);
  ++n;
  bool ok = true;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &v[i]);
    if (ok == true) {
      if (i > 1 && !(v[i] == 1 || v[i - 1] == 1)) {
        ok = false;
      }
    }
  }
  if (ok == true) {
    printf("perfect\n");
    return 0;
  }
  printf("ambiguous\n");
  int poz = 1;
  x[poz] = 0;
  y[poz] = 0;
  for (int i = 2; i <= n; ++i) {
    if (v[i] > 1) {
      if (v[i - 1] == 1) {
        int t = poz;
        for (int j = 1; j <= v[i]; ++j) {
          x[++poz] = t;
          y[poz] = t;
        }
      } else {
        int t = poz;
        x[++poz] = t;
        y[poz] = t - 1;
        for (int j = 1; j < v[i]; ++j) {
          x[++poz] = t;
          y[poz] = t;
        }
      }
    } else {
      int t = poz;
      x[++poz] = t;
      y[poz] = t;
    }
  }
  for (int i = 1; i <= poz; ++i) {
    printf("%d ", x[i]);
  }
  printf("\n");
  for (int i = 1; i <= poz; ++i) {
    printf("%d ", y[i]);
  }
  printf("\n");
  return 0;
}
