#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
const long long mod = 1e18;
const long long inf = 1e18;
long long n, q, a[maxn], seg[maxn * 4], bl[maxn * 4], br[maxn * 4];
long long ans, al, ar;
void fix(long long ind, long long v = 1, long long s = 0, long long e = n) {
  if ((e - s) == 1) {
    seg[v] = 1;
    bl[v] = 1;
    br[v] = 1;
    return;
  }
  long long mid = (e + s) / 2ll, lc = v + v, rc = lc | 1;
  if (ind < mid)
    fix(ind, lc, s, mid);
  else
    fix(ind, rc, mid, e);
  if (a[mid] < a[mid - 1]) {
    seg[v] = seg[lc] + seg[rc];
    bl[v] = bl[lc];
    br[v] = br[rc];
    return;
  }
  seg[v] = seg[lc] + seg[rc] + br[lc] * bl[rc];
  if (bl[lc] == (mid - s))
    bl[v] = bl[lc] + bl[rc];
  else
    bl[v] = bl[lc];
  if (br[rc] == (e - mid))
    br[v] = br[rc] + br[lc];
  else
    br[v] = br[rc];
}
void solve(long long l, long long r, long long v = 1, long long s = 0,
           long long e = n) {
  if ((l >= e) || (r <= s)) return;
  if ((l <= s) && (e <= r)) {
    if (ans == -1) {
      ans = seg[v];
      al = bl[v];
      ar = br[v];
      return;
    }
    if (a[s - 1] > a[s]) {
      ans += seg[v];
      ar = br[v];
      return;
    }
    ans += seg[v] + ar * bl[v];
    if (br[v] == (e - s))
      ar += br[v];
    else
      ar = br[v];
    if (al == (s - l)) al += bl[v];
    return;
  }
  long long mid = (e + s) / 2ll, lc = v + v, rc = lc | 1;
  solve(l, r, lc, s, mid);
  solve(l, r, rc, mid, e);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    fix(i);
  }
  while (q--) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long x, y;
      cin >> x >> y;
      a[x - 1] = y;
      fix(x - 1);
      continue;
    }
    long long l1, r1;
    cin >> l1 >> r1;
    ans = -1;
    solve(l1 - 1, r1);
    cout << ans << endl;
  }
}
