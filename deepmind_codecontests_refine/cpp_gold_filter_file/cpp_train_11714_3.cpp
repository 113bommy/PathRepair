#include <bits/stdc++.h>
using namespace std;
int main() {
  double d, l, v1, v2;
  scanf("%lf %lf %lf %lf", &d, &l, &v1, &v2);
  l -= d;
  v1 += v2;
  l /= v1;
  printf("%f", l);
}
