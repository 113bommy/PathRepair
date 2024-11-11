#include <bits/stdc++.h>
using namespace std;
int main() {
  char begintime[6];
  while (scanf("%s", &begintime) != EOF) {
    int h = (begintime[0] - '0') * 10 + (begintime[1] - '0');
    int m = (begintime[3] - '0') * 10 + (begintime[4] - '0');
    if (h - 12 < 0)
      printf("%lf %lf\n", 30 * h + 0.5 * m, 6 * m);
    else
      printf("%lf %lf\n", 30 * (h - 12) + 0.5 * m, 6 * m);
  }
  return 0;
}
