#include <bits/stdc++.h>
int s, u;
int po[6] = {500, 1000, 1500, 2000, 2500};
double total;
struct cf {
  int min;
  int wro;
  double score;
} data[6];
int main() {
  for (int i = 0; i < 5; i++) scanf("%d", &data[i].min);
  for (int i = 0; i < 5; i++) scanf("%d", &data[i].wro);
  scanf("%d %d", &s, &u);
  for (int i = 0; i < 5; i++) {
    double point1 = (1 - data[i].min / 250.0) * po[i] - 50 * data[i].wro;
    double point2 = 0.3 * po[i];
    data[i].score = (point1 > point2 ? point1 : point2);
    total += data[i].score;
  }
  total += s * 100 - 50 * u;
  printf("%.0lf", total);
  return 0;
}
