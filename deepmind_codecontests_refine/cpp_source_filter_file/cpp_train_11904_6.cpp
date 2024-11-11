#include <bits/stdc++.h>
using namespace std;
int main() {
  double s, a, b, c;
  scanf("%lf %lf %lf %lf", &s, &a, &b, &c);
  if (a == 0 && b == 0 && c == 0)
    printf("0 0 0");
  else
    printf("%lf %lf %lf", s * a / (a + b + c), s * b / (a + b + c),
           s * c / (a + b + c));
  return 0;
}
