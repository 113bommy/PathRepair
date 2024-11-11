#include <bits/stdc++.h>
using namespace std;
int n;
double a, dl, d, x, y, ile;
int main() {
  scanf("%lf %lf", &a, &dl);
  dl = dl - ((int)(dl / (4 * a))) * 4 * a;
  scanf("%d", &n);
  int kier = 0;
  for (int i = 0; i < n; i++) {
    d = dl;
    while (d > 0) {
      if (kier == 0) {
        ile = min(a - x, d);
        x += ile;
      } else if (kier == 1) {
        ile = min(a - y, d);
        y += ile;
      } else if (kier == 2) {
        ile = min(x, d);
        x -= ile;
      } else {
        ile = min(y, d);
        y -= ile;
      }
      d -= ile;
      if (d != 0) kier = (kier + 1) % 4;
    }
    printf("%lf %lf\n", x, y);
  }
  return 0;
}
