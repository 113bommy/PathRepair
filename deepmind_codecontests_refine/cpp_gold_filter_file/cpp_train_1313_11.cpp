#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 123;
vector<int> t[4 * maxn];
int n, m, pt[maxn];
void build(int v = 1, int tl = 1, int tr = n) {
  if (tl == tr) {
    t[v].push_back(pt[tl]);
    return;
  }
  int tm = (tl + tr) >> 1;
  build(v + v, tl, tm);
  build(v + v + 1, tm + 1, tr);
  t[v].resize(t[v + v].size() + t[v + v + 1].size());
  merge(t[v + v].begin(), t[v + v].end(), t[v + v + 1].begin(),
        t[v + v + 1].end(), t[v].begin());
}
int get(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
  if (l > tr || tl > r) return 0;
  if (l <= tl && tr <= r)
    return upper_bound(t[v].begin(), t[v].end(), x) - t[v].begin();
  int tm = (tl + tr) >> 1;
  return get(l, r, x, v + v, tl, tm) + get(l, r, x, v + v + 1, tm + 1, tr);
}
long long f(int x) { return x * 1ll * (x - 1); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &pt[i]);
  }
  build();
  for (int i = 1, l, d, r, u; i <= m; i++) {
    scanf("%d%d%d%d", &l, &d, &r, &u);
    long long ans = f(n);
    ans -= f(l - 1);
    ans -= f(d - 1);
    ans -= f(n - r);
    ans -= f(n - u);
    ans += f(get(1, l - 1, d - 1));
    ans += f(l - 1 - get(1, l - 1, u));
    ans += f(get(r + 1, n, d - 1));
    ans += f(n - r - get(r + 1, n, u));
    printf("%lld\n", ans / 2);
  }
  return 0;
}
