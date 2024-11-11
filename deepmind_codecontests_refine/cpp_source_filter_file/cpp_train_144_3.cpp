#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, k, a, an, ans;
  scanf("%d%d", &n, &m);
  scanf("%d", &an);
  k = an;
  for (i = 1; i < n; i++) {
    scanf("%d", &a);
    an = max(an, k - a);
    k = a;
  }
  ans = k - m;
  if (ans <= 0)
    printf("0\n");
  else
    printf("%d\n", ans);
  return 0;
}
