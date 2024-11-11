#include <bits/stdc++.h>
using namespace std;
int n;
long double p, l, ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%Lf", &p), ans = ans + (2 * l + 1) * p, l = (l + 1) * p;
  return 0 & printf("%0.7Lf", ans);
}
