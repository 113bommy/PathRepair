#include <bits/stdc++.h>
using namespace std;
long long add[(100 + 5)];
bool flag[(100 + 5)];
int main() {
  int n, m, x, y;
  long long rk;
  scanf("%d%d%I64d%d%d", &n, &m, &rk, &x, &y);
  if (n == 1) {
    long long tmp = rk / m, sy = rk - tmp * m;
    printf("%I64d %I64d ", tmp + (sy ? 1 : 0), tmp);
    printf("%I64d\n", tmp + ((y <= sy) ? 1 : 0));
    return 0;
  }
  int Roll = 2 * n - 2, rall = Roll * m;
  long long rt = rk / rall, sy = rk % rall;
  for (int i = (1); i <= (int)(n); ++i) add[i] += rt;
  for (int i = (2); i <= (int)(n - 1); ++i) add[i] += rt;
  int t = (int)sy / m, p = 0, ad = 1;
  sy -= t * m;
  while (t--) {
    p += ad;
    if (p > n) p = n - 1, ad = -1;
    ++add[p];
  }
  p += ad;
  if (p > n) p = n - 1;
  if (sy) flag[p] = true;
  long long now, Min = add[1] + flag[1], Max = add[1] + flag[1];
  for (int i = (2); i <= (int)(n); ++i) {
    now = add[i] + flag[i];
    Min = min(Min, add[i]);
    Max = max(Max, now);
  }
  long long me = add[x];
  if (flag[x] && sy >= y) ++me;
  printf("%I64d %I64d %I64d\n", Max, Min, me);
  return 0;
}
