#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool uax(T &x, T y) {
  return (y > x) ? x = y, true : false;
}
template <typename T>
inline bool uin(T &x, T y) {
  return (y < x) ? x = y, true : false;
}
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = false;
  string r = "{";
  for (auto x : v) {
    if (f) r += ", ";
    r += to_string(x);
    f = true;
  }
  return r += "}";
}
template <typename A>
string to_string(vector<vector<A>> v) {
  string r;
  for (auto x : v) r += "\n" + to_string(x);
  return r;
}
void err(istream_iterator<string>) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << to_string(a) << "; ";
  err(++it, args...);
}
template <typename T>
void kek(T ans) {
  cout << ans << endl;
  exit(0);
}
int const MOD = 1e9 + 7;
long long const INF = 1e18 + 42;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long A, cf, cm, m;
  cin >> n >> A >> cf >> cm >> m;
  vector<long long> a(n);
  for (long long &x : a) cin >> x;
  vector<int> ids(n);
  iota(begin(ids), end(ids), 0);
  sort(begin(ids), end(ids), [&](int i, int j) { return a[i] > a[j]; });
  vector<long long> b(n);
  for (int i = n - 2; i >= 0; --i) {
    b[i] = b[i + 1] + (a[ids[i]] - a[ids[i + 1]]) * (n - i - 1);
  }
  long long ans = 0, opti = -1, optm = -1;
  long long sum = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    if (sum > m) break;
    long long cost = m - sum;
    while (j < i or b[j] > cost) ++j;
    long long lim = (cost - b[j]) / (n - j) + a[ids[j]];
    if (uax(ans, cf * i + cm * lim)) opti = i, optm = lim;
    sum += A - a[ids[i]];
  }
  if (sum <= m) {
    ans = cf * n + cm * A, opti = n, optm = A;
  }
  cout << ans << '\n';
  for (int i : ids) {
    if (opti > 0) {
      opti--;
      a[i] = A;
    } else {
      a[i] = max(optm, a[i]);
    }
  }
  for (long long &x : a) cout << x << ' ';
  cout << '\n';
}
