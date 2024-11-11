#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const long long linf = 4000000000000000000LL;
const long long inf = 998244353;
const long double pi = 3.1415926535;
void pv(vector<int> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<long long> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<vector<int>> a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << '\n';
    pv(a[i]);
    cout << '\n';
  }
}
void pv(vector<vector<long long>> a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << '\n';
    pv(a[i]);
  }
  cout << '\n';
}
void pv(vector<string> a) {
  for (auto& x : a) cout << x << '\n';
  cout << '\n';
}
void setIO(string second) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (int(second.size())) {
    freopen((second + ".in").c_str(), "r", stdin);
    if (second != "test1") freopen((second + ".out").c_str(), "w", stdout);
  }
}
const int MAX = 5e5;
class segment_tree {
  struct item {
    int sum;
  };
  item single(int i) { return {i}; }
  item merge(item x, item y) {
    item ans;
    ans.sum = min(x.sum, y.sum);
    return ans;
  }
  vector<item> tree;
  int height;
  item neutral = {inf};

 public:
  void build() {
    int n = MAX;
    height = log2(n + 1) + 1;
    tree.resize((1 << height + 1) - 1, neutral);
  }

 public:
  int query(int l, int r) { return query(0, 0, (1 << height) - 1, l, r).sum; }
  item query(int v, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) return neutral;
    if (l <= tl && r >= tr) {
      return tree[v];
    }
    int mid = (tl + tr) / 2;
    return merge(query(2 * v + 1, tl, mid, l, r),
                 query(2 * v + 2, mid + 1, tr, l, r));
  }

 public:
  void update(int pos, int val) {
    update(0, 0, (1 << height) - 1, pos, single(val));
  }
  void update(int v, int tl, int tr, int pos, item val) {
    if (tl == tr) {
      tree[v] = val;
    } else {
      int mid = (tl + tr) / 2;
      if (pos <= mid)
        update(2 * v + 1, tl, mid, pos, val);
      else
        update(2 * v + 2, mid + 1, tr, pos, val);
      tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
    }
  }

 public:
  int get(int k, int l, int r) { return get(0, 0, (1 << height) - 1, k, l, r); }
  int get(int v, int tl, int tr, int k, int l, int r) {
    if (tr < l || tl > r) return inf;
    if (tree[v].sum > k) return inf;
    if (tl == tr) return tl;
    int mid = (tl + tr) / 2;
    if (tl >= l && tr <= r) {
      if (k < tree[2 * v + 1].sum) return get(2 * v + 2, mid + 1, tr, k, l, r);
      return get(2 * v + 1, tl, mid, k, l, r);
    } else
      return min(get(2 * v + 1, tl, mid, k, l, r),
                 get(2 * v + 2, mid + 1, tr, k, l, r));
  }
};
int n, q;
vector<int> a;
vector<vector<pair<int, int>>> query;
int main() {
  setIO("");
  cin >> n;
  a.resize(n);
  for (auto& x : a) cin >> x, x--;
  cin >> q;
  query.resize(n);
  for (int i = (0); i < (q); ++i) {
    int l, r;
    cin >> l >> r;
    r--, l--;
    query[r].push_back({l, i});
  }
  vector<int> last(MAX, -2);
  segment_tree sum;
  sum.build();
  vector<int> ans(q);
  for (int i = (0); i < (n); ++i) {
    if (last[a[i]] != -2) {
      sum.update(last[a[i]], inf);
    }
    sum.update(i, last[a[i]] + 1);
    last[a[i]] = i;
    for (auto& x : query[i]) {
      int v = sum.query(x.first, i);
      if (v < x.first) ans[x.second] = a[sum.get(v, x.first, i)] + 1;
    }
  }
  for (auto& x : ans) cout << x << '\n';
}
