#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
template <typename T, typename U>
struct par {
  T x;
  U y;
  par() : x(-1), y(-1) {}
  par(const T& x, const U& y) : x(x), y(y) {}
  bool operator<(const par& other) const {
    if (x == other.x) return y < other.y;
    return x < other.x;
  }
  bool operator==(const par& other) const {
    return x == other.x && y == other.y;
  }
  par operator-(const par& b) const { return {x - b.x, y - b.y}; }
};
template <class T>
inline vector<T> rv(long long n) {
  vector<T> v(n);
  for (long long i = 0; i < (n); i++) cin >> v[i];
  return v;
}
template <class T>
inline void pv(const vector<T>& v) {
  for (long long i = 0; i < (v.size()); i++) cout << v[i] << " ";
  cout << endl;
}
template <class T, class U>
inline void amax(T& a, const U& b) {
  if (a < b) a = b;
}
template <class T, class U>
inline void amin(T& a, const U& b) {
  if (a > b) a = b;
}
template <class T, class U>
inline T min(T& a, const U& b) {
  return a > b ? b : a;
}
template <class T, class U>
inline T max(T& a, const U& b) {
  return a < b ? b : a;
}
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
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
long long GCD(long long a, long long b) {
  if (a < b) swap(a, b);
  while (b) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main(int argc, char** argv) {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < (n); i++) cin >> a[i];
  long long last = a[0], x = 0;
  vector<long long> v;
  for (long long i = 1; i < n; i++) {
    if (a[i] != last) {
      v.push_back(x);
      last = a[i];
      x = 1;
    } else {
      x++;
    }
  }
  v.push_back(x);
  long long best = 0;
  for (long long i = 0; i < v.size() - 1; i++) {
    best = max(best, 2 * (min(v[i], v[i + 1])));
  }
  cout << best << endl;
  return 0;
}
