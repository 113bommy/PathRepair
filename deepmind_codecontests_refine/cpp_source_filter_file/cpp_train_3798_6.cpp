#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5 + 9;
const long long oo = 1e10;
const long long mod = 1e9 + 7;
long long n, m, po = 1, k, q;
long long ans[N];
pair<long long, long long> rook[N], node[4 * 100009];
struct book {
  long long x1, y1, x2, y2;
  long long id;
} qu[N];
bool cmp(const book x, const book y) { return (x.y2 < y.y2); }
bool cmp1(pair<long long, long long> x, pair<long long, long long> y) {
  return x.second < y.second;
}
bool cmp3(const book x, const book y) { return x.x2 < y.x2; }
void update(long long i, long long l, long long r, long long pos,
            long long hi) {
  if (pos > r || pos < l || l > r) return;
  if (l == r) {
    node[i].first = 1;
    if (node[i].second < hi || node[i].second == oo) node[i].second = hi;
    return;
  }
  long long mid = (l + r) / 2;
  update(2 * i, l, mid, pos, hi);
  update(2 * i + 1, mid + 1, r, pos, hi);
  node[i].first = node[2 * i].first + node[2 * i + 1].first;
  node[i].second = min(node[2 * i].second, node[2 * i + 1].second);
}
long long getm(long long i, long long l, long long r, long long a, long long b,
               long long hi) {
  if (a > r || b < l || l > r) return 0;
  if (a <= l && r <= b) {
    if (node[i].second >= hi)
      return node[i].first;
    else
      return 0;
  }
  long long mid = (l + r) / 2;
  return getm(2 * i, l, mid, a, b, hi) + getm(2 * i + 1, mid + 1, r, a, b, hi);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> q;
  for (long long i = 1; i <= k; ++i) cin >> rook[i].first >> rook[i].second;
  for (long long i = 1; i <= q; ++i) {
    cin >> qu[i].x1 >> qu[i].y1 >> qu[i].x2 >> qu[i].y2, qu[i].id = i;
  }
  sort(rook + 1, rook + 1 + k, cmp1);
  sort(qu + 1, qu + 1 + q, cmp);
  for (long long i = 1; i <= 4 * n; ++i) node[i].second = oo;
  for (long long i = 1; i <= q; ++i) {
    while (po <= n && rook[po].second <= qu[i].y2) {
      update(1, 1, n, rook[po].first, rook[po].second);
      po++;
    }
    long long cur = getm(1, 1, n, qu[i].x1, qu[i].x2, qu[i].y1);
    if (cur == qu[i].x2 - qu[i].x1 + 1) ans[qu[i].id] = 1;
  }
  sort(rook + 1, rook + 1 + k);
  sort(qu + 1, qu + 1 + q, cmp3);
  for (long long i = 1; i <= 4 * m; ++i) node[i].second = oo, node[i].first = 0;
  po = 1;
  for (long long i = 1; i <= q; ++i)
    if (ans[qu[i].id] == 0) {
      while (po <= m && rook[po].first <= qu[i].x2) {
        update(1, 1, m, rook[po].second, rook[po].first);
        po++;
      }
      long long cur = getm(1, 1, m, qu[i].y1, qu[i].y2, qu[i].x1);
      if (cur == qu[i].y2 - qu[i].y1 + 1) ans[qu[i].id] = 1;
    }
  for (long long i = 1; i <= q; ++i)
    if (ans[i])
      cout << "YES\n";
    else
      cout << "NO\n";
}
