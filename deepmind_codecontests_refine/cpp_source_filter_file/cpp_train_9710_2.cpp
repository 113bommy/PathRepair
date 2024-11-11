#include <bits/stdc++.h>
using namespace std;
void __print(long long x) { cerr << x; }
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
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long t;
  t = 1;
  ;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    std::vector<pair<long long, long long>> a(n), c(m);
    vector<long long> v(1e6 + 7, -1);
    for (long long i = 0; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      a[i] = {x, y};
    }
    for (long long i = 0; i < m; i++) {
      long long x, y;
      cin >> x >> y;
      c[i] = {x, y};
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        long long dx = c[i].first - a[i].first;
        long long dy = c[i].second - a[i].second;
        if (dx < 0 || dy < 0) continue;
        v[dx] = max(v[dx], dy + 1);
      }
    }
    long long ans = 1e9;
    for (long long i = 1e6 + 2; i >= 0; i--) {
      v[i] = max(v[i], v[i + 1]);
      ans = min(ans, i + v[i] + 1);
    }
    cout << ans;
  }
}
