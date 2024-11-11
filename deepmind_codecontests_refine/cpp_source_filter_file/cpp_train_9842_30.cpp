#include <bits/stdc++.h>
using namespace std;
const double PI =
    3.141592653589793238462643383279502884197169399375105820974944592307816406286;
double d, h, v, e;
int main() {
  scanf("%lf%lf%lf%lf", &d, &h, &v, &e);
  if (4 * v - d * d * PI * e <= 0)
    printf("NO\n");
  else
    printf("%.12f\n", (PI * h * d * d) / (4 * v - d * d * PI * e));
}
