#include <bits/stdc++.h>
using namespace std;
void doit() {
  int k = 250, sum = 0, sum2 = 0, a, P;
  double t;
  for (int i = 1; i <= k; i++) {
    scanf("%d", &a);
    sum += a;
    sum2 += a * a;
  }
  P = int(1.0 * sum / k + 0.5);
  t = 1.0 * sum2 / (P * P * k);
  if (t < 1.18)
    printf("poisson\n");
  else
    printf("uniform\n");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) doit();
  return 0;
}
