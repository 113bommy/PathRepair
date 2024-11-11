#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100 * 1000 + 17, inf = 1e17;
long long n, a[MAXN], seg[MAXN << 2], dp[MAXN], ans;
void add(int pos, int val, int v = 1, int l = 1, int r = n + 1) {
  if (pos < l || r <= pos) return;
  if (l + 1 == r) {
    seg[v] = val;
    return;
  }
  add(pos, val, v << 1, l, l + r >> 1);
  add(pos, val, v << 1 | 1, l + r >> 1, r);
  seg[v] = min(seg[v << 1], seg[v << 1 | 1]);
}
long long get(int lp, int rp, int v = 1, int l = 1, int r = n + 1) {
  if (rp <= l || r <= lp) return inf;
  if (lp <= l && r <= rp) return seg[v];
  return min(get(lp, rp, v << 1, l, l + r >> 1),
             get(lp, rp, v << 1 | 1, l + r >> 1, r));
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) cin >> a[i];
  add(n, n);
  for (int i = n - 1; i > 0; i--) {
    dp[i] = n - a[i] - i + get(i + 1, a[i] + 1);
    add(i, dp[i] + i);
    ans += dp[i];
  }
  cout << ans << endl;
  return 0;
}
