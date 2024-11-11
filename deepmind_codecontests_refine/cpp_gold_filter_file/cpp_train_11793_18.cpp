#include <bits/stdc++.h>
using namespace std;
double R, r, a, pi = acos(-1.0), eps = 1e-7;
int i, n;
int main() {
  scanf("%d%lf%lf", &n, &R, &r);
  if (n == 1 && r <= R) {
    puts("YES");
    return 0;
  }
  a = sqrt(2 * (R - r) * (R - r) - 2 * (R - r) * (R - r) * cos(2 * pi / n));
  if (2 * r <= a + eps)
    puts("YES");
  else
    puts("NO");
}
