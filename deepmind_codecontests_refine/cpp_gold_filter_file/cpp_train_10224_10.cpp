#include <bits/stdc++.h>
using namespace std;
int a[200002];
int ca[200003];
vector<pair<int, pair<int, int> > > input;
unordered_map<int, int> cmp, rcmp;
class OS {
 public:
  int segtree[800002];
  int query(int node, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && qr >= r) return segtree[node];
    int m = (l + r) / 2;
    int a = query(2 * node, l, m, ql, qr);
    int b = query(2 * node + 1, m + 1, r, ql, qr);
    return a + b;
  }
  void update(int node, int l, int r, int in, int val) {
    if (l == r) {
      segtree[node] += val;
      return;
    }
    int m = (l + r) / 2;
    if (in <= m)
      update(2 * node, l, m, in, val);
    else
      update(2 * node + 1, m + 1, r, in, val);
    segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
  }
  int ranking(int x, int n) { return query(1, 1, n, 1, x - 1); }
  int order_stats(int k, int n) {
    int l = 1;
    int r = n + 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (ranking(m, n) < k)
        l = m + 1;
      else
        r = m;
    }
    return l - 1;
  }
};
int ans[200003];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  set<int> s;
  OS os = OS();
  for (int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]), rcmp[i] = a[i];
  int in = 1;
  for (auto x : s) {
    cmp[x] = in;
    in++;
  }
  for (int i = 1; i <= n; i++) a[i] = cmp[a[i]];
  int m;
  cin >> m;
  int tm = m;
  int mind = 1;
  while (tm--) {
    int i, j;
    cin >> i >> j;
    input.push_back({i, {j, mind}});
    mind++;
  }
  sort(input.begin(), input.end());
  vector<pair<int, int> > v;
  for (int i = 1; i <= n; i++) {
    v.push_back({-a[i], i});
  }
  sort(v.begin(), v.end());
  int iter_k = 0;
  for (auto p : input) {
    int k = p.first;
    int qin = p.second.first;
    int inputin = p.second.second;
    while (iter_k + 1 <= k) {
      auto pp = v[iter_k];
      int val = -pp.first;
      int in = pp.second;
      os.update(1, 1, n, in, 1);
      iter_k++;
    }
    int pans = os.order_stats(qin, n);
    ans[inputin] = pans;
  }
  for (int i = 1; i <= m; i++) cout << rcmp[ans[i]] << "\n";
  return 0;
}
