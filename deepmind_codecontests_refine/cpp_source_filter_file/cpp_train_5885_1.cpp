#include <bits/stdc++.h>
using namespace std;
double PI = 3.14159265358979323846264338327950288419716939937510582;
double l1, l2, l3;
int main() {
  scanf("%lf%lf%lf", &l1, &l2, &l3);
  double area1 = sqrt(2) / 12.0 * l1 * l1 * l1;
  double area2 = sqrt(2) / 6.0 * l2 * l2 * l2;
  double area3 = 1.0 / 24.0 * (5 + sqrt(5)) * l3 * l3 * l3;
  printf("%lf\n", area1 + area2 + area3);
  return 0;
}
