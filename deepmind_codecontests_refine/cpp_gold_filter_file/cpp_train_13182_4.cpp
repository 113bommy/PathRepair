#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int dx8[] = {-1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[] = {0, -1, 0, 1, 1, -1, 1, -1};
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
 private:
  int s, _n;
  vector<S> st;
  void construct(int pos, int l, int r, vector<S> &ind) {
    if (l == r) {
      st[pos] = ind[l];
      return;
    }
    int mid = (l + r) / 2;
    construct(pos * 2 + 1, l, mid, ind);
    construct(pos * 2 + 2, mid + 1, r, ind);
    st[pos] = op(st[pos * 2 + 1], st[pos * 2 + 2]);
  }
  void update(int i, int j, int l, int r, S val, int pos) {
    if (l > r || l > j || r < i) return;
    if (l == r) {
      st[pos] = val;
      return;
    }
    int mid = (l + r) / 2;
    update(i, j, l, mid, val, 2 * pos + 1);
    update(i, j, mid + 1, r, val, 2 * pos + 2);
    st[pos] = op(st[pos * 2 + 1], st[pos * 2 + 2]);
  }
  void query(int i, int j, int l, int r, int pos, int k, int &ans) {
    if (l > r || l > j || r < i) {
      return;
    }
    if (i <= l && j >= r) {
      auto &vec = st[pos].arr;
      int left = 0, right = int(vec.size()) - 1;
      while (left <= right) {
        int mid = (left + right) / 2;
        if (vec[mid].first <= k) {
          left = mid + 1;
          ans = min(ans, vec[mid].second);
        } else {
          right = mid - 1;
        }
      }
      return;
    }
    int mid = (l + r) / 2;
    query(i, j, l, mid, pos * 2 + 1, k, ans);
    query(i, j, mid + 1, r, pos * 2 + 2, k, ans);
  }
  void bs(int i, int j, int l, int r, int pos, bool (*fun)(S), int &ans) {
    assert(l >= 0 && l < _n);
    assert(r >= 0 && r < _n);
    assert(r >= l);
    if (l > r || l > j || r < i) return;
    if (l == r) {
      if (fun(st[pos]) == false) ans = min(ans, r);
      return;
    }
    if (i <= l && j >= r) {
      if (fun(st[pos]) == false) {
        ans = min(ans, r);
        int mid = (l + r) / 2;
        if (fun(st[pos * 2 + 1]) == false)
          bs(i, j, l, mid, 2 * pos + 1, fun, ans);
        else if (fun(st[pos * 2 + 2]) == false)
          bs(i, j, mid + 1, r, 2 * pos + 2, fun, ans);
      }
      return;
    }
    int mid = (l + r) / 2;
    bs(i, j, l, mid, 2 * pos + 1, fun, ans);
    bs(i, j, mid + 1, r, 2 * pos + 2, fun, ans);
    return;
  }
  void rbs(int i, int j, int l, int r, int pos, bool (*fun)(S), int &ans) {
    assert(l >= 0 && l < _n);
    assert(r >= 0 && r < _n);
    assert(r >= l);
    if (l > r || l > j || r < i) return;
    if (l == r) {
      if (fun(st[pos]) == false) ans = max(ans, l);
      return;
    }
    if (i <= l && j >= r) {
      if (fun(st[pos]) == false) {
        ans = max(ans, l);
        int mid = (l + r) / 2;
        if (fun(st[pos * 2 + 2]) == false)
          rbs(i, j, l, mid, 2 * pos + 2, fun, ans);
        else if (fun(st[pos * 2 + 1]) == false)
          rbs(i, j, mid + 1, r, 2 * pos + 1, fun, ans);
      }
      return;
    }
    int mid = (l + r) / 2;
    rbs(i, j, mid + 1, r, 2 * pos + 2, fun, ans);
    rbs(i, j, l, mid, 2 * pos + 1, fun, ans);
    return;
  }

 public:
  segtree() : segtree(0) {}
  segtree(int n) : segtree(vector<S>(n, e())) {}
  segtree(vector<S> &v) : _n(int(v.size())) {
    assert(_n > 0);
    int s = ceil(log2(_n));
    s = pow(2, s + 1) - 1;
    st.clear();
    st.resize(s, e());
    construct(0, 0, _n - 1, v);
  }
  void set(int i, S val) {
    assert(i >= 0 && i < _n);
    update(i, i, 0, _n - 1, val, 0);
  }
  S query(int i) {
    assert(i >= 0 && i < _n);
    return query(i, i, 0, _n - 1, 0);
  }
  int query(int i, int j, int k) {
    assert(i >= 0 && i < _n);
    assert(i <= j && j >= 0 && j < _n);
    int ans = INT_MAX;
    query(i, j, 0, _n - 1, 0, k, ans);
    return ans;
  }
  template <bool (*fun)(S)>
  int bs(int l, int r) {
    assert(l >= 0 && l < _n);
    assert(r >= l && r >= 0 && r < _n);
    assert(fun(e()) == true);
    int ans = r + 1;
    bs(l, r, 0, _n - 1, 0, fun, ans);
    return ans;
  }
  template <bool (*fun)(S)>
  int rbs(int l, int r) {
    assert(l >= 0 && l < _n);
    assert(r >= l && r >= 0 && r < _n);
    assert(fun(e()) == true);
    int ans = l - 1;
    rbs(l, r, 0, _n - 1, 0, fun, ans);
    return ans;
  }
};
struct S {
  vector<pair<int, int>> arr;
};
S op(S a, S b) {
  auto &arr1 = a.arr;
  auto &arr2 = b.arr;
  vector<pair<int, int>> temp;
  int i = 0, j = 0;
  while (i < int(arr1.size()) or j < int(arr2.size())) {
    if (i == int(arr1.size())) {
      while (j < int(arr2.size())) {
        temp.push_back(arr2[j++]);
      }
      break;
    }
    if (j == int(arr2.size())) {
      while (i < int(arr1.size())) {
        temp.push_back(arr1[i++]);
      }
      break;
    }
    if (arr1[i].first < arr2[j].first)
      temp.push_back(arr1[i++]);
    else
      temp.push_back(arr2[j++]);
  }
  for (int i = 1; i < int(temp.size()); i++)
    temp[i].second = min(temp[i].second, temp[i - 1].second);
  return S{temp};
}
S e() { return S{{}}; }
vector<vector<int>> g;
vector<int> in_time, out_time;
vector<S> nodes;
vector<int> h;
vector<int> cost;
void dfs(int r, int p, int &t) {
  in_time[r] = t++;
  for (auto c : g[r]) {
    if (c == p) continue;
    h[c] = h[r] + 1;
    dfs(c, r, t);
  }
  nodes[in_time[r]] = S{vector<pair<int, int>>(1, {h[r], cost[r]})};
  out_time[r] = t - 1;
}
void solve() {
  int n, r;
  cin >> n >> r;
  r--;
  g.clear();
  g.resize(n);
  cost.clear();
  cost.resize(n);
  for (auto &a : cost) cin >> a;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  in_time = vector<int>(n);
  out_time = vector<int>(n);
  nodes = vector<S>(n);
  h = vector<int>(n);
  int t = 0;
  dfs(r, -1, t);
  segtree<S, op, e> seg(nodes);
  int q;
  cin >> q;
  int last = 0;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    int x, k;
    x = (a + last) % n;
    k = (b + last) % n;
    int l = in_time[x];
    int r = out_time[x];
    int deapth = h[x] + k;
    last = seg.query(l, r, deapth);
    cout << last << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
