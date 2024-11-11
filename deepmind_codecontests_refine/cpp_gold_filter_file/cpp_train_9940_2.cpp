#include <bits/stdc++.h>
using namespace std;
int n, w, h, H, p;
multiset<int> ah, aw, x, y;
multiset<int>::iterator l, r;
char C;
int main() {
  scanf("%d %d %d", &w, &h, &n);
  x.insert(0);
  x.insert(h);
  y.insert(0);
  y.insert(w);
  ah.insert(h);
  aw.insert(w);
  for (int i = 0; i < n; i++) {
    scanf(" %c %d", &C, &H);
    if (C == 'H') {
      l = x.lower_bound(H);
      l--;
      r = x.upper_bound(H);
      p = (*r) - (*l);
      ah.erase(ah.lower_bound(p));
      ah.insert(H - (*l));
      ah.insert((*r) - H);
      x.insert(H);
    } else {
      l = y.lower_bound(H);
      l--;
      r = y.upper_bound(H);
      p = (*r) - (*l);
      aw.erase(aw.lower_bound(p));
      aw.insert(H - (*l));
      aw.insert((*r) - H);
      y.insert(H);
    }
    l = ah.end();
    r = aw.end();
    l--;
    r--;
    printf("%I64d\n", (*l) * 1ll * (*r));
  }
  return 0;
}
