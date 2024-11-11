#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
using namespace std;
template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}
template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}
const int N = 3e5 + 5;
template <typename T, typename U>
struct SegmentTree {
  int S, H;
  T zero;
  vector<T> value;
  U noop;
  vector<bool> dirty;
  vector<U> prop;
  void init(int _S = 1, T _zero = T(), U _noop = U()) {
    zero = _zero, noop = _noop;
    for (S = 1, H = 1; S < _S;) S *= 2, H++;
    value.resize(2 * S, zero);
    dirty.resize(2 * S, false);
    prop.resize(2 * S, noop);
  }
  void set_leaves(vector<T>& leaves) {
    copy(leaves.begin(), leaves.end(), value.begin() + S);
    for (int i = S - 1; i > 0; i--) value[i] = value[2 * i] + value[2 * i + 1];
  }
  void apply(int i, const U& update) {
    value[i] = update(value[i]);
    if (i < S) {
      prop[i] = prop[i] + update;
      dirty[i] = true;
    }
  }
  void rebuild(int i) {
    for (int l = i / 2; l; l /= 2) {
      T combined = value[2 * l] + value[2 * l + 1];
      value[l] = prop[l](combined);
    }
  }
  void propagate(int i) {
    for (int h = H; h > 0; h--) {
      int l = i >> h;
      if (dirty[l]) {
        apply(2 * l, prop[l]);
        apply(2 * l + 1, prop[l]);
        prop[l] = noop;
        dirty[l] = false;
      }
    }
  }
  void upd(int i, int j, const U& update) {
    if (i > j) return;
    i += S, j += S;
    propagate(i), propagate(j);
    for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
      if ((l & 1) == 1) apply(l++, update);
      if ((r & 1) == 0) apply(r--, update);
    }
    rebuild(i), rebuild(j);
  }
  T query(int i, int j) {
    if (i > j) return zero;
    i += S, j += S;
    propagate(i), propagate(j);
    T res_left = zero, res_right = zero;
    for (; i <= j; i /= 2, j /= 2) {
      if ((i & 1) == 1) res_left = res_left + value[i++];
      if ((j & 1) == 0) res_right = value[j--] + res_right;
    }
    return res_left + res_right;
  }
};
struct Node {
  int min_value = N;
  int min_index = N;
  int cnt_removed = 0;
  int index = -1;
  Node operator+(const Node& right) const {
    Node res = right;
    res.cnt_removed += cnt_removed;
    if (min_value < right.min_value) {
      res.min_value = min_value;
      res.min_index = min_index;
    }
    if (res.index == -1) {
      res.index = index;
    }
    return res;
  }
};
struct Update {
  int add = 0;
  int cnt_removed = 0;
  Update(int add = 0, int cnt_removed = 0)
      : add(add), cnt_removed(cnt_removed) {}
  Update operator+(const Update& right) const {
    Update res = right;
    res.add += add;
    res.cnt_removed += cnt_removed;
    return res;
  }
  Node operator()(const Node& node) const {
    Node res = node;
    res.min_value += add;
    res.min_value = min(res.min_value, N);
    res.cnt_removed += cnt_removed;
    return res;
  }
};
vector<int> occ[N];
int res[N];
int arr[N];
struct Query {
  int l, r;
  int ind;
  bool operator<(const Query& other) const { return l < other.l; }
} queries[N];
SegmentTree<Node, Update> segment_tree;
int n;
void process(int l) {
  int ind = l;
  int val = segment_tree.query(ind, ind).min_value;
  while (val <= 0) {
    segment_tree.upd(ind, ind, Update(N, 1));
    segment_tree.upd(ind + 1, n - 1, Update(-1, 0));
    auto tmp = segment_tree.query(l, n - 1);
    val = tmp.min_value;
    ind = tmp.min_index;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int q;
  cin >> n >> q;
  segment_tree.init(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    arr[i] -= i + 1;
    arr[i] *= -1;
  }
  vector<Node> leaves(n);
  for (int i = 0; i < n; ++i) {
    leaves[i].index = i;
    leaves[i].min_index = leaves[i].index;
    if (arr[i] < 0) arr[i] = N;
    leaves[i].min_value = arr[i];
  }
  segment_tree.set_leaves(leaves);
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    queries[i].l = x;
    queries[i].r = n - y - 1;
    queries[i].ind = i;
  }
  sort(queries, queries + q);
  int next_ind = n - 1;
  for (int i = q - 1; i >= 0; --i) {
    auto& curr = queries[i];
    while (next_ind >= curr.l) {
      process(next_ind);
      --next_ind;
    }
    res[curr.ind] = segment_tree.query(curr.ind, curr.r).cnt_removed;
  }
  for (int i = 0; i < q; ++i) {
    cout << res[i] << '\n';
  }
  return 0;
}
