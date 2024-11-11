#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if (m == 1)
    printf("%.20lf", 0);
  else
    printf("%.20lf", 1. / n + 1. * (n - 1) / n * (m - 1) / (n * m - 1));
  return 0;
}
