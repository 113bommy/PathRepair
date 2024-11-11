#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
int n;
double ans;
double p[maxn];
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%lf", &p[i]);
  for (i = 0; i <= n; ++i)
    for (j = i + 1; j <= n; ++j)
      if (2 * i <= n && n <= 2 * j)
        ans = max(ans, (j - n * 0.5) / (j - i) * p[i] +
                           (n * 0.5 - i) / (j - i) * p[j]);
  printf("%lf", ans);
  return 0;
}
