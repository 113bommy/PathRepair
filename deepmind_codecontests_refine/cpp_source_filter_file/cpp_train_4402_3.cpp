#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using vv = vector<vector<T>>;
template <class T>
inline bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const int INF = 1002003004;
const ll LINF = 1002003004005006007ll;
struct preprocess {
  preprocess() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} ____;
template <typename T>
struct BinaryIndexedTree {
  int sz;
  vector<T> data;
  BinaryIndexedTree(int sz) : sz(sz), data(sz + 1) {}
  T sum(int k) {
    T res = 0;
    for (k++; k > 0; k -= k & -k) res += data[k];
    return res;
  }
  T sum(int l, int r) { return sum(r - 1) - sum(l - 1); }
  void add(int k, T x) {
    for (k++; k <= sz; k += k & -k) data[k] += x;
  }
  int lower_bound(T w) {
    if (w <= 0) return 0;
    int x = 0;
    int k = 1;
    while ((k << 1) <= sz) k <<= 1;
    for (; k > 0; k >>= 1) {
      if (x + k <= sz && data[x + k] < w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }
};
int main() {
  int n;
  cin >> n;
  vll a(n);
  for (int i = 0; i < (int)(n); i++) cin >> a[i];
  vv<int> sets;
  vector<int> init(n);
  iota((init).begin(), (init).end(), 0);
  sets.emplace_back(init);
  ll ans = 0;
  ll inv = 0;
  for (int bi = (int)(34) - 1; bi >= 0; bi--) {
    ll val = 1ll << bi;
    vv<int> nxt;
    int now = 0;
    int nowinv = 0;
    for (int i = 0; i < (int)(sets.size()); i++) {
      vi &v = sets[i];
      vi b;
      for (int j = 0; j < (int)(v.size()); j++) {
        if (a[v[j]] & val) {
          b.emplace_back(1);
        } else {
          b.emplace_back(0);
        }
      }
      int ones = 0;
      for (int j = 0; j < (int)(b.size()); j++) {
        if (b[j]) {
          ones++;
        } else {
          now += ones;
        }
      }
      ones = 0;
      for (int j = 0; j < (int)(b.size()); j++) {
        if (!b[j]) {
          ones++;
        } else {
          nowinv += ones;
        }
      }
      vi nxt1, nxt2;
      for (int j = 0; j < (int)(b.size()); j++) {
        if (b[j]) {
          nxt1.emplace_back(v[j]);
        } else {
          nxt2.emplace_back(v[j]);
        }
      }
      if (!nxt1.empty()) nxt.emplace_back(nxt1);
      if (!nxt2.empty()) nxt.emplace_back(nxt2);
    }
    if (now > nowinv) {
      ans |= val;
    }
    inv += min(now, nowinv);
    sets = nxt;
  }
  cout << inv << ' ' << ans << '\n';
}
