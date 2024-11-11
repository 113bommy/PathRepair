#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  scanf("%d", &n, &t);
  long double res = pow(1.000000011, t) * n;
  return !printf("%Lf\n", res);
}
