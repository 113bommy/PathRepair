#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long N = 100005, inf = 1e18;
long long tree[4 * N], n, a[N];
void upd(long long node, long long l, long long r, long long pos,
         long long val) {
  if (l == r) {
    tree[node] = val;
    return;
  }
  long long mid = (l + r) / 2;
  if (pos <= mid)
    upd(2 * node, l, mid, pos, val);
  else
    upd(2 * node + 1, mid + 1, r, pos, val);
  tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
long long query(long long node, long long l, long long r, long long s,
                long long e) {
  if (s > r || e < l) return inf;
  if (s <= l && e >= r) return tree[node];
  long long mid = (l + r) / 2;
  return min(query(2 * node, l, mid, s, e),
             query(2 * node + 1, mid + 1, r, s, e));
}
void solve() {
  cin >> n;
  vector<bool> occur(n + 3, false);
  vector<long long> last(n + 3, 0);
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] != 1) occur[1] = true;
  }
  for (long long i = 1; i <= n; i++) {
    if (a[i] != 1) {
      long long x = query(1, 1, n, 1, a[i] - 1);
      if (x > last[a[i]]) occur[a[i]] = true;
    }
    upd(1, 1, n, a[i], i);
    last[a[i]] = i;
  }
  for (long long i = 2; i <= (n + 1); i++) {
    long long x = query(1, 1, n, 1, i - 1);
    if (x > last[i]) occur[i] = true;
  }
  for (long long i = 1; i <= (n + 2); i++)
    if (!occur[i]) {
      cout << i << "\n";
      break;
    }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
