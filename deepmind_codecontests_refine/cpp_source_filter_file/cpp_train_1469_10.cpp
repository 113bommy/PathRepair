#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, skc = 1e9 + 7;
int a[N], w[N], n;
int low(int x) { return x & -x; }
struct node {
  long long t[N];
  void add(int x, long long vl) {
    for (; x <= n; x += low(x)) t[x] += vl;
  }
  long long query(int x) {
    long long tot = 0;
    for (; x; x -= low(x)) tot += t[x];
    return tot;
  }
  long long ask(int x, int y) { return (x > y ? 0 : query(y) - query(x - 1)); }
} A, B;
int erfen(int l, int r) {
  if (A.ask(l, r - 1) <= A.ask(r, r)) return r;
  int p = l, mid = l + r >> 1, x = l, y = r;
  while (l <= r) {
    mid = l + r >> 1;
    if (A.ask(x, mid) <= A.ask(mid + 1, y))
      p = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return p + 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long ans;
  int x, y, q, p;
  cin >> n >> q;
  for (register int i = (1); i <= (n); ++i) cin >> a[i];
  for (register int i = (1); i <= (n); ++i)
    cin >> w[i], A.add(i, w[i]), B.add(i, 1ll * w[i] * (a[i] - i) % skc);
  while (q--) {
    cin >> x >> y;
    if (x < 0) {
      x = -x;
      A.add(x, y - w[x]);
      B.add(x, 1ll * (y - w[x]) * (a[x] - x) % skc);
      w[x] = y;
    } else {
      p = erfen(x, y);
      ans = A.ask(x, p - 1) * (a[p] - p) - B.ask(x, p - 1);
      ans += B.ask(p + 1, y) - A.ask(p + 1, y) * (a[p] - p);
      cout << (ans % skc + skc) % skc << '\n';
    }
  }
  return 0;
}
