#include <bits/stdc++.h>
using namespace std;
long long total = 0;
struct c {
  int can;
  int tru;
};
int main() {
  double a, b, c;
  scanf("%lf%lf%lf", &a, &b, &c);
  printf("%.100f\n", a * (b) / (b + c));
}
