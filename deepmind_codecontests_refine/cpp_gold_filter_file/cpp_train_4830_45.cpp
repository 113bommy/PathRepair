#include <bits/stdc++.h>
using namespace std;
const int NMax = 300;
const double PI = 3.14159265358979f;
int N;
int main() {
  scanf("%d", &N);
  double d = 0;
  if (N < 5) {
    puts("No solution");
    return 0;
  }
  double alpha = (double)2 * PI / N, l = 500, first = 0, second = 0;
  d = alpha;
  printf("%.4lf %.4lf\n", first, second);
  for (int i = 2; i < N; i++) {
    first = first + cos(d) * l;
    second = second + sin(d) * l;
    l += 0.01;
    d = alpha * (double)i;
    printf("%.4lf %.4lf\n", first, second);
  }
  double k = tan(d), k1 = tan(d + alpha);
  double b = second - k * first;
  double x1 = b / (k1 - k), y1 = k1 * x1;
  printf("%.4lf %.4lf\n", x1, y1);
  return 0;
}
