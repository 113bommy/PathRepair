#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  int hh, mm;
  double a, b;
  scanf("%d%c%d", &hh, &c, &mm);
  if (((!hh) && (!mm)) || ((hh == 12) && (!mm)))
    printf("%d %d\n", 0, 0);
  else {
    if (hh >= 12) hh = hh - 12;
    b = mm * 360 / 60.0;
    a = (hh * 360 + b) / 12.0;
    printf("%.9lf %.9lf\n", a, b);
  }
  return 0;
}
