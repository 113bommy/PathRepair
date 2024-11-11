#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
inline ll popcnt(ull a) { return __builtin_popcountll(a); }
ll intpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b /= 2;
  }
  return ans;
}
ll intpow(ll a, ll b, ll m) {
  ll ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= m;
    (a *= a) %= m;
    b /= 2;
  }
  return ans;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
void scan(T& a) {
  cin >> a;
}
template <class T>
void scan(vector<T>& a) {
  for (auto&& i : a) scan(i);
}
void in() {}
template <class Head, class... Tail>
void in(Head& head, Tail&... tail) {
  scan(head);
  in(tail...);
}
void print() { cout << ' '; }
template <class T>
void print(const T& a) {
  cout << a;
}
template <class T>
void print(const vector<T>& a) {
  if (a.empty()) return;
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    cout << ' ';
    print(*i);
  }
}
int out() {
  cout << '\n';
  return 0;
}
template <class T>
int out(const T& t) {
  print(t);
  cout << '\n';
  return 0;
}
template <class Head, class... Tail>
int out(const Head& head, const Tail&... tail) {
  print(head);
  cout << ' ';
  out(tail...);
  return 0;
}
void solve() {
  long long n;
  in(n);
  vector<vector<long long>> r(n, vector<long long>(5));
  in(r);
  long long id = 0;
  for (long long i = 1; i < n; ++i) {
    long long cnt = 0;
    for (long long j = 0; j < 5; ++j) {
      if (r[id][j] < r[i][j]) ++cnt;
    }
    if (cnt >= 3) {
      id = i;
    }
  }
  for (long long i = 0; i < n; ++i) {
    if (id == i) continue;
    long long cnt = 0;
    for (long long j = 0; j < 5; ++j) {
      if (r[id][j] < r[i][j]) ++cnt;
    }
    if (cnt < 3) {
      out(-1);
      return;
    }
  }
  out(id + 1);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  in(t);
  for (long long i = 0; i < t; ++i) solve();
  return 0;
}
