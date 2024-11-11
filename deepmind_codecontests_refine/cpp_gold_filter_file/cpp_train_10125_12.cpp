#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long n, k, m, seg[4 * maxn], lz[4 * maxn];
map<long long, long long> vis[maxn];
set<pair<long long, long long> > s;
void upd(long long id, long long s, long long e, long long l, long long r,
         long long x) {
  if (r <= s || e <= l) return;
  if (l <= s && e <= r) {
    seg[id] += x;
    lz[id] += x;
    return;
  }
  long long mid = (s + e) / 2;
  seg[id * 2] += lz[id];
  seg[id * 2 + 1] += lz[id];
  lz[id * 2] += lz[id];
  lz[id * 2 + 1] += lz[id];
  lz[id] = 0;
  upd(id * 2, s, mid, l, r, x);
  upd(id * 2 + 1, mid, e, l, r, x);
  seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
  return;
}
long long solve(long long id, long long s, long long e, long long x) {
  if (e - s == 1) return e;
  long long mid = (s + e) / 2;
  seg[id * 2] += lz[id];
  seg[id * 2 + 1] += lz[id];
  lz[id * 2] += lz[id];
  lz[id * 2 + 1] += lz[id];
  lz[id] = 0;
  if (max(x, seg[id * 2]) <= mid) return solve(id * 2, s, mid, x);
  return solve(id * 2 + 1, mid, e, max(x, seg[id * 2]));
}
int main() {
  long long x, y;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  for (long long i = 0; i < maxn; i++) {
    upd(1, 0, maxn - 1, i, i + 1, i);
  }
  cin >> n >> k >> m;
  s.insert(make_pair(-n, 0ll));
  for (long long i = 1; i <= m; i++) {
    cin >> x >> y;
    if (vis[x][y])
      upd(1, 0, maxn - 1, 0, y + abs(x - k), -1),
          s.erase(make_pair(-y - abs(x - k), vis[x][y])), vis[x][y] = 0;
    else
      upd(1, 0, maxn - 1, 0, y + abs(x - k), 1),
          vis[x][y] = i, s.insert(make_pair(-y - abs(x - k), i));
    cout << solve(1, 0, maxn - 1, -s.begin()->first) - n << '\n';
  }
  return 0;
}
