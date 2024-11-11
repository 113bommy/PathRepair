#include <bits/stdc++.h>
using namespace std;
struct node {
  long long l, r;
  long long mx = -1e18;
  long long ch = 0;
};
vector<node> tree;
void push(long long v) {
  if (tree[v].l != tree[v].r) {
    tree[v * 2].ch += tree[v].ch;
    tree[v * 2 + 1].ch += tree[v].ch;
  }
  tree[v].mx += tree[v].ch;
  tree[v].ch = 0;
}
vector<long long> atc(1e6 + 2, 1e17);
vector<long long> def(1e6 + 2, 1e17);
void build(long long v, long long l, long long r) {
  tree[v].l = l, tree[v].r = r;
  if (l == r) {
    tree[v].mx = def[l];
    return;
  }
  long long mid = (r + l) / 2;
  build(v * 2, l, mid);
  build(v * 2 + 1, mid + 1, r);
  tree[v].mx = max(tree[v * 2].mx, tree[v * 2 + 1].mx);
}
void upd(long long v, long long l, long long r, long long val) {
  push(v);
  if (tree[v].l > r || tree[v].r < l) return;
  if (tree[v].l >= l && tree[v].r <= r) {
    tree[v].ch += val;
    push(v);
    return;
  }
  upd(v * 2, l, r, val);
  upd(v * 2 + 1, l, r, val);
  tree[v].mx = max(tree[v * 2].mx, tree[v * 2 + 1].mx);
}
signed main() {
  ios_base::sync_with_stdio(false);
  long long mna = 1e9, mnb = 1e9;
  long long n, m, k;
  cin >> n >> m >> k;
  tree.resize(1e6 * 4);
  for (long long i = 0; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    mna = min(mna, b);
    atc[a - 1] = min(atc[a - 1], b);
  }
  for (long long i = 1e6; i >= 0; --i) atc[i] = min(atc[i + 1], atc[i]);
  for (long long i = 0; i < m; ++i) {
    long long a, b;
    cin >> a >> b;
    mnb = min(mnb, b);
    def[a - 1] = min(def[a - 1], b);
  }
  for (long long i = 1e6; i >= 0; --i) def[i] = min(def[i + 1], def[i]);
  for (long long i = 0; i < 1e6 + 2; ++i) def[i] *= -1;
  vector<pair<long long, pair<long long, long long> > > mnst;
  for (long long i = 0; i < k; ++i) {
    long long d, a, cen;
    cin >> d >> a >> cen;
    mnst.push_back({d, {a, cen}});
  }
  build(1, 0, 1e6 + 1);
  sort(mnst.begin(), mnst.end());
  long long j = 0;
  long long ans = -(mnb + mna);
  for (long long i = 0; i < 1e6 + 1; ++i) {
    while (j < k && mnst[j].first <= i) {
      long long att = mnst[j].second.first, cen = mnst[j].second.second;
      upd(1, att, 1e6 + 1, cen);
      ++j;
    }
    long long sum = tree[1].mx - atc[i];
    ans = max(sum, ans);
  }
  cout << ans;
}
