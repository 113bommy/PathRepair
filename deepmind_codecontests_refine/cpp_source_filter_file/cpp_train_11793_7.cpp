#include <bits/stdc++.h>
using namespace std;
double R, r, a, pi = acos(-1.), eps = 1e-8;
int i, n;
int main() {
  scanf("%d%lf%lf", &n, &R, &r);
  if (n == 1 && r <= R) {
    puts("YES");
    return 0;
  }
  a = sqrt(2 * (R - r) * (R - r) - 4 * (R - r) * (R - r) * cos(2 * pi / n));
  if (2 * r <= a + eps)
    puts("YES");
  else
    puts("NO");
}
