#include <bits/stdc++.h>
using namespace std;
int a, b, l, r;
int main() {
  cin >> a >> b >> l >> r;
  l--;
  r--;
  int pl = l % (a + b);
  int pr = r % (a + b);
  int cl = l / (a + b);
  int cr = r / (a + b);
  if (b >= a) {
    if (cr > cl + 1) {
      printf("%d\n", a + 1);
    } else if (cr == cl + 1) {
      int le = max(0, a - pl);
      int ri = min(a, pr + 1);
      int ans = min(a, le + ri);
      if (ri == a) ans++;
      printf("%d\n", ans);
    } else {
      printf("%d\n", min(pr - pl + 1, max(1, a - pl)));
    }
  } else {
    int minus = a - b;
    if (cr > cl + 2) {
      printf("%d\n", minus + a);
    } else if (cr == cl + 2) {
      printf("%d\n",
             a + max(1, min(minus, (pr + 1 - a + minus) + max(0, a - pl))));
    } else if (cr == cl + 1) {
      int ans = max(1, min(minus, a - pl)) + min(a, pr + 1);
      printf("%d\n", ans);
    } else {
      printf("%d\n", min(pr - pl + 1, max(1, a - pl)));
    }
  }
  return 0;
}
