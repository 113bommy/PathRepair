#include <bits/stdc++.h>
int main() {
  double h, m;
  scanf("%lf:%lf", &h, &m);
  if (h == 12) h = 0;
  h *= 30;
  h += m / 2;
  m *= 6;
  int numDec = 0;
  for (; ((int)(pow(10, numDec) * h)) != pow(10, numDec) * h; numDec++)
    ;
  printf("%.*lf %.0lf\n", numDec, h, m);
  return 0;
}
