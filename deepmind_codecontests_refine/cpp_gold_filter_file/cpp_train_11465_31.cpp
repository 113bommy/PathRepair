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
    double x = sqrt(d * (d - 4));
    printf("Y %.9f %.9f\n", (d + x) / 2.0f, (d - x) / 2.0f);
  }
  return 0;
}
