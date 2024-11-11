#include <bits/stdc++.h>
using namespace std;
const double PI = atan(1.0) * 4;
const long long int INF = 100000000000000003;
const int32_t LOG = 21;
long long int a[300005], lazy[1200005];
long long int seg[1200005];
long long int cur[300005];
vector<long long int> vals[300005];
long long int comp(long long int p1, long long int p2) { return min(p1, p2); }
inline void build(long long int v, long long int tl, long long int tr) {
  if (tl == tr)
    seg[v] = a[tl];
  else {
    long long int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    seg[v] = comp(seg[v * 2], seg[v * 2 + 1]);
  }
}
inline void push(long long int v) {
  seg[v * 2] += lazy[v];
  seg[v * 2 + 1] += lazy[v];
  lazy[v * 2] += lazy[v];
  lazy[v * 2 + 1] += lazy[v];
  lazy[v] = 0;
}
inline void update(long long int v, long long int tl, long long int tr,
                   long long int l, long long int r, long long int inc) {
  if (l > r) return;
  if (l == tl && r == tr) {
    seg[v] += inc;
    lazy[v] += inc;
  } else {
    push(v);
    long long int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), inc);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, inc);
    seg[v] = comp(seg[v * 2], seg[v * 2 + 1]);
  }
}
long long int query(long long int v, long long int tl, long long int tr,
                    long long int l, long long int r) {
  if (l > r) return INF;
  if (l <= tl && tr <= r) return seg[v];
  push(v);
  long long int tm = (tl + tr) / 2;
  long long int q1 = query(v * 2, tl, tm, l, min(r, tm));
  long long int q2 = query(v * 2, tm + 1, tr, max(l, tm + 1), tr);
  return comp(q1, q2);
}
void reset(long long int n) {
  fill(seg, seg + 4 * n + 1, 0);
  fill(lazy, lazy + 4 * n + 1, 0);
  fill(cur, cur + n + 2, 0);
  fill(a, a + n + 2, 0);
  for (long long int i = 0; i < n + 2; i++) vals[i].clear();
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int b[n];
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      vals[x].push_back(i);
      a[i] = x;
    }
    for (long long int i = 0; i < n; i++) cin >> b[i];
    build(1, 0, n - 1);
    bool g = true;
    for (long long int i = 0; i < n; i++) {
      long long int toCheck = b[i];
      if (cur[toCheck] >= vals[toCheck].size()) {
        g = false;
        break;
      }
      long long int pos = vals[toCheck][cur[toCheck]];
      if (pos != 0) {
        long long int minval = query(1, 0, n - 1, 0, pos - 1);
        if (minval < toCheck) {
          g = false;
          break;
        }
      }
      cur[toCheck]++;
      update(1, 0, n - 1, pos, pos, INF);
    }
    if (!g)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
    reset(n);
  }
  return 0;
}
