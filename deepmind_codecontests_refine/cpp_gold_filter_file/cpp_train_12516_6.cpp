#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 2e5 + 10;
long long n, m, p;
pair<long long, long long> a[maxn], b[maxn];
pair<pair<long long, long long>, long long> mon[maxn];
long long ans, tmm[maxn * 4], tmx[maxn * 4], tree[maxn * 4], lazy[maxn * 4];
void build(long long rt, long long l, long long r) {
  lazy[rt] = 0;
  if (l == r) {
    tmm[rt] = tmx[rt] = b[l].first;
    tree[rt] = -b[l].second;
    return;
  }
  long long m = (l + r) / 2;
  build(rt * 2, l, m);
  build(rt * 2 + 1, m + 1, r);
  tmm[rt] = min(tmm[rt * 2], tmm[rt * 2 + 1]);
  tmx[rt] = max(tmx[rt * 2], tmx[rt * 2 + 1]);
  tree[rt] = max(tree[rt * 2], tree[rt * 2 + 1]);
}
void upd(long long rt, long long l, long long r, long long x, long long y) {
  if (tmm[rt] >= x) {
    tree[rt] += y;
    lazy[rt] += y;
    return;
  }
  if (tmx[rt] < x) return;
  long long m = (l + r) / 2;
  if (lazy[rt] != 0) {
    tree[rt * 2] += lazy[rt];
    lazy[rt * 2] += lazy[rt];
    tree[rt * 2 + 1] += lazy[rt];
    lazy[rt * 2 + 1] += lazy[rt];
    lazy[rt] = 0;
  }
  upd(rt * 2, l, m, x, y);
  upd(rt * 2 + 1, m + 1, r, x, y);
  tree[rt] = max(tree[rt * 2], tree[rt * 2 + 1]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> p;
  for (long long i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  for (long long i = 1; i <= m; i++) cin >> b[i].first >> b[i].second;
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  for (long long i = 1; i <= p; i++)
    cin >> mon[i].first.first >> mon[i].first.second >> mon[i].second;
  sort(mon + 1, mon + 1 + p);
  build(1, 1, m);
  for (long long i = 1; i <= p; i++) {
    upd(1, 1, m, mon[i].first.second + 1, mon[i].second);
  }
  ans = -a[1].second - b[1].second;
  for (long long i = n, j = p; i > 0; i--) {
    while (j > 0 && mon[j].first.first >= a[i].first) {
      upd(1, 1, m, mon[j].first.second + 1, -mon[j].second);
      j--;
    }
    ans = max(ans, tree[1] - a[i].second);
  }
  cout << ans << endl;
  return 0;
}
