#include <bits/stdc++.h>
using namespace std;
double a1, a2, b1, b2, c1, c2;
int main() {
  scanf("%lf%lf%lf%lf%lf%lf", &a1, &b1, &c1, &a2, &b2, &c2);
  if (!b1 && !b2)
    if ((!a1 && c1) || (!a2 && c2))
      printf("0");
    else if ((!c1 && !c2) || (!a1 && !a2) || c1 / a1 == c2 / a2)
      printf("-1");
    else
      printf("0");
  else if ((!a1 && !b1 && !c1) || (!a2 && !b2 && !c2))
    printf("-1");
  else if ((!a1 && !b1) || (!a2 && !b2))
    printf("0");
  else if (!b1 || !b2)
    printf("1");
  else if (a1 / b1 == a2 / b2 && c2 / b2 == c1 / b1)
    printf("-1");
  else if (a1 / b1 == a2 / b2)
    printf("0");
  else
    printf("1");
  return 0;
}
