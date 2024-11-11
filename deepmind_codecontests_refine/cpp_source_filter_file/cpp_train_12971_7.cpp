#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<long long>;
using pii = pair<long long, long long>;
const long long DX[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0},
                DY[9] = {-1, 0, 1, 0, -1, 1, 1, -1, 0};
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto i = (begin(v)); i != (end(v)); ++i)
    os << *i << (i == end(v) - 1 ? "" : " ");
  return os;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto i = (begin(v)); i != (end(v)); ++i) is >> *i;
  return is;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
using heap = priority_queue<T, vector<T>, greater<T>>;
struct {
  template <typename T>
  operator T() {
    T x;
    cin >> x;
    return x;
  }
} IN;
struct before_main_function {
  before_main_function() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
  }
} before_main_function;
signed main() {
  long long n = IN;
  vector<long long> a(n);
  cin >> a;
  vector<vector<long long>> tree(n);
  map<long long, long long> cnt_a, cnt_b;
  for (long long i = 0, ilen = (long long)(n - 1); i < ilen; ++i) {
    long long p = IN;
    tree[p - 1].push_back(i + 1);
  }
  long long nim = 0;
  long long A = 0, B = 0;
  function<long long(long long)> dfs = [&](long long v) -> long long {
    long long ret = 0;
    for (auto &w : tree[v]) {
      ret = dfs(w);
    }
    ret ^= 1;
    if (ret) {
      cnt_b[a[v]]++;
      nim ^= a[v];
      B++;
    } else {
      cnt_a[a[v]]++;
      A++;
    }
    return ret;
  };
  dfs(0);
  long long ans = 0;
  for (auto &p : cnt_a) {
    long long v = p.first;
    long long c = p.second;
    ans += c * cnt_b[nim ^ v];
  }
  if (nim == 0) {
    ans = A * (A - 1) / 2 + B * (B - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
