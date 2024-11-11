#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 7;
const long long M = 1e6 + 7;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
const double eps = 1e-6;
long long t, n, tot = 0;
long long arr[N], lsh[N], tree[N];
inline void pushup(long long node) {
  tree[node] = tree[node << 1] + tree[node << 1 | 1];
}
void build(long long node, long long l, long long r) {
  if (l == r) {
    tree[node] = 0;
    return;
  }
  long long mid = l + r >> 1;
  build(node << 1, l, mid), build(node << 1 | 1, mid + 1, r);
  pushup(node);
}
void Updata(long long node, long long l, long long r, long long pos,
            long long val) {
  if (l == r) {
    tree[node] += val;
    return;
  }
  long long mid = l + r >> 1;
  if (pos <= mid)
    Updata(node << 1, l, mid, pos, val);
  else
    Updata(node << 1 | 1, mid + 1, r, pos, val);
  pushup(node);
}
long long quary(long long node, long long l, long long r, long long ql,
                long long qr) {
  if (!ql || ql > qr) return 0;
  if (ql <= l && r <= qr) return tree[node];
  long long mid = l + r >> 1;
  long long ans = 0;
  if (ql <= mid) ans += quary(node << 1, l, mid, ql, qr);
  if (qr > mid) ans += quary(node << 1 | 1, mid + 1, r, ql, qr);
  return ans;
}
long long getid(long long val) {
  return lower_bound(lsh + 1, lsh + 1 + tot, val) - lsh;
}
void solve() {
  cin >> n;
  tot = 0;
  for (long long i = 1; i <= n; ++i) {
    cin >> arr[i];
    lsh[++tot] = arr[i];
  }
  sort(lsh + 1, lsh + 1 + tot);
  tot = unique(lsh + 1, lsh + 1 + tot) - (lsh + 1);
  build(1, 1, tot);
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    long long id = getid(arr[i]);
    ans += min(quary(1, 1, tot, 1, id - 1), quary(1, 1, tot, id + 1, tot));
    Updata(1, 1, tot, id, 1);
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) solve();
  return 0;
}
