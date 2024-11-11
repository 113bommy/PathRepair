#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int count = 0;
  double s, q, t;
  scanf("%lf %lf %lf", &t, &s, &q);
  while (t > s) {
    count++;
    s = s * q;
  }
  printf("%I64d\n", count);
  return 0;
}
