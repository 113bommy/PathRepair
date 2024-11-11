#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, d, a[105];
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int i = 1;
    while (d && i < n) {
      int tmp = d / i;
      if (tmp >= a[i]) {
        a[0] += a[i];
        d -= a[i] * i;
        i++;
      } else {
        a[0] += tmp;
        d = 0;
        break;
      }
    }
    printf("%d\n", a[0]);
  }
  return 0;
}
