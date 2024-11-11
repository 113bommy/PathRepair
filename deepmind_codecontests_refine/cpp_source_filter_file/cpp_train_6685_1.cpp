#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Universe {
  vector<T> o;
  void push(const T &x) { o.push_back(x); }
  int build() {
    sort(o.begin(), o.end());
    o.resize(unique(o.begin(), o.end()) - o.begin());
    return o.size();
  }
  int find(const T &x) {
    auto it = lower_bound(o.begin(), o.end(), x);
    return (it == o.end() || x < *it ? -1 : it - o.begin() + 1);
  }
  T &operator[](int i) { return o[i - 1]; }
};
struct Node {
  int freq;
  bool left, right;
  Node(bool b) { freq = left = right = b; }
  Node operator+(const Node &o) {
    Node r(0);
    r.freq = freq + o.freq - (right & o.left);
    r.left = left;
    r.right = o.right;
    return r;
  }
} NIL(0);
template <class T>
struct SegTree {
  vector<Node> tree;
  SegTree(int n) : tree(n << 2, NIL) {}
  void update(int i, int l, int r, int p, T x) {
    if (p > r || p < l) {
      return;
    } else if (l == r) {
      tree[i] = Node(x);
    } else {
      int m = (l + r) >> 1;
      int fe = i << 1, fd = (i << 1) + 1;
      update(fe, l, m, p, x);
      update(fd, m + 1, r, p, x);
      tree[i] = tree[fe] + tree[fd];
    }
  }
  Node query(int i, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) {
      return NIL;
    } else if (l <= ql && qr <= r) {
      return tree[i];
    } else {
      int m = (l + r) >> 1;
      int fe = i << 1, fd = (i << 1) + 1;
      return query(fe, l, m, ql, qr) + query(fd, m + 1, r, ql, qr);
    }
  }
};
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > in;
    Universe<int> cc;
    for (int i = 0; i < n; i++) {
      int l, r;
      scanf("%d %d", &l, &r);
      cc.push(l);
      cc.push(r);
      in.push_back({l, r});
    }
    int m = (cc.build() << 1) + 5;
    vector<int> open(m), close(m);
    for (int i = 0; i < n; i++) {
      open[cc.find(in[i].first) << 1]++;
      close[cc.find(in[i].second) << 1]++;
    }
    vector<int> freq(m);
    for (int i = 0, total = 0; i < m; i++) {
      total += open[i];
      freq[i] = total;
      total -= close[i];
    }
    vector<int> left(m);
    for (int i = 1; i < m; i++) {
      if (freq[i] == 1) {
        left[i] = left[i - 1];
      } else {
        left[i] = freq[i];
      }
    }
    vector<int> right(m);
    for (int i = m - 2; i >= 0; i--) {
      if (freq[i] == 1) {
        right[i] = right[i + 1];
      } else {
        right[i] = freq[i];
      }
    }
    vector<bool> loose(m);
    int all = 0;
    SegTree<bool> t(m);
    for (int i = 1; i < m; i++) {
      if (freq[i] == 1) {
        if (left[i] == 0 && right[i] == 0) {
          loose[i] = true;
        } else if (left[i] > 0 && right[i] > 0) {
          t.update(1, 0, m - 1, i, true);
        }
      } else if (freq[i] == 0 && freq[i - 1] > 0) {
        all++;
      }
    }
    int global = 0;
    for (int i = 0; i < n; i++) {
      int ql = cc.find(in[i].first) << 1;
      int qr = cc.find(in[i].second) << 1;
      int add = (loose[ql] ? -1 : t.query(1, 0, m - 1, ql, qr).freq);
      global = max(global, all + add);
    }
    printf("%d\n", global);
  }
}
