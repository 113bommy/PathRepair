#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r;
  bool operator<(const node &a) const {
    if (l == a.l) return r < a.r;
    return l < a.l;
  }
} e[100010];
multiset<int> p;
multiset<int>::iterator it;
int main() {
  int i, j, k, n;
  long long x, y, s;
  scanf("%d%lld%lld", &n, &x, &y);
  for (i = 0; i < n; i++) scanf("%d%d", &e[i].l, &e[i].r);
  sort(e, e + n);
  s = 0;
  for (i = 0; i < n; i++) {
    it = p.lower_bound(e[i].l);
    if (!p.empty() && (it--) != p.begin() && y * (e[i].l - *it) < x) {
      s = (s + y * (e[i].r - *it)) % 1000000007;
      p.erase(*it);
      p.insert(e[i].r);
    } else {
      s = (s + x + y * (e[i].r - e[i].l)) % 1000000007;
      p.insert(e[i].r);
    }
  }
  printf("%lld\n", s);
  return 0;
}
