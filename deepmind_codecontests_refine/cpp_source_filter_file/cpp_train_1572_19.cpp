#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long mod = 1e9 + 7;
const long long N = 4e5 + 5;
long long i, j;
void solve() {
  long long n;
  cin >> n;
  ;
  vector<long long> a(2 * n);
  for (auto &i : a) cin >> i;
  ;
  sort(a.begin(), a.end());
  long long ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
  for (i = 1; i <= n / 2; i++) {
    ans = min(ans, (a[2 * n - 1] - a[0]) * (a[i + n / 2 - 1] - a[i]));
  }
  cout << ans << "\n";
  ;
}
int32_t main() {
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}
