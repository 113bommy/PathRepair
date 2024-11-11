#include <bits/stdc++.h>
using namespace std;
long long n, m, a[51][20001], sum[51][20001], f[2][20001], L, R, val, ans, k;
long long t[100010], lazy[100010];
void build(long long l, long long r, long long node) {
  if (l == r) {
    t[node] = f[l][0];
    return;
  }
  long long mid = (l + r) >> 1;
  build(l, mid, node << 1);
  build(mid + 1, r, node << 1 | 1);
  t[node] = max(t[node << 1], t[node << 1 | 1]);
}
void push(long long l, long long r, long long node) {
  t[node] += lazy[node];
  if (l != r) {
    lazy[node << 1] += lazy[node];
    lazy[node << 1 | 1] += lazy[node];
  }
  lazy[node] = 0;
}
void upd(long long l, long long r, long long node) {
  push(l, r, node);
  if (l > R || r < L) return;
  if (L <= l && r <= R) {
    lazy[node] += val;
    push(l, r, node);
    return;
  }
  long long mid = (l + r) >> 1;
  upd(l, mid, node << 1);
  upd(mid + 1, r, node << 1 | 1);
  t[node] = max(t[node << 1], t[node << 1 | 1]);
}
long long query(long long l, long long r, long long node) {
  push(l, r, node);
  if (l > R || r < L) return 0;
  if (L <= l && r <= R) {
    return t[node];
  }
  long long mid = (l + r) >> 1;
  return max(query(l, mid, node << 1), query(mid + 1, r, node << 1 | 1));
}
void modify(long long l, long long r, long long val2) {
  L = l, R = r, val = val2;
  upd(0, m - 1, 1);
}
long long get(long long l, long long r) {
  L = l, R = r;
  return query(0, m - 1, 1);
}
void solve() {
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      cin >> a[i][j];
      sum[i][j] = a[i][j];
      if (j) sum[i][j] += sum[i][j - 1];
    }
  for (long long i = 1; i <= n; i++) {
    memset(t, 0, sizeof(t));
    memset(lazy, 0, sizeof(lazy));
    for (long long j = 0; j < m; j++) {
      f[j][0] = f[j][1];
      f[j][1] = 0;
    }
    build(0, m - 1, 1);
    if (i > 1)
      for (long long j = k - 1; j >= 0; j--) modify(0, j, -a[i - 1][j]);
    for (long long j = 0; j <= m - k; j++) {
      long long res = sum[i][j + k - 1] + sum[i - 1][j + k - 1];
      if (j) res -= sum[i][j - 1] + sum[i - 1][j - 1];
      f[j][1] = get(0, m - 1) + res;
      ans = max(ans, f[j][1]);
      if (i == 1) continue;
      modify(max(0LL, j - k + 1), j, a[i - 1][j]);
      modify(j + 1, min(m - 1, j + k), -a[i - 1][j + k]);
    }
  }
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
