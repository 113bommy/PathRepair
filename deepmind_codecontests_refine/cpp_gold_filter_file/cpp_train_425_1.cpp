#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10, mod = 1e9 + 7, inf = 1e18, N2 = 1e6 + 10;
struct segment_tree {
  pair<long long, long long> it[N * 4];
  pair<long long, long long> combine(pair<long long, long long> t1,
                                     pair<long long, long long> t2) {
    return make_pair(t1.first + t2.first, t1.second + t2.second);
  }
  void update(int id, int l, int r, int v, pair<long long, long long> x) {
    if (l == r) {
      it[id] = x;
      return;
    }
    int mid = (l + r) >> 1;
    if (v <= mid)
      update(id * 2, l, mid, v, x);
    else
      update(id * 2 + 1, mid + 1, r, v, x);
    it[id] = combine(it[id * 2], it[id * 2 + 1]);
  }
  long long lw(int id, int l, int r, int x) {
    if (l == r) {
      if (it[id].second == 0) return 0;
      return it[id].first / it[id].second * min((long long)x, it[id].second);
    }
    int mid = (l + r) >> 1;
    if (it[id * 2].second >= x)
      return lw(id * 2, l, mid, x);
    else
      return it[id * 2].first +
             lw(id * 2 + 1, mid + 1, r, x - it[id * 2].second);
  }
};
struct ds {
  long long l, r, c, p;
};
struct ds2 {
  long long id, c, p;
};
int n, k, m;
ds query[N];
void read() {
  cin >> n >> k >> m;
  for (int i = 1; i <= m; i++)
    cin >> query[i].l >> query[i].r >> query[i].c >> query[i].p;
}
bool cmp(ds t1, ds t2) { return t1.p < t2.p; }
segment_tree seg;
vector<ds2> on[N2], off[N2];
void process() {
  sort(query + 1, query + m + 1, cmp);
  for (int i = 1; i <= m; i++)
    on[query[i].l].push_back({i, query[i].c, query[i].p}),
        off[query[i].r + 1].push_back({i, query[i].c, query[i].p});
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (ds2 x : on[i]) seg.update(1, 1, m, x.id, make_pair(x.c * x.p, x.c));
    for (ds2 x : off[i]) seg.update(1, 1, m, x.id, make_pair(0, 0));
    ans += seg.lw(1, 1, m, k);
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  read();
  process();
  return 0;
}
