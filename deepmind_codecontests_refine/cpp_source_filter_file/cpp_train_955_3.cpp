#include <bits/stdc++.h>
using namespace std;
int q, n, r;
int d[100001], f[100001];
int main() {
  scanf("%d", &q);
  for (; q; --q) {
    scanf("%d %d", &n, &r);
    for (register int i = 1; i <= n; i = -~i) {
      scanf("%d", &d[i]);
      if (f[d[i]])
        --i, --n;
      else
        f[d[i]] = 1;
    }
    sort(d, d + n);
    for (register int i = n; i >= 0; --i)
      if (d[i] <= r * (n - i)) {
        printf("%d\n", n - i);
        break;
      }
    for (register int i = 1; i <= n; i = -~i) f[d[i]] = 0;
  }
}
