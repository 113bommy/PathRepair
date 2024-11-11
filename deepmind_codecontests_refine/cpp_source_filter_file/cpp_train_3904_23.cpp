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
long long binpow(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long binpowmod(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long mod_inverse(long long n, long long p) {
  return binpowmod(n, p - 2, p);
}
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
unsigned int onesComplement(unsigned int n) {
  int number_of_bits = floor(log2(n)) + 1;
  return ((1 << number_of_bits) - 1) ^ n;
}
bool comp1(pair<int, int> x, pair<int, int> y) { return x.second < y.second; }
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    int x_mov = min(x - 1, n - x);
    int y_mov = min(y - 1, m - y);
    int mov = min(x_mov, y_mov);
    if (mov < 3) {
      cout << "YES";
      return;
    }
  }
  cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(15);
  solve();
}
