#include <bits/stdc++.h>
using namespace std;
int n, m, v = 999, p = 0, c = 999;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    v = min(v, a);
    p = max(p, a);
  }
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    c = min(c, a);
  }
  if (max(2 * v, p) < c)
    printf("%d\n", max(2 * v, p));
  else
    printf("-1\n");
  return 0;
}
