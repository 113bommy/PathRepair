#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG = 20;
long long n, m, k, u, v, x, y, t, l, r, tot;
long long B[MAXN];
pair<long long, long long> seg[MAXN << 2];
set<int> neg;
pair<long long, long long> combine(pair<long long, long long> x,
                                   pair<long long, long long> y) {
  return {min(x.first, y.first), max(x.second, y.second)};
}
pair<long long, long long> build(int id, int tl, int tr) {
  if (tr - tl == 1) return seg[id] = {B[tl], B[tl]};
  int mid = (tl + tr) >> 1;
  return seg[id] =
             combine(build(id << 1, tl, mid), build(id << 1 | 1, mid, tr));
}
void update(int id, int tl, int tr, int pos, long long val) {
  if (pos < tl || tr <= pos) return;
  if (tr - tl == 1) {
    seg[id] = {val, val};
    return;
  }
  int mid = (tl + tr) >> 1;
  update(id << 1, tl, mid, pos, val);
  update(id << 1 | 1, mid, tr, pos, val);
  seg[id] = combine(seg[id << 1], seg[id << 1 | 1]);
}
pair<long long, long long> get(int id, int tl, int tr, int l, int r) {
  if (r <= tl || tr <= l) return seg[0];
  if (l <= tl && tr <= r) return seg[id];
  int mid = (tl + tr) >> 1;
  return combine(get(id << 1, tl, mid, l, r), get(id << 1 | 1, mid, tr, l, r));
}
void change(int i, long long val) {
  if (i < 1 || n <= i) return;
  tot -= abs(B[i]);
  B[i] += val;
  update(1, 1, n, i, B[i]);
  tot += abs(B[i]);
  neg.erase(i);
  if (B[i] <= 0) neg.insert(i);
}
long long check(int i, long long val) {
  long long res = 0;
  if (i) res += abs(B[i] - val) - abs(B[i]);
  if (i + 1 < n) res += abs(B[i + 1] + val) - abs(B[i + 1]);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  seg[0] = {INF, -INF};
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> B[i];
  for (int i = 1; i < n; i++) {
    B[i] -= B[i + 1];
    if (B[i] > 0)
      tot += B[i];
    else {
      neg.insert(i);
      tot -= B[i];
    }
  }
  neg.insert(n + 1);
  build(1, 1, n);
  cin >> m;
  while (m--) {
    cin >> t >> l >> r >> x;
    if (t == 2) {
      change(l - 1, -x);
      change(r, x);
      continue;
    }
    long long ans = -2 * x;
    if (r - l <= 200) {
      for (int i = l - 1; i <= r - 1; i++) ans = max(ans, check(i, x));
      cout << ans + tot << '\n';
      continue;
    }
    ans = max(ans, check(l - 1, x));
    int pos = *neg.lower_bound(l);
    if (r < pos) {
      long long mx = get(1, 1, n, l, r).first;
      ans = max(ans, abs(mx - x) + x - mx);
    } else {
      pair<long long, long long> p = get(1, 1, n, pos, r + 1);
      if (p.second >= 0)
        ans = 2 * x;
      else {
        ans = max(ans, check(pos - 1, x));
        if (pos - l > 1) {
          long long mn = get(1, 1, n, l, pos - 1).first;
          ans = max(ans, abs(mn - x) + x - mn);
        }
        if (pos != r) {
          long long mx = get(1, 1, n, pos + 1, r + 1).second;
          ans = max(ans, abs(mx + x) + x - abs(mx));
        }
      }
    }
    cout << ans + tot << '\n';
  }
  return 0;
}
