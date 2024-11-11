#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
template <typename T>
void setmax(T& x, T y) {
  x = max(x, y);
}
template <typename T>
void setmin(T& x, T y) {
  x = min(x, y);
}
struct segtree {
  int size;
  vector<long long> t;
  void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    t.assign(2 * size - 1, 0);
  }
  void set(int i, long long v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      t[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }
    t[x] = t[2 * x + 1] + t[2 * x + 2];
  }
  void set(int i, long long v) { set(i, v, 0, 0, size); }
  long long sum(int l, int r, int x, int lx, int rx) {
    if (l >= rx || r <= lx) {
      return 0;
    }
    if (lx >= l && rx <= r) {
      return t[x];
    }
    int m = (lx + rx) / 2;
    long long s1 = sum(l, r, 2 * x + 1, lx, m);
    long long s2 = sum(l, r, 2 * x + 2, m, rx);
    return s1 + s2;
  }
  long long sum(int l, int r) { return sum(l, r, 0, 0, size); }
};
void solve() {
  int n;
  segtree sg;
  cin >> n;
  sg.init(n);
  string s;
  cin >> s;
  string t = s;
  reverse(t.begin(), t.end());
  map<char, set<int>> m;
  for (int i = 0; i < int(n); i++) {
    m[s[i]].insert(i);
  }
  long long ans = 0;
  for (int i = 0; i < int(n); i++) {
    char cur = t[i];
    int index = *(m[cur].begin());
    m[cur].erase(index);
    int shift = sg.sum(index, n);
    sg.set(index, 1);
    ans += index + shift - i;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 0; i < int(t); i++) {
    solve();
  }
}
