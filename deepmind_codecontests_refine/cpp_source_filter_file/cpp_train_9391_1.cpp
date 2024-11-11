#include <bits/stdc++.h>
using namespace std;
int a, b, c, r, l, T;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &a, &b, &c, &r);
    if (a > b) swap(a, b);
    l = c - r;
    r = c + r;
    r = min(r, b);
    l = max(l, a);
    if (r < l) r = l;
    printf("%d", b - a - r + l);
  }
  return 0;
}
