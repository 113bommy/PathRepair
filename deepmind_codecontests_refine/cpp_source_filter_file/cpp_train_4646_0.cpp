#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 50;
long long n, mx, a[maxn];
struct pii {
  long long f, s, id;
} p[maxn];
struct segt {
  long long seg[maxn];
  void build(long long l = 1, long long r = mx, long long idx = 1) {
    if (l == r) {
      seg[idx] = a[l];
      return;
    }
    long long mid = (l + r) >> 1;
    build(l, mid, idx << 1);
    build(mid + 1, r, idx << 1 | 1);
    seg[idx] = min(seg[idx << 1], seg[idx << 1 | 1]);
  }
  long long qry(long long a, long long b, long long l = 1, long long r = mx,
                long long idx = 1) {
    if (a <= l and b >= r) {
      return seg[idx];
    }
    long long mid = (l + r) >> 1;
    long long ret = 0x3f3f3f3f;
    if (a <= mid) ret = qry(a, b, l, mid, idx << 1);
    if (b > mid) ret = min(ret, qry(a, b, mid + 1, r, idx << 1 | 1));
    return ret;
  }
} tree;
vector<long long> vc;
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> p[i].f >> p[i].s;
    p[i].id = i;
    vc.emplace_back(p[i].f), vc.emplace_back(p[i].s),
        vc.emplace_back(p[i].s + 1);
  }
  sort(vc.begin(), vc.end());
  vc.resize(unique(vc.begin(), vc.end()) - vc.begin());
  mx = vc.size();
  for (long long i = 1; i <= n; i++) {
    p[i].f = lower_bound(vc.begin(), vc.end(), p[i].f) - vc.begin() + 1;
    p[i].s = lower_bound(vc.begin(), vc.end(), p[i].s) - vc.begin() + 1;
    a[p[i].f]++;
    a[p[i].s + 1]--;
  }
  for (long long i = 1; i <= mx; i++) {
    a[i] += a[i - 1];
  }
  tree.build();
  for (long long i = 1; i <= n; i++) {
    long long t = tree.qry(p[i].f, p[i].s);
    if (t >= 2) return cout << p[i].id << "\n", 0;
  }
  cout << -1 << "\n";
}
