#include <bits/stdc++.h>
using namespace std;
int fb, tb, ta, fa, n, q, h, a, b;
int main() {
  scanf("%d%d%d%d%d", &n, &h, &a, &b, &q);
  while (q-- > 0) {
    scanf("%d%d%d%d", &ta, &fa, &tb, &fb);
    int zm = 0;
    if (ta > tb) {
      swap(ta, tb);
      swap(fa, fb);
    }
    int ans = tb - ta;
    int x = 0;
    if (fa >= b) {
      ans += fa - b;
      x = b;
    } else {
      if (fa <= a) {
        ans += a - fa;
        x = a;
      } else
        x = fa;
    }
    if (ans == 0)
      printf("%d\n", max(fa, fb) - min(fa, fb));
    else {
      ans += max(x, fb) - min(x, fb);
      printf("%d\n", ans);
    }
  }
}
