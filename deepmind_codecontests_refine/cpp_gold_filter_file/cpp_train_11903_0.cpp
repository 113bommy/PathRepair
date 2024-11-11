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
const long long INF = LLONG_MAX;
const long long mod = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long k;
  cin >> k;
  string second;
  cin >> second;
  long long n = second.length();
  long long prefix_sum = 0;
  vector<long long> cnt(n + 5);
  cnt[0] = 1;
  for (long long i = 0; i < n; i++) {
    prefix_sum += second[i] - '0';
    cnt[prefix_sum]++;
  }
  long long ans = 0;
  for (long long i = k; i <= prefix_sum; i++) {
    if (!k)
      ans += (cnt[i] - 1) * (cnt[i]) / 2;
    else {
      ans += cnt[i] * cnt[i - k];
    }
  }
  cout << ans << "\n";
  return 0;
}
