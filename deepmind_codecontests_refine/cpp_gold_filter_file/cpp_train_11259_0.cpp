#include <bits/stdc++.h>
using namespace std;
const int MAX = 110;
int c[MAX];
int main() {
  int n, t, ans = 0, minn = 0x3f3f3f3f, s, d;
  scanf("%d %d", &n, &t);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &s, &d);
    if (t <= s)
      c[i] = s - t;
    else {
      if ((t - s) % d == 0)
        ans = i;
      else
        c[i] = (((t - s) / d + 1) * d + s) - t;
    }
  }
  if (ans == 0)
    for (int i = 1; i <= n; i++)
      if (minn > c[i]) ans = i, minn = c[i];
  printf("%d\n", ans);
  return 0;
}
