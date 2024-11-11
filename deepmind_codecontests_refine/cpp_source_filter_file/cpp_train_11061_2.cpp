#include <bits/stdc++.h>
using namespace std;
int T, n, ans;
int a[551111], b[551111], ta[551111], tb[551111], c[551111], d[551111];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ta[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    tb[b[i]] = i;
    c[b[i]] = i - ta[b[i]];
    if (c[b[i]] < 0) c[b[i]] += n;
    d[c[b[i]]]++;
  }
  for (int i = 1; i <= n; i++) {
    ans = max(ans, d[i]);
  }
  printf("%d\n", ans);
  return 0;
}
