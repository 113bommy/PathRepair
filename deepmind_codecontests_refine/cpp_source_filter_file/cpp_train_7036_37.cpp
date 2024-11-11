#include <bits/stdc++.h>
using namespace std;
int a[200];
inline double sqr(double x) { return x * x; }
inline int rand1(int P) {
  double sum = 0;
  double x = (double)rand() / RAND_MAX;
  double frac = 1;
  for (int k = 0; k <= 2 * P; k++) {
    if (k) frac *= k;
    sum += (pow(P, k) * exp(-P)) / frac;
    if (x <= sum) return k;
  }
  return 2 * P;
}
inline int rand2(int P) {
  double x = (double)rand() / RAND_MAX;
  return (int)floor(x * (2 * P + 1));
}
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(a, 0, sizeof a);
    double sum = 0;
    for (int i = 0; i < 200; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    sum /= 200;
    double fangcha = 0;
    for (int i = 0; i < 200; i++) fangcha += sqr(a[i] - sum);
    fangcha /= 200;
    if (fangcha < 2 * sum)
      puts("poisson");
    else
      puts("uniform");
  }
  return 0;
}
