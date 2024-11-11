#include <bits/stdc++.h>
using namespace std;
long double n, a;
int main() {
  while (scanf("%llf %llf", &n, &a) != EOF) {
    long double angle = (n - 2.0L) * (180.0L / n);
    long double diff = angle / (n - 2.0L);
    int v1 = n, v2 = 1, aux = 2, v3;
    double res;
    v3 = aux;
    res = 1000.0 * 1000.0 * 1000.0 * 2L;
    while (angle > 0.0) {
      if (abs(angle - a) < res) {
        res = abs(angle - a);
        v3 = aux;
      }
      angle -= diff;
      aux++;
    }
    printf("%d %d %d\n", v1, v2, v3);
  }
  return 0;
}
