#include <bits/stdc++.h>
using namespace std;
template <int MAXN>
struct segtree_lazy {
  struct updater {
    int x;
    updater(int x = 0) : x(x) {}
    updater& operator+=(const updater& other) {
      x = other.x;
      return *this;
    }
    operator bool() const { return x != 0; }
  };
  struct node_t {
    int x;
    node_t(int x = 0) : x(x) {}
    node_t& operator+=(const node_t& other) {
      x += other.x;
      return *this;
    }
    node_t& operator+=(const updater& other) {
      x = other.x;
      return *this;
    }
    node_t operator+(const node_t& other) const {
      node_t tmp = *this;
      tmp += other;
      return tmp;
    }
  };
  node_t a[2 * MAXN];
  updater b[2 * MAXN];
  void init() {
    for (int i = 1; i <= MAXN; i++) {
      a[i + MAXN - 1] = node_t();
    }
    for (int i = MAXN - 1; i > 0; i--) {
      a[i] = a[2 * i] + a[2 * i + 1];
    }
  }
  void push(int i) {
    if (b[i]) {
      a[i] += b[i];
      if (i < MAXN) {
        b[2 * i] += b[i];
        b[2 * i + 1] += b[i];
      }
      b[i] = updater();
    }
  }
  node_t get(int l, int r, int node = 1, int nl = 1, int nr = MAXN) {
    push(node);
    if (r < nl || nr < l) {
      return node_t();
    }
    if (l <= nl && nr <= r) {
      return a[node];
    }
    int nm = (nl + nr) >> 1;
    return get(l, r, 2 * node, nl, nm) + get(l, r, 2 * node + 1, nm + 1, nr);
  }
  void update(int l, int r, updater val, int node = 1, int nl = 1,
              int nr = MAXN) {
    push(node);
    if (r < nl || nr < l) {
      return;
    }
    if (l <= nl && nr <= r) {
      b[node] += val;
      push(node);
      return;
    }
    int nm = (nl + nr) >> 1;
    update(l, r, val, 2 * node, nl, nm);
    update(l, r, val, 2 * node + 1, nm + 1, nr);
    a[node] = a[2 * node] + a[2 * node + 1];
  }
};
segtree_lazy<131072 * 16> drvo;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  drvo.init();
  int n, q;
  cin >> n >> q;
  vector<int> a(n), l(q + 1, INT32_MAX), r(q + 1, -1);
  int maxi = -1, c = 0;
  for (auto& i : a) {
    cin >> i;
    maxi = max(maxi, i);
    l[i] = min(l[i], c);
    r[i] = max(r[i], c);
    ++c;
  }
  if (maxi > q) return cout << "NO\n", 0;
  bool ok;
  if (maxi == q)
    ok = 1;
  else
    ok = 0;
  int free = -1;
  for (int i = 0; i < n; ++i) {
    if (!a[i]) {
      free = i;
      break;
    }
  }
  l[1] = 0;
  r[1] = n - 1;
  for (int i = 1; i <= q; ++i) {
    if (l[i] == INT32_MAX) continue;
    drvo.update(l[i] + 1, r[i] + 1, i);
  }
  vector<int> b(n, 1);
  for (int i = 0; i < n; ++i) {
    b[i] = drvo.get(i + 1, i + 1).x;
  }
  if (!ok && free == -1) return cout << "NO\n", 0;
  if (!ok) {
    b[free] = q;
  }
  for (int i = 0; i < n; ++i) {
    if (!a[i]) continue;
    if (a[i] < b[i]) {
      return cout << "NO\n", 0;
    }
  }
  if (*max_element(b.begin(), b.end()) != q) return cout << "NO\n", 0;
  cout << "YES\n";
  for (auto& i : b) cout << i << ' ';
  cout << '\n';
}
