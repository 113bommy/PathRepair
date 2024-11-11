#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const long long inf = 1e18 + 10;
int seg[4 * maxn], a[maxn], cnt[maxn], ps[maxn], ans[maxn];
map<int, int> last;
vector<pair<pair<int, int>, int> > qr;
inline void update(int ind) {
  seg[ind] = seg[((ind) * (2))] ^ seg[(((ind) * (2)) + 1)];
}
void add(int s, int e, int ind, int l, int r, int x) {
  if (s > r || e < l) return;
  if (s >= l && e <= r) {
    seg[ind] = x;
    return;
  }
  int mid = (s + e) / 2;
  add(s, mid, ((ind) * (2)), l, r, x);
  add(mid + 1, e, (((ind) * (2)) + 1), l, r, x);
  update(ind);
}
int query(int s, int e, int ind, int l, int r) {
  if (s > r || e < l) return 0;
  if (s >= l && e <= r) return seg[ind];
  int mid = (s + e) / 2;
  return query(s, mid, ((ind) * (2)), l, r) ^
         query(mid + 1, e, (((ind) * (2)) + 1), l, r);
}
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ps[i] = ps[i - 1] ^ a[i];
  cin >> m;
  for (int i = 0, l, r; i < m; i++) {
    scanf("%d %d", &l, &r);
    qr.push_back({{r, l}, i});
  }
  int j = 0;
  sort(qr.begin(), qr.end());
  for (int i = 1; i <= n; i++) {
    cnt[last[a[i]]] = 0;
    if (last[a[i]]) add(1, n, 1, last[a[i]], last[a[i]], 0);
    cnt[i] = 1;
    last[a[i]] = i;
    add(1, n, 1, i, i, a[i]);
    while (qr[j].first.first == i && j < qr.size()) {
      ans[qr[j].second] =
          query(1, n, 1, qr[j].first.second, qr[j].first.first) ^
          ps[qr[j].first.first] ^ ps[qr[j].first.second - 1];
      j++;
    }
  }
  for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
  return 0;
}
