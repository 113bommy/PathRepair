#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-12;
const int N = 1e3 + 5;
const int mod = 998244353;
int n;
int x[N], y[N];
int main() {
  int Max, Mix, May, Miy;
  Max = May = -1e9;
  Mix = Miy = 1e9;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", x + i, y + i);
    Max = max(Max, x[i]);
    Mix = min(Mix, x[i]);
    May = max(May, y[i]);
    Miy = min(Miy, y[i]);
  }
  if (n == 3)
    printf("%d\n", 2 * (Max + May - Mix - Miy));
  else {
    int res = 0;
    for (int i = 1; i <= n; i++)
      res = max(res, max(abs(x[i] - Max), abs(x[i] - Mix)) +
                         max(abs(y[i] - May), abs(y[i] - Miy)));
    res *= 2;
    printf("%d", res);
    for (int i = 4; i <= n; i++) printf(" %d", 2 * (Max + May - Mix - Miy));
  }
  return 0;
}
