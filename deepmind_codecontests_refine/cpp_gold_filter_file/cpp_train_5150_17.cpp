#include <bits/stdc++.h>
using namespace std;
double a_val = 1.0, b_val;
int n, a[1010];
bool v[1000010];
double l = -1e9, r = 1e9;
int main() {
  cin >> n;
  for (register int i = 1; i <= n; ++i) scanf("%d", a + i), v[a[i]] = 1;
  for (register int i = 1; i <= a[n]; ++i) {
    b_val -= 10;
    if (v[i])
      r = min(r, -(b_val - 10.0) / a_val), ++a_val;
    else
      l = max(l, -(b_val - 10.0) / a_val);
  }
  l /= 10, r /= 10;
  l *= (n + 1), r *= (n + 1);
  l = floor(l), r = floor(r) == r ? r - 1 : floor(r);
  if (l == r) {
    puts("unique");
    printf("%.0lf", l);
  } else
    puts("not unique");
}
