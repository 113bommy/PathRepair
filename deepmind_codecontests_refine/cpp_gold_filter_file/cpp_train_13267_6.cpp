#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e3 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long n, dsu[maxn], sz[maxn], t[maxn], a[maxn], mx, s, ans;
pair<long long, pair<long long, long long> > e[maxn];
void init() {
  mx = 0;
  for (long long i = 1; i <= n; i++) {
    dsu[i] = i;
    sz[i] = 1;
    t[i] = a[i] + sz[i];
    mx = max(mx, t[i]);
  }
}
long long root(long long v) {
  if (dsu[v] == v) return v;
  return root(dsu[v]);
}
bool Union(long long v, long long u) {
  long long x = root(v), y = root(u);
  if (x == y) return 1;
  if (sz[x] < sz[y]) swap(x, y);
  sz[x] += sz[y];
  t[x] += t[y];
  mx = max(mx, t[x]);
  dsu[y] = x;
  return 0;
}
bool isval(long long x) {
  init();
  for (long long i = 0; i < n - 1; i++) {
    if (e[i].first < x) {
      Union(e[i].second.first, e[i].second.second);
    }
  }
  return (mx <= s);
}
int main() {
  long long v, u, c;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (long long i = 0; i < n - 1; i++) {
    cin >> e[i].second.first >> e[i].second.second >> e[i].first;
  }
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
  }
  long long l = 0, r = 2e4, mid;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (isval(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l;
  return 0;
}
