#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 5;
int n, k, a[N], dp[N], prv[N];
int seg[N << 2], lazy[N << 2];
inline void add(int id, int x) {
  seg[id] += x;
  lazy[id] += x;
}
inline void shift(int id) {
  add(id << 1, lazy[id]);
  add(id << 1 | 1, lazy[id]);
  lazy[id] = 0;
}
void build(int id = 1, int st = 0, int en = n + 1) {
  lazy[id] = 0;
  if (en - st == 1) {
    seg[id] = dp[st];
    return;
  }
  int mid = st + en >> 1;
  build(id << 1, st, mid);
  build(id << 1 | 1, mid, en);
  seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
void update(int l, int r, int x, int id = 1, int st = 0, int en = n + 1) {
  if (r <= st || en <= l) return;
  if (l <= st && en <= r) return add(id, x);
  shift(id);
  int mid = st + en >> 1;
  update(l, r, x, id << 1, st, mid);
  update(l, r, x, id << 1 | 1, mid, en);
  seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
int get(int l, int r, int id = 1, int st = 0, int en = n + 1) {
  if (r <= st || en <= l) return -1e9;
  if (l <= st && en <= r) return seg[id];
  shift(id);
  int mid = st + en >> 1;
  return max(get(l, r, id << 1, st, mid), get(l, r, id << 1 | 1, mid, en));
}
inline void read_input() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
}
inline void solve() {
  memset(dp, -63, sizeof dp);
  for (int i = dp[0] = 0; i < k; i++) {
    build();
    memset(prv, 0, sizeof prv);
    for (int j = 0; j <= n; j++) {
      dp[j] = get(0, j);
      update(prv[a[j]], j + 1, 1);
      prv[a[j]] = j + 1;
    }
  }
  cout << dp[n];
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve();
  return 0;
}
