#include <bits/stdc++.h>
using namespace std;
struct trio {
  int64_t first, second, trd;
  friend ostream &operator<<(ostream &o, trio &a) {
    o << "(" << a.first << "," << a.second << "," << a.trd << ")";
    return o;
  }
};
template <typename T>
inline T max() {
  return numeric_limits<T>::max();
}
template <typename T>
inline T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
inline void get(T &&v) {
  cin >> v;
}
template <typename T, typename... Args>
inline void get(T &&v, Args &&...args) {
  cin >> v;
  get(args...);
}
template <typename T>
inline void put(T &&v) {
  cout << v << '\n';
}
template <typename T, typename... Args>
inline void put(T &&v, Args &&...args) {
  cout << v << ' ';
  put(args...);
}
template <typename T>
inline void getc(T &&a) {
  for (auto &v : a) cin >> v;
}
template <typename T>
inline void putc(T &&a, const string s = " ") {
  {
    for (auto &v : a) cout << v << s;
  }
  cout << '\n';
}
template <typename T>
inline void putcr(T &&a, const string s = " ") {
  if (a.size() > 0) {
    for (int64_t i = a.size() - 1; i >= 0; --i) cout << a[i] << s;
  }
  cout << '\n';
}
int64_t mod = 1e9 + 7;
inline int64_t fpow(int64_t a, int64_t n) {
  int64_t r = 1;
  while (n) {
    if (n & 1) r = r * a;
    a = a * a;
    n >>= 1;
  }
  return r;
}
inline int64_t mpow(int64_t a, int64_t n) {
  int64_t r = 1;
  while (n) {
    if (n & 1) r = (r * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return r;
}
inline int64_t mul(int64_t a, int64_t n) {
  assert(n >= 0);
  int64_t r = 0;
  while (n) {
    if (n & 1) r = (r + a) % mod;
    a = (a + a) % mod;
    n >>= 1;
  }
  return r;
}
inline int64_t bpow(int64_t a, int64_t n) {
  int64_t r = 1;
  while (n) {
    if (n & 1) r = mul(r, a);
    a = mul(a, a);
    n >>= 1;
  }
  return r;
}
ostream &operator<<(ostream &out, pair<int32_t, int32_t> &a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
ostream &operator<<(ostream &out, pair<int64_t, int64_t> &a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
vector<int32_t> primes;
inline void calc_primes(int32_t lmt) {
  vector<char> s(lmt);
  primes.push_back(2);
  for (int32_t i = 3; i < lmt; i += 2) {
    if (s[i]) continue;
    primes.push_back(i);
    for (int32_t j = i + (i << 1); j < lmt; j += (i << 1)) s[j] = 1;
  }
}
inline vector<pair<int32_t, int32_t> > factorize(int32_t n) {
  vector<pair<int32_t, int32_t> > a;
  int32_t cnt = __builtin_ctzl(n);
  a.push_back({2, cnt});
  n >>= cnt;
  for (auto &d : primes) {
    cnt = 0;
    while (n % d == 0) n /= d, cnt++;
    a.push_back({d, cnt});
    if (n == 1) break;
  }
  if (n != 1) a.push_back({n, 1});
  return a;
}
int64_t n, d;
vector<int64_t> a;
int64_t f() {
  int64_t r = 2;
  if (n == 1) return r;
  if (a[0] + 2 * d <= a[1]) r++;
  if (a[n - 1] - 2 * d > a[n - 2]) r++;
  for (int64_t i = 1; i < n - 1; ++i) {
    if (a[i] + 2 * d <= a[i + 1]) r++;
    if (a[i] - 2 * d > a[i - 1]) r++;
  }
  return r;
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(20);
  };
  get(n, d);
  (a).clear();
  (a).resize(n);
  ;
  getc(a);
  put(f());
  return 0;
}
