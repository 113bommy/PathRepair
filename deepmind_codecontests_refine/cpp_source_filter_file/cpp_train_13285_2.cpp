#include <bits/stdc++.h>
using namespace std;
struct node {
  int sz, l, r, best;
  node() {
    sz = -1;
    l = r = -1;
    best = -1;
  }
  node(int a) { *this = node(1, 0, 0, 0); }
  node(int a, int b, int c, int d) {
    sz = a;
    l = b;
    r = c;
    best = d;
  }
};
node operator+(node a, node b) {
  if (a.sz == -1) return b;
  if (b.sz == -1) return a;
  node ans;
  if (a.l == a.sz && b.r == b.sz)
    ans = node(a.sz + b.sz, a.sz + b.sz, a.sz + b.sz, a.sz + b.sz);
  else if (a.l == a.sz) {
    ans = node(a.sz + b.sz, a.sz + b.l, b.r, max({a.best, b.best, a.sz + b.l}));
  } else if (b.r == b.sz) {
    ans = node(a.sz + b.sz, a.l, a.r + b.sz, max({a.best, b.best, a.r + b.sz}));
  } else {
    ans = node(a.sz + b.sz, a.l, b.r, max({a.best, b.best, a.r + b.l}));
  }
  return ans;
}
template <typename T>
class segment_tree {
 private:
  static const int default_size = 100001;
  int my_size;
  vector<T> tree;
  void build(vector<T>& data, int id, int l, int r) {
    if (l == r)
      tree[id] = data[l];
    else {
      int mid = (l + r) >> 1;
      build(data, id << id, l, mid);
      build(data, id << 1 | 1, mid + 1, r);
      tree[id] = tree[id << 1] + tree[id << 1 | 1];
    }
  }
  void update(int id, int l, int r, int pos, T v) {
    if (l == r)
      tree[id] = v;
    else {
      int mid = (l + r) >> 1;
      if (pos <= mid)
        update(id << 1, l, mid, pos, v);
      else
        update(id << 1 | 1, mid + 1, r, pos, v);
      tree[id] = tree[id << 1] + tree[id << 1 | 1];
    }
  }
  T query(int id, int l, int r, int x, int y) {
    if (l > y || r < x) return T();
    if (x <= l && r <= y) return tree[id];
    int mid = (l + r) >> 1;
    return query(id << 1, l, mid, x, y) + query(id << 1 | 1, mid + 1, r, x, y);
  }

 public:
  segment_tree() {}
  segment_tree(int size) {
    my_size = size;
    clear();
  }
  void clear() { tree.assign(my_size << 2, T(0)); }
  void build(vector<T>& data) {
    data.resize(my_size);
    build(data, 1, 0, my_size - 1);
  }
  void setPos(int pos, T value) { update(1, 0, my_size - 1, pos, value); }
  void update(int pos, T value) { setPos(pos, value); }
  T getPos(int pos) { return query(1, 0, my_size - 1, pos, pos); }
  void addToPos(int pos, T value) { setPos(pos, getPos(pos) + value); }
  T getInterval(int l, int r) { return query(1, 0, my_size - 1, l, r); }
  T query(int l, int r) { return getInterval(l, r); }
};
struct histogram_solver {
  vector<int> dp;
  vector<int> he;
  static long long solve(vector<int> values) {
    stack<int> s;
    int i = 0;
    long long ans = 0;
    while (i < values.size()) {
      if (s.empty() || values[s.top()] <= values[i])
        s.push(i++);
      else {
        int tp = s.top();
        s.pop();
        long long area = 1ll * values[tp] * (s.empty() ? i + 1 : i - s.top());
        ans = max(ans, area);
      }
    }
    while (!s.empty()) {
      int tp = s.top();
      s.pop();
      long long area = 1ll * values[tp] * (s.empty() ? i + 1 : i - s.top());
      ans = max(ans, area);
    }
    return ans;
  }
};
const int maxn = 100100;
const int magic = 50;
segment_tree<node> trees[magic];
struct max_t {
  long long value;
  max_t() { value = -(1ll << 50); }
  max_t(long long v) { value = v; }
  max_t operator+(const max_t& other) { return max_t(max(value, other.value)); }
};
segment_tree<max_t> library;
string arr[maxn];
char str[maxn];
int lcp[maxn];
int solve(set<int>& B, int l, int r) {
  int last = -1;
  vector<int> to_apply;
  for (int v : B) {
    if (v >= l && v <= r) {
      if (last != -1 && last + 1 != v) to_apply.push_back(0);
      to_apply.push_back(lcp[v]);
      last = v;
    }
  }
  histogram_solver lol;
  return lol.solve(to_apply);
}
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int e = 0; e < n; e++) {
    scanf("%s", str);
    arr[e] = str;
  }
  for (int e = 0; e < n - 1; e++) {
    while (lcp[e] < arr[e].size() && lcp[e] < arr[e + 1].size() &&
           arr[e][lcp[e]] == arr[e + 1][lcp[e]])
      lcp[e]++;
  }
  for (int e = 0; e < magic; e++) trees[e] = segment_tree<node>(n);
  library = segment_tree<max_t>(n);
  set<int> big;
  for (int e = 0; e < n - 1; e++) {
    for (int f = 0; f <= min(lcp[e], magic - 1); f++)
      trees[f].update(e, node(1, 1, 1, 1));
    if (lcp[e] >= magic) big.insert(e);
  }
  for (int e = 0; e < n; e++) library.update(e, arr[e].size());
  cerr << "build " << clock() << " ms" << endl;
  for (int e = 0; e < q; e++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int l, r;
      scanf("%d %d", &l, &r);
      l--;
      r--;
      int ans = library.query(l, r).value;
      if (l < r) {
        for (int f = 0; f < magic; f++) {
          int sz = trees[f].query(l, r - 1).best;
          if (sz == 0) sz--;
          ans = max(ans, (sz + 1) * f);
        }
        ans = max(ans, solve(big, l, r));
      }
      printf("%d\n", ans);
    } else {
      int l;
      scanf("%d %s", &l, str);
      l--;
      arr[l] = str;
      library.update(l, arr[l].size());
      if (l) {
        if (lcp[l - 1] >= magic) big.erase(l - 1);
        for (int f = 0; f <= min(magic - 1, lcp[l - 1]); f++)
          trees[f].update(l - 1, node(0));
        lcp[l - 1] = 0;
        while (lcp[l - 1] < arr[l - 1].size() && lcp[l - 1] < arr[l].size() &&
               arr[l - 1][lcp[l - 1]] == arr[l][lcp[l - 1]])
          lcp[l - 1]++;
        for (int f = 0; f <= min(magic - 1, lcp[l - 1]); f++)
          trees[f].update(l - 1, node(1, 1, 1, 1));
        if (lcp[l - 1] >= magic) big.insert(l - 1);
      }
      if (l < n - 1) {
        if (lcp[l] >= magic) big.erase(l);
        for (int f = 0; f <= min(magic - 1, lcp[l]); f++)
          trees[f].update(l, node(0));
        lcp[l] = 0;
        while (lcp[l] < arr[l].size() && lcp[l] < arr[l + 1].size() &&
               arr[l][lcp[l]] == arr[l + 1][lcp[l]])
          lcp[l]++;
        for (int f = 0; f <= min(magic - 1, lcp[l]); f++)
          trees[f].update(l, node(1, 1, 1, 1));
        if (lcp[l] >= magic) big.insert(l);
      }
    }
  }
  cerr << "over " << clock() << " ms" << endl;
  return 0;
}
