#include <bits/stdc++.h>
using namespace std;
double n, r;
int main() {
  scanf("%lf %lf", &n, &r);
  double aci = 180 / n;
  aci = aci * 3.14159265 / 180;
  printf("%.7lf", (r * sin(aci) / (1 - sin(aci))));
  return 0;
}
