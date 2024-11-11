#include <bits/stdc++.h>
using namespace std;
void rset();
void init_test();
void solve();
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(20);
  init_test();
  return 0;
}
template <typename T>
void chmin(T& a, T b) {
  if (a > b) a = b;
}
template <typename T>
void chmax(T& a, T b) {
  if (a < b) a = b;
}
template <typename T>
void MACRO_rdv2_Init(int n, T& t) {
  t.resize(n);
}
template <typename First, typename... Rest>
void MACRO_rdv2_Init(int n, First& first, Rest&... rest) {
  first.resize(n);
  MACRO_rdv2_Init(n, rest...);
}
template <typename T>
void MACRO_rdv2_Scan(int p, T& t) {
  std::cin >> t[p];
}
template <typename First, typename... Rest>
void MACRO_rdv2_Scan(int p, First& first, Rest&... rest) {
  std::cin >> first[p];
  MACRO_rdv2_Scan(p, rest...);
}
template <typename T>
void wrv(const vector<T>& v) {
  for (int(__ii) = (0); (__ii) < (((int)v.size())); ++(__ii)) {
    if (__ii) cout << ' ';
    cout << v[__ii];
  }
  cout << '\n';
}
template <typename T>
void wrm(const vector<vector<T>>& v) {
  for (int(__ii) = (0); (__ii) < (((int)v.size())); ++(__ii)) {
    for (int(__jj) = (0); (__jj) < (v[__ii].size()); ++(__jj)) {
      if (__jj) cout << ' ';
      cout << v[__ii][__jj];
    }
    cout << '\n';
  }
}
template <typename T>
void sc(T& x) {
  cin >> x;
}
template <typename Head, typename... Tail>
void sc(Head& head, Tail&... tail) {
  cin >> head;
  sc(tail...);
}
template <typename T>
void wr(const T& x) {
  cout << x << '\n';
}
template <typename Head, typename... Tail>
void wr(const Head& head, const Tail&... tail) {
  cout << head << ' ';
  wr(tail...);
}
template <typename T>
void wrf(const T& x) {
  cout << x << endl;
}
template <typename Head, typename... Tail>
void wrf(const Head& head, const Tail&... tail) {
  cout << head << ' ';
  wrf(tail...);
}
template <typename T>
void debug_out(const T& x) {
  cerr << x << '\n';
}
template <typename Head, typename... Tail>
void debug_out(const Head& head, const Tail&... tail) {
  cerr << head << ' ';
  debug_out(tail...);
}
template <typename... T>
void err(const T&... cod) {
  wr(cod...);
  exit(0);
}
void solve() {
  long long n, k;
  sc(n, k);
  if (__builtin_popcountll(n) > k) err("No");
  wr("Yes");
  multiset<int> s;
  map<int, int> cnt;
  for (int(i) = (0); (i) < (62); ++(i))
    if ((n >> i) & 1) {
      s.insert(i);
      ++cnt[i];
    }
  k -= ((int)s.size());
  while (true) {
    int p = *prev(s.end());
    if (k >= cnt[p]) {
      k -= cnt[p];
      for (int(i) = (0); (i) < (2 * cnt[p]); ++(i)) s.insert(p - 1);
      cnt[p - 1] += 2 * cnt[p];
      s.erase(p);
      cnt.erase(p);
    } else {
      break;
    }
  }
  while (k > 0) {
    int p = *s.begin();
    s.erase(s.begin());
    s.insert(p - 1);
    s.insert(p - 1);
    --k;
  }
  vector<int> a;
  for (long long x : s) a.push_back(x);
  sort(a.rbegin(), a.rend());
  wrv(a);
}
void init_test() {
  int qq = 1;
  while (qq--) solve();
}
