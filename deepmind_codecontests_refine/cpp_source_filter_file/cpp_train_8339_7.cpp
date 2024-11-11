#include <bits/stdc++.h>
using namespace std;
int a, b, s, ans, c[1000005], d[1000005], cn, dn;
bool flag[1000005];
int main() {
  scanf("%d%d", &a, &b);
  ans = 0;
  while (s + ans + 1 <= a + b) {
    ans++;
    s += ans;
  }
  for (int i = ans; i >= 1; i--)
    if (!flag[i] && i <= a) {
      a -= i;
      c[++cn] = i;
      flag[i] = true;
    }
  for (int i = ans; i >= 1; i--)
    if (!flag[i] && i <= b) {
      b -= i;
      d[++dn] = i;
      flag[i] = true;
    }
  printf("%d\n", cn);
  for (int i = cn; i > 1; i--) printf("%d ", c[i]);
  if (cn > 0)
    printf("%d\n", c[1]);
  else
    putchar('\n');
  printf("%d\n", cn);
  for (int i = dn; i > 1; i--) printf("%d ", d[i]);
  if (dn > 0)
    printf("%d\n", d[1]);
  else
    putchar('\n');
  return 0;
}
