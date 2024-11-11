#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2500000000;
const int inf = 0x3f3f3f3f;
const double EPS = 1e-9;
const double PII = 2 * asin(1.0);
const long long mod = 1e9 + 7;
int double_cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
int main() {
  int n;
  scanf("%d", &n);
  int cont = 0;
  for (int i = 0; i < n; ++i) {
    int aux;
    scanf("%d", &aux);
    if (aux % 2 == 0) cont ^= aux;
    if (cont != 0)
      printf("%d\n", 1);
    else
      printf("%d\n", 2);
  }
}
