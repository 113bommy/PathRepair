#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int ALL = 1e6;
struct Seg {
  long long tree[N << 2], cnt[N << 2];
  inline void pushup(int p) {
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
    cnt[p] = cnt[p << 1] + cnt[p << 1 | 1];
  }
  void update(int p, int l, int r, int pos, int cn, int opt) {
    if (l == r) {
      if (opt == 1) {
        tree[p] += 1LL * pos * cn;
        cnt[p] += cn;
      } else {
        tree[p] -= 1ll * pos * cn;
        cnt[p] -= cn;
      }
      return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
      update(p << 1, l, mid, pos, cn, opt);
    else
      update(p << 1 | 1, mid + 1, r, pos, cn, opt);
    pushup(p);
  }
  long long query(int p, int l, int r, int k) {
    if (cnt[p] <= k) return tree[p];
    if (l == r) return 1LL * k * l;
    int mid = l + r >> 1;
    if (cnt[p << 1] >= k) return query(p << 1, l, mid, k);
    return tree[p << 1] + query(p << 1 | 1, mid + 1, r, k - cnt[p << 1]);
  }
} seg;
vector<pair<pair<int, int>, int> > G[N];
int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= m; i++) {
    int l, r, c, p;
    scanf("%d%d%d%d", &l, &r, &c, &p);
    G[l].push_back(pair<pair<int, int>, int>(pair<int, int>(c, p), 1));
    G[r + 1].push_back(pair<pair<int, int>, int>(pair<int, int>(c, p), 0));
  }
  int now = 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (auto p : G[i])
      seg.update(1, 1, ALL, p.first.second, p.first.first, p.second);
    ans += seg.query(1, 1, ALL, k);
  }
  printf("%lld\n", ans);
  return 0;
}
