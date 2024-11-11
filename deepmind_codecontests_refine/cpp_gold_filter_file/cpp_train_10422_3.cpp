#include <bits/stdc++.h>
using namespace std;
long long n, ans, l[100100], r[100100], uniq;
struct ps {
  long long l, r, id;
  ps other() { return ps{r, l, id}; }
  bool operator<(const ps &o) const {
    return tie(l, r, id) < tie(o.l, o.r, o.id);
  }
};
set<ps> pl, pr;
int main() {
  scanf("%lld", &n);
  ans = uniq = n;
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &l[i], &r[i]);
    pl.insert({l[i], r[i], i});
    pr.insert({r[i], l[i], i});
  }
  while (!pl.empty()) {
    ps p1 = *(pl.rbegin());
    pl.erase(p1);
    ps p2 = *(pr.rbegin());
    pr.erase(p2);
    if (p1.id == p2.id || pl.empty()) {
      ans += max(p1.l, p2.l);
      continue;
    }
    ans += max(p1.l, p2.l);
    ps newps{p2.r, p1.r, ++uniq};
    pl.insert(newps);
    pr.insert(newps.other());
    pl.erase(p2.other());
    pr.erase(p1.other());
  }
  printf("%lld\n", ans);
  return 0;
}
