#include <bits/stdc++.h>
using namespace std;
const double sq2 = sqrt(2);
double ans, r;
int i, n;
void work(int x) {
  if (x >= 1) ans += 2 + sq2;
  x--;
  if (x <= 0) return;
  ans += 2 * sq2 * x + (long long)x * (x + 1);
}
int main() {
  scanf("%d%lf", &n, &r);
  for (i = 1; i <= n; ++i) {
    ans += 2;
    work(i - 1);
    work(n - i);
  }
  printf("%.4lf\n", ans * r / n / n);
}
