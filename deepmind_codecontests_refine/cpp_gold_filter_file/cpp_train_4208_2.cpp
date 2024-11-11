#include <bits/stdc++.h>
using namespace std;
int n, a, b, x[100005], y[100005];
int main() {
  int tot, ans, ind, mval;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  sort(x + 1, x + n + 1);
  tot = 0;
  for (int i = 1; i <= n; i++) {
    if (i == 1 || x[i] != x[i - 1]) y[++tot] = x[i];
  }
  scanf("%d%d", &a, &b);
  ans = 0;
  while (a > b) {
    mval = a - 1;
    ind = 0;
    for (int i = 1; i <= tot; i++) {
      if (a - a % y[i] >= b) y[++ind] = y[i];
    }
    tot = ind;
    for (int i = 1; i <= tot; i++) {
      if (a - a % y[i] < mval) mval = a - a % y[i];
    }
    a = mval;
    ans++;
  }
  printf("%d", ans);
  return 0;
}
