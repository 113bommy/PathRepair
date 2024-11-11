#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 20;
int n, m, k, a[MXN];
struct node {
  long long ssize, psize, val;
  vector<pair<int, int>> pref, suf;
  vector<int> sufpref;
  bool empty;
  node(bool isempty) {
    psize = ssize = val = 0;
    empty = isempty;
  }
  node(int x) {
    psize = ssize = 1;
    val = (x >= k);
    pref.push_back({x, 1});
    suf = pref;
    sufpref = {1};
    empty = 0;
  }
  node operator+(node nd) {
    if (empty) return nd;
    if (nd.empty) {
      node res(empty);
      res.pref = pref;
      res.suf = suf;
      res.sufpref = sufpref;
      res.ssize = ssize;
      res.psize = psize;
      res.val = val;
      return res;
    }
    int psz = 0, ssz = 0;
    long long ans = 0;
    vector<pair<int, int>> p, s;
    vector<int> preef;
    p = pref;
    s = nd.suf;
    reverse(s.begin(), s.end());
    for (int i = ssize - 1; i >= 0; i--) {
      int f = suf[i].first | nd.suf[0].first;
      if (f != s.back().first) {
        s.push_back({f, suf[i].second});
      } else {
        s.back().second += suf[i].second;
      }
    }
    reverse(s.begin(), s.end());
    ssz = s.size();
    preef.push_back(s[0].second);
    for (int i = 1; i < ssz; i++) {
      preef.push_back(preef.back() + s[i].second);
    }
    for (int i = 0; i < nd.psize; i++) {
      int f = nd.pref[i].first | pref.back().first;
      if (f != p.back().first) {
        p.push_back({f, nd.pref[i].second});
      } else {
        p.back().second += nd.pref[i].second;
      }
    }
    psz = p.size();
    ans = 0LL + val + nd.val;
    int ptr1 = ssize - 1, ptr2 = nd.psize - 1;
    while (ptr1 >= 0 && ptr2 >= 0) {
      if ((suf[ptr1].first | nd.pref[ptr2].first) >= k) {
        ans += 1LL * sufpref[ptr1] * nd.pref[ptr2].second;
      }
      if ((suf[ptr1].first | nd.pref[ptr2].first) >= k) {
        ptr2--;
        continue;
      }
      if ((suf[ptr1].first | nd.pref[ptr2].first) < k) {
        ptr1--;
        continue;
      }
    }
    node res(false);
    res.pref = p;
    res.suf = s;
    res.sufpref = preef;
    res.psize = psz;
    res.ssize = ssz;
    res.val = ans;
    return res;
  }
};
struct seg_tree {
  int size;
  vector<node> v;
  seg_tree() { size = 0; }
  void init() {
    size = 1;
    while (size < n) size <<= 1;
    v.assign(2 * size, node(true));
  }
  void build(int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < n) {
        v[x] = node(a[lx]);
      } else {
        v[x] = node(true);
      }
      return;
    }
    int m = (lx + rx) / 2;
    build(2 * x + 1, lx, m);
    build(2 * x + 2, m, rx);
    v[x] = v[2 * x + 1] + v[2 * x + 2];
  }
  void build() { build(0, 0, size); }
  void set(int x, int lx, int rx, int i, int t) {
    if (rx - lx == 1) {
      v[x] = node(t);
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m)
      set(2 * x + 1, lx, m, i, t);
    else
      set(2 * x + 2, m, rx, i, t);
    v[x] = v[2 * x + 1] + v[2 * x + 2];
  }
  void set(int i, int t) { set(0, 0, size, i, t); }
  node get(int x, int lx, int rx, int l, int r) {
    if (lx >= l && rx <= r) {
      return v[x];
    }
    if (lx >= r || rx <= l) {
      return node(true);
    }
    int m = (lx + rx) / 2;
    node p = get(2 * x + 1, lx, m, l, r);
    node q = get(2 * x + 2, m, rx, l, r);
    return p + q;
  }
  long long get(int l, int r) { return get(0, 0, size, l, r).val; }
} seg;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  seg.init();
  seg.build();
  for (int i = 0; i < m; i++) {
    int type, x, y;
    cin >> type >> x >> y;
    x--;
    if (type == 2) {
      cout << seg.get(x, y) << "\n";
    } else {
      seg.set(x, y);
    }
  }
}
