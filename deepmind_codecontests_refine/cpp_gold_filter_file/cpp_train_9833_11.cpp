#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if (m == 1)
    printf("%.20f", 1. / n);
  else
    printf("%.20f", 1. / n + 1. * (n - 1) / n * (m - 1) / (n * m - 1));
  return 0;
}
