#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 100, OO = 1e18 + 8, M = 3e5, lg = 22;
long long ans[N], cnt[N], a[N], seg[N];
void build(long long c, long long b, long long e) {
  if (e - b == 1) {
    seg[c] = b;
    return;
  }
  long long mid = (e + b) / 2;
  build(2 * c, b, mid);
  build(2 * c + 1, mid, e);
  if (a[seg[2 * c]] > a[seg[2 * c + 1]])
    seg[c] = seg[2 * c];
  else
    seg[c] = seg[2 * c + 1];
}
long long get(long long c, long long b, long long e, long long l, long long r) {
  if (b == l && e == r) return seg[c];
  long long mid = (b + e) / 2;
  if (r <= mid) return get(2 * c, b, mid, l, r);
  if (l >= mid) return get(2 * c + 1, mid, e, l, r);
  long long a1 = get(2 * c, b, mid, l, mid);
  long long a2 = get(2 * c + 1, mid, e, mid, r);
  if (a[a1] > a[a2])
    return a1;
  else
    return a2;
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vector<pair<pair<long long, long long>, long long> > v;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    v.push_back({{x, y}, i});
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < v.size(); i++) {
    a[i] = v[i].first.first + v[i].first.second - 1;
  }
  build(1, 0, n);
  vector<long long> e;
  for (long long i = v.size() - 1; i >= 0; i--) {
    long long x = v[i].first.first, h = v[i].first.second;
    x += h;
    x--;
    x *= -1;
    long long t = lower_bound(e.begin(), e.end(), x) - e.begin();
    if (t == e.size()) {
      cnt[i] = 1;
      ans[v[i].second] = cnt[i];
      e.push_back(-1 * v[i].first.first);
      continue;
    }
    t = v.size() - t;
    long long f = t - 1;
    t = get(1, 0, n, i, t);
    if (t == i)
      cnt[i] = f - i + 1;
    else
      cnt[i] = t - i + cnt[t];
    ans[v[i].second] = cnt[i];
    e.push_back(-1 * v[i].first.first);
  }
  for (long long i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
