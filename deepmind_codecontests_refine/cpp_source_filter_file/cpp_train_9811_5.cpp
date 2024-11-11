#include <bits/stdc++.h>
using namespace std;
long long sqr(long long x) { return x * x; }
long long get(const vector<int> x, const vector<int> y, const vector<int> z) {
  long long ret = sqr(x[0] - y[0]) + sqr(y[0] - z[0]) + sqr(x[0] - z[0]);
  for (int now : y) {
    int rx = lower_bound(x.begin(), x.end(), now) - x.begin();
    if (rx > 0) rx--;
    int rz = lower_bound(z.begin(), z.end(), now) - z.begin();
    if (rz == z.size()) rz--;
    long long tmp_cost =
        sqr(x[rx] - now) + sqr(now - z[rz]) + sqr(x[rx] - z[rz]);
    ret = min(ret, tmp_cost);
  }
  return ret;
}
void solve() {
  int nr, ng, nb;
  scanf("%d%d%d", &nr, &ng, &nb);
  vector<int> r(nr);
  vector<int> g(ng);
  vector<int> b(nb);
  for (int i = 0; i < nr; i++) scanf("%d", &r[i]);
  for (int i = 0; i < ng; i++) scanf("%d", &g[i]);
  for (int i = 0; i < nb; i++) scanf("%d", &b[i]);
  sort(r.begin(), r.end());
  sort(g.begin(), g.end());
  sort(b.begin(), b.end());
  long long res = get(r, g, b);
  res = min(res, get(b, g, r));
  res = min(res, get(g, r, b));
  res = min(res, get(b, r, g));
  res = min(res, get(r, b, g));
  res = min(res, get(g, b, r));
  cout << res << endl;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
