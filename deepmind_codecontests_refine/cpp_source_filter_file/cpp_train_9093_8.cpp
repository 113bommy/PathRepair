#include <bits/stdc++.h>
using namespace std;
int n, h;
pair<int, int> a[111111];
int main() {
  scanf("%d%d", &n, &h);
  if (n == 2) {
    printf("0");
    return 0;
  }
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].first), a[i].second = i;
  sort(a + 1, a + 1 + n);
  int mx = a[n].first + max(a[n - 1].first, a[1].first + h);
  int mn = min(a[1].first + a[2].first + h, a[2].first + a[3].first);
  int ps = a[1].second, par;
  int an = min(mx - mn, a[n].first + a[n - 1].first - a[1].first - a[2].first);
  if (mx - mn < a[n].first + a[n - 1].first - a[1].first - a[2].first)
    par = 2;
  else
    par = 1;
  printf("%d\n", an);
  for (int i = 1; i <= n; ++i)
    if (i == ps)
      printf("%d ", par);
    else
      printf("1 ");
  return 0;
}
