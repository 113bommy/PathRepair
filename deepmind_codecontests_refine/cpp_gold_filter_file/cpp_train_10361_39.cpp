#include <bits/stdc++.h>
long long mpow(long long a, long long n, long long mod) {
  long long ret = 1;
  long long b = a;
  while (n) {
    if (n & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    n >>= 1;
  }
  return (long long)ret;
}
using namespace std;
using namespace std;
long long tree[4 * (int)(1e5 + 4)], vol[(int)(1e5 + 4)];
long long dp[(int)(1e5 + 4)];
void update(int i, int l, int r, int x, long long val) {
  if (x < l || x > r) return;
  if (l == r && x == l) {
    tree[i] = max(tree[i], val);
    return;
  }
  int mid = (l + r) >> 1;
  update(2 * i, l, mid, x, val);
  update(2 * i + 1, mid + 1, r, x, val);
  tree[i] = max(tree[2 * i], tree[2 * i + 1]);
}
long long query(int i, int l, int r, int ql, int qr) {
  if (qr < l || ql > r) return 0;
  if (l >= ql && r <= qr) {
    return tree[i];
  }
  int mid = (l + r) >> 1;
  return max(query(2 * i, l, mid, ql, qr),
             query(2 * i + 1, mid + 1, r, ql, qr));
}
map<long long, int> compress;
set<long long> s;
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long r, h;
    cin >> r >> h;
    vol[i] = r * r * h;
    s.insert(vol[i]);
  }
  int id = 1;
  for (set<long long>::iterator it = s.begin(); it != s.end(); it++) {
    compress[*it] = id++;
  }
  id--;
  for (int i = 1; i <= n; i++) {
    int idx = compress[vol[i]];
    dp[idx] = max(dp[idx], query(1, 1, id, 1, idx - 1) + vol[i]);
    update(1, 1, id, idx, dp[idx]);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int idx = compress[vol[i]];
    ans = max(ans, dp[idx]);
  }
  double pi = acos(-1.0);
  double rem = ans;
  cout << fixed << setprecision(10) << pi * rem;
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
