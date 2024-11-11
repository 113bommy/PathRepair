#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
int f[maxn], tmp, ans, sum, n, d, r, x;
int main() {
  scanf("%d %d", &n, &d);
  memset(f, 0, sizeof(f));
  f[0] = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    for (int j = maxn - 1 - x; j >= 0; j--) f[j + x] |= f[j];
  }
  r = 1;
  sum = 0;
  ans = 0;
  while (r < maxn) {
    tmp = -1;
    while (r <= sum + d && r < maxn) {
      if (f[r]) tmp = r;
      r++;
    }
    if (tmp == -1) break;
    sum = tmp;
    ans++;
  }
  printf("%d %d\n", sum, ans);
  return 0;
}
