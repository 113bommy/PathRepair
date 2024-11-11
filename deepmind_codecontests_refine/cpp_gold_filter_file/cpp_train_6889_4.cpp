#include <bits/stdc++.h>
using namespace std;
const int FASTIO = []() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return 0;
}();
template <typename T>
class seg_tree {
  int p = 1;
  function<T(T, T)> key;
  T begi;

 public:
  vector<T> t;
  seg_tree(vector<T>& v, function<T(T, T)> func, T a) : key(func), begi(a) {
    int n = v.size();
    while (p < n) p <<= 1;
    t.resize(2 * p, begi);
    for (int i = 0; i < n; i++) {
      t[i + p] = v[i];
    }
    for (int i = p - 1; i > 0; i--) {
      t[i] = key(t[i << 1], t[(i << 1) | 1]);
    }
  }
  seg_tree(int Size, function<T(T, T)> func, T& c) : key(func), begi(c) {
    while (p < Size) p <<= 1;
    t.resize(2 * p, begi);
  }
  T get(int l, int r) {
    T ans = begi;
    l += p;
    r += p;
    while (l <= r) {
      if (l & 1) ans = key(ans, t[l++]);
      if ((r & 1) == 0) ans = key(ans, t[r--]);
      l >>= 1;
      r >>= 1;
    }
    return ans;
  }
  void add(int i, T val) {
    i += p;
    t[i] += val;
    i >>= 1;
    while (i > 0) {
      t[i] = key(t[i << 1], t[(i << 1) | 1]);
      i >>= 1;
    }
  }
  void update(int i, T val) {
    i += p;
    t[i] = val;
    i >>= 1;
    while (i > 0) {
      t[i] = key(t[i << 1], t[(i << 1) | 1]);
      i >>= 1;
    }
  }
};
const int inf = 1e9 + 1;
signed main() {
  int n;
  cin >> n;
  int w;
  cin >> w;
  vector<long long> ans(w + 1, 0);
  while (n--) {
    int len;
    cin >> len;
    vector<int> a(len);
    for (int i = 0; i < len; i++) {
      cin >> a[i];
    }
    seg_tree<int> t(
        a, [](int a, int b) { return a < b ? b : a; }, -inf);
    for (int i = 0; i < w; i++) {
      int l = max(0, i - (w - len)), r = min(len - 1, i);
      int q = t.get(l, r);
      if (q < 0 && (i - len >= 0 || i + len < w)) q = 0;
      ans[i] += q;
      if (r - l + 1 == len) {
        i = w - len;
      }
      ans[i + 1] -= q;
    }
  }
  for (int i = 0; i < w; i++) {
    cout << ans[i] << ' ';
    ans[i + 1] += ans[i];
  }
}
