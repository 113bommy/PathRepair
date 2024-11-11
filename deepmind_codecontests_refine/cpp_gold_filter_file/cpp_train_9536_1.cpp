#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
struct pt {
  int x, y, z;
} p[N];
bool cmp(pt a, pt b) { return a.x > b.x; }
int n, mx, my, mz;
long long ans, area;
set<pair<int, int> > S;
bool test(set<pair<int, int> >::iterator x, set<pair<int, int> >::iterator y) {
  return x->first <= y->first && x->second <= y->second;
}
void erase(set<pair<int, int> >::iterator l, set<pair<int, int> >::iterator x,
           set<pair<int, int> >::iterator r) {
  area -= 1ll * (x->first - l->first) * (x->second - r->second);
  S.erase(x);
}
void insert(pair<int, int> v) {
  if (S.count(v)) return;
  S.insert(v);
  set<pair<int, int> >::iterator x = S.find(v), l = x, r = x, ll, rr;
  --l;
  ++r;
  area += 1ll * (x->first - l->first) * (x->second - r->second);
  while (test(l, x)) ll = l, --ll, erase(ll, l, x), l = ll;
  while (test(r, x)) rr = r, ++rr, erase(x, r, rr), r = rr;
  if (test(x, l) || test(x, r)) erase(l, x, r);
}
int main() {
  scanf("%d%d%d%d", &n, &mx, &my, &mz);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
  sort(p + 1, p + n + 1, cmp);
  S.insert(pair<int, int>(0, 1e9));
  S.insert(pair<int, int>(1e9, 0));
  for (int i = 1; i <= n; i++) insert(pair<int, int>(p[i].y, p[i].z));
  int j = 1;
  for (int i = mx; i; i--) {
    for (; j <= n && p[j].x >= i; j++)
      insert(pair<int, int>(p[j].y, mz)), insert(pair<int, int>(my, p[j].z));
    ans += 1ll * my * mz - area;
  }
  printf("%lld\n", ans);
  return 0;
}
