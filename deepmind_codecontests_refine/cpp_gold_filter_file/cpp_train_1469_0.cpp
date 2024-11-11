#include <bits/stdc++.h>
using namespace std;
const int N = 200005, P = 1000000007;
using ll = long long;
int n, q, a[N];
ll w[N];
struct BIT {
  ll c[N];
  bool mod;
  inline static int lowbit(int x) { return x & -x; }
  void add(int x, ll val) {
    while (x <= n) {
      c[x] += val;
      if (mod) c[x] %= P;
      x += lowbit(x);
    }
  }
  ll query(int x) {
    ll ret = 0;
    while (x) ret += c[x], x -= lowbit(x);
    return mod ? ret % P : ret;
  }
  inline ll query(int x, int y) { return query(y) - query(x - 1); }
} ta, tb;
int getpos(int l, int r) {
  int ans = l, lp = l;
  ll t = ta.query(l, r);
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ta.query(lp, mid) > t / 2)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> w[i];
  ta.mod = 0;
  tb.mod = 1;
  for (int i = 1; i <= n; i++) {
    a[i] -= i;
    ta.add(i, w[i]);
    tb.add(i, a[i] * w[i] % P);
  }
  for (int _ = 0; _ < q; _++) {
    int t1, t2;
    cin >> t1 >> t2;
    if (t1 < 0) {
      t1 = -t1;
      ta.add(t1, -w[t1]);
      tb.add(t1, a[t1] * -w[t1] % P);
      ta.add(t1, w[t1] = t2);
      tb.add(t1, a[t1] * w[t1] % P);
    } else {
      int k = getpos(t1, t2);
      ll ans = (ta.query(t1, k) % P * a[k] % P - tb.query(t1, k)) % P +
               (tb.query(k, t2) - ta.query(k, t2) % P * a[k] % P) % P;
      ans = (ans % P + P) % P;
      cout << ans << endl;
    }
  }
  return 0;
}
