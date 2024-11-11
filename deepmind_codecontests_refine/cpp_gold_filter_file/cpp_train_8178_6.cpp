#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int INF = 1e9;
const double EPS = 1e-8;
int n, i, a[100050], f[100050];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", a + i);
    f[i] = min(f[i - 1] + 20,
               min(f[lower_bound(a + 1, a + i, a[i] - 89) - a - 1] + 50,
                   f[lower_bound(a + 1, a + i, a[i] - 1439) - a - 1] + 120));
    printf("%d\n", f[i] - f[i - 1]);
  }
  return 0;
}
