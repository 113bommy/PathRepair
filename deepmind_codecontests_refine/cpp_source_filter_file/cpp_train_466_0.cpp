#include <bits/stdc++.h>
using namespace std;
double max(double a, double b) {
  if (a > b) return a;
  return b;
}
int main() {
  double m[5], w[5], maxi[5] = {500, 1000, 1500, 2000, 2500};
  for (int i = 0; i < 5; i++) {
    scanf("%lf", &m[i]);
  }
  for (int i = 0; i < 5; i++) {
    scanf("%lf", &w[i]);
  }
  double score = 0;
  for (int i = 0; i < 5; i++) {
    score += max(0.3 * maxi[i], (1 - m[i] / 250) * maxi[i] - 50 * w[i]);
  }
  double s, u;
  scanf("%lf %lf", &s, &u);
  score += s * 100;
  score -= u * 50;
  printf("%lf\n", score);
  return 0;
}
