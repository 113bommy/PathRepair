#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, k, a, an, ans;
  scanf("%d%d", &n, &m);
  scanf("%d", &k);
  an = 0;
  for (i = 1; i < n; i++) {
    scanf("%d", &a);
    an = max(an, k - a);
    k = a;
  }
  ans = an - m;
  if (ans <= 0)
    printf("0\n");
  else
    printf("%d\n", ans);
  return 0;
}
