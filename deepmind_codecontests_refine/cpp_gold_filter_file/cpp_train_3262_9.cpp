#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f, g;
double q, w, x, y;
int niz[15000];
int main() {
  scanf("%d%d", &a, &b);
  for (int i = 0; i < a; ++i) scanf("%d", &niz[i]);
  for (int j = 1; j < a; ++j) {
    c += niz[j] - niz[0];
  }
  q = double((b + c)) / double(a);
  if (q < 0) {
    printf("-1");
    return 0;
  }
  for (int j = 1; j < a; ++j) {
    if (q + niz[0] - niz[j] < 0) {
      printf("-1");
      return 0;
    }
  }
  printf("%.6lf\n", q);
  for (int j = 1; j < a; ++j) {
    printf("%.6lf\n", q + niz[0] - niz[j]);
  }
}
