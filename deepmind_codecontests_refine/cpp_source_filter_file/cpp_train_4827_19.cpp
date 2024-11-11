#include <bits/stdc++.h>
using namespace std;
int n;
double p[100010], x1[100010], x2[100010];
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
  for (int i = 1; i <= n; i++) {
    x1[i] = (x1[i - 1] + 1) * p[i];
    x2[i] = (x2[i - 1] + 2 * x1[i - 1] + 1) * p[i];
  }
  printf("%.1lf", x2[n]);
  return 0;
}
