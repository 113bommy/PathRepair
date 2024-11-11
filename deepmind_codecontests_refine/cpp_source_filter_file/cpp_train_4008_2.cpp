#include <bits/stdc++.h>
using namespace std;
const double pi = atan(1.0) * 4;
int N, W;
int a[100010 << 1];
double Min(double a, double b) { return a > b ? b : a; }
int main() {
  while (scanf("%d%d", &N, &W) == 2) {
    for (int i = 0; i < (N << 1); i++) {
      scanf("%d", a + i);
    }
    sort(a, a + (N << 1));
    printf("%f\n", 3 * N * Min(Min(a[0], a[N] / 2.0), W / 3.0 * N));
  }
  return 0;
}
