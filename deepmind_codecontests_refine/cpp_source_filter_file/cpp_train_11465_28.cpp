#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for (; t--;) {
    int d;
    scanf("%d", &d);
    if (d && d < 4) {
      printf("N\n");
      continue;
    }
    long double x = sqrt(d * (d - 4));
    printf("Y %.9Lf %.9Lf\n", (d + x) / 2.0f, (d - x) / 2.0f);
  }
  return 0;
}
