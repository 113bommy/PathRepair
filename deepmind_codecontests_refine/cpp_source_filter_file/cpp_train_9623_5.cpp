#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
template <class T>
void selfmax(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void selfmin(T& a, const T& b) {
  a = min(a, b);
}
template <typename T>
inline T gcd(T a, T b) {
  while (b != 0) swap(b, a %= b);
  return a;
}
void __print(long long x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  long long f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class A>
void read(vector<pair<A, A> >& x) {
  for (auto& a : x) read(a.first, a.second);
}
template <typename... T>
void read(vector<long long>& a) {
  long long n = a.size();
  for (long long i = 0; i < n; i++) cin >> a[i];
}
template <class A>
void print(vector<A>& a) {
  for (auto& x : a) cout << x << " ";
  cout << endl;
}
long long prod(long long a, long long b, long long m) {
  long long res = 0;
  while (b) {
    if (b & 1) res = (res + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
}
long long power(long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (b & 1) res = prod(res, a, m);
    a = prod(a, a, m);
    b >>= 1;
  }
  return res;
}
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
const long long MOD = 1e9 + 7;
const long long INF = 1000000000;
const long long BIGINF = 1e12;
void solve() {
  long long n;
  read(n);
  vector<long long> p(n);
  read(p);
  vector<long long> xr(n + 1);
  xr[0] = 0;
  for (long long i = 1; i <= n; i++) {
    xr[i] = xr[i - 1] ^ i;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long cnt = (n / i);
    if (cnt % 2) ans ^= xr[i];
    long long rem = n % i;
    ans ^= xr[rem];
  }
  for (long long i = 0; i < n; i++) {
    ans ^= p[i];
  }
  cout << ans << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  for (long long tt = 0; tt < t; tt++) {
    solve();
  }
}
