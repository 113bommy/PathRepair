#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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
const int mod = 1e9 + 7;
long long binpow(long long num, long long pow);
long long binpowMod(long long num, long long pow);
inline long long mul(long long a, long long b) { return (a * 1ll * b) % mod; }
inline long long add(long long a, long long b) { return (a + 0ll + b) % mod; }
inline long long sub(long long a, long long b) {
  return ((a + 0ll - b) % mod + mod) % mod;
}
inline void solve() {
  int n;
  cin >> n;
  cout << n << '\n';
  for (int i = (int)1; i < (int)n + 1; i++) cout << i << ' ';
  cout << '\n';
}
int main() {
  auto start = high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << duration.count() << " microseconds\n";
  return 0;
}
long long binpow(long long num, long long pow) {
  if (pow == 0) return 1;
  long long val = binpow(num, pow / 2);
  val *= val;
  if (pow & 1) val *= num;
  return val;
}
long long binpowMod(long long num, long long pow) {
  if (pow == 0) return 1;
  long long val = binpow(num, pow / 2);
  val = mul(val, val);
  if (pow & 1) val = mul(num, val);
  return val;
}
