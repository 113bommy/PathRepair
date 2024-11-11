#include <bits/stdc++.h>
using namespace std;
bool b[200005];
int main() {
  int n, k, i, p, q = 0, a[200005];
  scanf("%d%d", &n, &k);
  for (i = 0; i < k; i++) {
    scanf("%d", &a[i]);
    b[a[i]] = 1;
  }
  for (i = 0; i < k; i++) {
    p = 1;
    while (++p <= n) {
      while (b[++q])
        ;
      printf("%d ", q);
    }
    printf("%d\n", a[i]);
  }
  return 0;
}
