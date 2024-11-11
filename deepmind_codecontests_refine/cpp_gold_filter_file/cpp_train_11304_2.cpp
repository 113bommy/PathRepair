#include <bits/stdc++.h>
int a, b;
void process() {
  double x = 0;
  if (a < 4 * b) {
    x = a / (8.0 * b);
    printf("%.8lf\n", x / 2 + 0.5);
  } else {
    if (a == 0)
      x = 0;
    else
      x = (2.0 * b) / a;
    printf("%.8lf\n", 1 - x / 2);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &a, &b);
    process();
  }
  return 0;
}
