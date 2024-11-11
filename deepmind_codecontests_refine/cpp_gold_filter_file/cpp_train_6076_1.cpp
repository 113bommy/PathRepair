#include <bits/stdc++.h>
using namespace std;
const int N = 100010, inf = 1000000007;
int n, h, mi = inf, mi0 = inf, mi1 = inf, ma0, ma1, pos, a[N];
int main() {
  scanf("%d %d", &n, &h);
  if (n == 2)
    printf("0\n1 1");
  else {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] < mi) mi = a[i], pos = i;
    }
    for (int i = 1; i <= n; i++)
      if (i != pos) {
        if (a[i] > ma0)
          ma1 = ma0, ma0 = a[i];
        else if (a[i] > ma1)
          ma1 = a[i];
        if (a[i] < mi0)
          mi1 = mi0, mi0 = a[i];
        else if (a[i] < mi1)
          mi1 = a[i];
      }
    printf("%d\n", min(ma0 + ma1 - mi - mi0, max(ma0 + ma1, ma0 + mi + h) -
                                                 min(mi0 + mi1, mi0 + mi + h)));
    if (ma0 + ma1 - mi - mi0 >
        max(ma0 + ma1, ma0 + mi + h) - min(mi0 + mi1, mi0 + mi + h)) {
      for (int i = 1; i <= n; i++)
        if (i != pos)
          printf("1 ");
        else
          printf("2 ");
    } else
      for (int i = 1; i <= n; i++) printf("1 ");
  }
  return 0;
}
