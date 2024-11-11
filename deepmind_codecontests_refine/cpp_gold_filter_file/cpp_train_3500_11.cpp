#include <bits/stdc++.h>
using namespace std;
void __print(long long x) { cerr << x; }
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
  long long f = 0;
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
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long maxx = -1e18, minn = 1e18;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++)
    cin >> a[i], maxx = max(maxx, a[i]), minn = min(minn, a[i]);
  if (k > 2) return cout << maxx, 0;
  if (k == 1) return cout << minn, 0;
  vector<long long> premin(n), suffmin(n);
  premin[0] = a[0];
  suffmin[n - 1] = a[n - 1];
  for (long long i = 1; i < n; i++) {
    premin[i] = min(premin[i - 1], a[i]);
  }
  for (long long i = n - 2; i >= 0; i--) {
    suffmin[i] = min(suffmin[i + 1], a[i]);
  }
  maxx = -1e18;
  for (long long i = 0; i < n - 1; i++) {
    long long h = max(premin[i], suffmin[i + 1]);
    maxx = max(h, maxx);
  }
  cout << maxx;
  return 0;
}
