#include <bits/stdc++.h>
using namespace std;
struct segtree {
  vector<int> tag;
  int n, h;
  string name;
  segtree() {}
  segtree(int sz, string nn) {
    name = nn;
    h = 32 - __builtin_clz(sz);
    n = 1 << h;
    tag = vector<int>(n << 1, 0);
  }
  inline void apply(int x, int t) {
    if (t == (1 << 5)) {
      if (tag[x] == (1 << 3)) {
        tag[x] = (1 << 4);
      } else if (tag[x] == (1 << 4)) {
        tag[x] = (1 << 3);
      } else if (tag[x] == (1 << 5)) {
        tag[x] = 0;
      } else {
        tag[x] = (1 << 5);
      }
    } else {
      tag[x] = t;
    }
  }
  inline void pushh(int x) {
    if (tag[x]) {
      apply(x << 1, tag[x]);
      apply(x << 1 | 1, tag[x]);
      tag[x] = 0;
    }
  }
  inline void push(int x) {
    for (int l = h; l > 0; --l) {
      pushh(x >> l);
    }
  }
  inline void assign(int l, int r, int t) {
    if (l >= r) return;
    l += n, r += n;
    push(l);
    push(r - 1);
    for (; l < r; l /= 2, r /= 2) {
      if (l % 2) apply(l++, t);
      if (r % 2) apply(--r, t);
    }
  }
  inline int get(int x) {
    push(x + n);
    return tag[x + n];
  }
};
int n, q;
const int NMAX = 100100;
int pos[NMAX];
vector<int> at[NMAX];
vector<int> nat[NMAX];
int ans[NMAX];
int cc = 0;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x >= 0) {
      at[abs(x)].push_back(i);
    } else {
      nat[abs(x)].push_back(i);
    }
  }
  pos[100001] = n;
  pos[100002] = n;
  segtree po(n + 1, "po"), ne(n + 1, "ne");
  for (int i = 1; i <= 1e5; ++i) {
    pos[i] = cc;
    cc += at[i].size();
    po.assign(pos[i], pos[i] + at[i].size(), (1 << 3));
    ne.assign(pos[i], pos[i] + at[i].size(), (1 << 4));
    cc += nat[i].size();
    ne.assign(pos[i] + at[i].size(), pos[i] + at[i].size() + nat[i].size(),
              (1 << 3));
    po.assign(pos[i] + at[i].size(), pos[i] + at[i].size() + nat[i].size(),
              (1 << 4));
  }
  for (int i = 0; i < q; ++i) {
    string s;
    int b;
    cin >> s >> b;
    if (s[0] == '>') {
      if (b >= 0) {
        ne.assign(pos[b + 1], n, (1 << 3));
        po.assign(pos[b + 1], n, (1 << 4));
      } else if (b < 0) {
        ne.assign(0, pos[-b], (1 << 5));
        po.assign(0, pos[-b], (1 << 5));
        ne.assign(pos[-b], n, (1 << 3));
        po.assign(pos[-b], n, (1 << 4));
      }
    } else {
      if (b <= 0) {
        po.assign(pos[-b + 1], n, (1 << 3));
        ne.assign(pos[-b + 1], n, (1 << 4));
      } else if (b >= 1) {
        ne.assign(0, pos[b], (1 << 5));
        po.assign(0, pos[b], (1 << 5));
        po.assign(pos[b], n, (1 << 3));
        ne.assign(pos[b], n, (1 << 4));
      }
    }
  }
  int cp = 0;
  for (int i = 1; i <= 1e5; ++i) {
    for (auto& j : at[i]) {
      ans[j] = i;
      assert(ne.get(cp) != po.get(cp));
      if (ne.get(cp) == (1 << 3)) ans[j] *= -1;
    }
    cp += at[i].size();
    for (auto& j : nat[i]) {
      ans[j] = i;
      assert(ne.get(cp) != po.get(cp));
      if (ne.get(cp) == (1 << 3)) ans[j] *= -1;
    }
    cp += nat[i].size();
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
