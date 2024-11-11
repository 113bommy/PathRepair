#include <bits/stdc++.h>
using namespace std;
int s, a, b, c, t;
int main() {
  scanf("%d%d%d%d", &s, &a, &b, &c);
  t = a + b + c;
  if (t == 0)
    printf("0.0 0.0 0.0\n");
  else
    printf("%.7f %.7f %.7f\n", (double)s * a / t, (double)s * b / t,
           (double)s * c / t);
  return 0;
}
