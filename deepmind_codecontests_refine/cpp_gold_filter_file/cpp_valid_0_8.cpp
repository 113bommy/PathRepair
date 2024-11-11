#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  os << "{";
  for (int i = 0; i < (int)vec.size(); i++) {
    os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
  }
  os << "}";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U> pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map_var) {
  os << "{";
  for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
    os << "(" << itr->first << ", " << itr->second << ")";
    itr++;
    if (itr != map_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& set_var) {
  os << "{";
  for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
    os << (*itr);
    ++itr;
    if (itr != set_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
int scan() { return getchar(); }
void scan(int& a) { cin >> a; }
void scan(long long& a) { cin >> a; }
void scan(char& a) { cin >> a; }
void scan(double& a) { cin >> a; }
void scan(string& a) { cin >> a; }
template <class T, class S>
void scan(pair<T, S>& p) {
  scan(p.first), scan(p.second);
}
template <class T>
void scan(vector<T>&);
template <class T>
void scan(vector<T>& a) {
  for (auto& i : a) scan(i);
}
template <class T>
void scan(T& a) {
  cin >> a;
}
void IN() {}
template <class Head, class... Tail>
void IN(Head& head, Tail&... tail) {
  scan(head);
  IN(tail...);
}
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val) {
  std::fill((T*)array, (T*)(array + N), val);
}
template <class T>
T ceil(T x, T y) {
  assert(y >= 1);
  return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T>
T floor(T x, T y) {
  assert(y >= 1);
  return (x > 0 ? x / y : (x + y - 1) / y);
}
vector<int> iota(int n) {
  vector<int> a(n);
  iota((a).begin(), (a).end(), 0);
  return a;
}
template <class T>
T POW(T x, int n) {
  T res = 1;
  for (; n; n >>= 1, x *= x) {
    if (n & 1) res *= x;
  }
  return res;
}
long long pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
long long allbit(long long n) { return (1LL << n) - 1; }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(long long t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
template <class S>
void fold_in(vector<S>& v) {}
template <typename Head, typename... Tail, class S>
void fold_in(vector<S>& v, Head&& a, Tail&&... tail) {
  for (auto e : a) v.emplace_back(e);
  fold_in(v, tail...);
}
template <class S>
void renumber(vector<S>& v) {}
template <typename Head, typename... Tail, class S>
void renumber(vector<S>& v, Head&& a, Tail&&... tail) {
  for (auto&& e : a)
    e = distance((v).begin(), lower_bound((v).begin(), (v).end(), (e)));
  renumber(v, tail...);
}
template <class S, class... Args>
void zip(vector<S>& head, Args&&... args) {
  vector<S> v;
  fold_in(v, head, args...);
  sort((v).begin(), (v).end()),
      v.erase(unique((v).begin(), (v).end()), v.end());
  renumber(v, head, args...);
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <unsigned int mod>
class ModInt {
 private:
  unsigned int v;
  static unsigned int norm(const unsigned int& x) {
    return x < mod ? x : x - mod;
  }
  static ModInt make(const unsigned int& x) {
    ModInt m;
    return m.v = x, m;
  }
  static ModInt inv(const ModInt& x) { return make(inverse(x.v, mod)); }
  static unsigned int inverse(int a, int m) {
    int u[] = {a, 1, 0}, v[] = {m, 0, 1}, t;
    while (*v) {
      t = *u / *v;
      swap(u[0] -= t * v[0], v[0]), swap(u[1] -= t * v[1], v[1]),
          swap(u[2] -= t * v[2], v[2]);
    }
    return (u[1] % m + m) % m;
  }

 public:
  ModInt() : v{0} {}
  ModInt(const long long val) : v{norm(val % mod + mod)} {}
  ModInt(const ModInt<mod>& n) : v{n()} {}
  explicit operator bool() const noexcept { return v != 0; }
  bool operator!() const noexcept { return !static_cast<bool>(*this); }
  ModInt& operator=(const ModInt& n) { return v = n(), (*this); }
  ModInt& operator=(const long long val) {
    return v = norm(val % mod + mod), (*this);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return v == 0 ? make(0) : make(mod - v); }
  ModInt operator+(const ModInt& val) const { return make(norm(v + val())); }
  ModInt operator-(const ModInt& val) const {
    return make(norm(v + mod - val()));
  }
  ModInt operator*(const ModInt& val) const {
    return make((long long)v * val() % mod);
  }
  ModInt operator/(const ModInt& val) const { return *this * inv(val); }
  ModInt& operator+=(const ModInt& val) { return *this = *this + val; }
  ModInt& operator-=(const ModInt& val) { return *this = *this - val; }
  ModInt& operator*=(const ModInt& val) { return *this = *this * val; }
  ModInt& operator/=(const ModInt& val) { return *this = *this / val; }
  ModInt operator+(const long long val) const { return ModInt{v + val}; }
  ModInt operator-(const long long val) const { return ModInt{v - val}; }
  ModInt operator*(const long long val) const {
    return ModInt{(long long)v * (val % mod)};
  }
  ModInt operator/(const long long val) const {
    return ModInt{(long long)v * inv(val)};
  }
  ModInt& operator+=(const long long val) { return *this = *this + val; }
  ModInt& operator-=(const long long val) { return *this = *this - val; }
  ModInt& operator*=(const long long val) { return *this = *this * val; }
  ModInt& operator/=(const long long val) { return *this = *this / val; }
  bool operator==(const ModInt& val) const { return v == val.v; }
  bool operator!=(const ModInt& val) const { return !(*this == val); }
  bool operator==(const long long val) const {
    return v == norm(val % mod + mod);
  }
  bool operator!=(const long long val) const { return !(*this == val); }
  unsigned int operator()() const { return v; }
  friend ModInt operator+(const long long val, const ModInt& n) {
    return n + val;
  }
  friend ModInt operator-(const long long val, const ModInt& n) {
    return ModInt{val - n()};
  }
  friend ModInt operator*(const long long val, const ModInt& n) {
    return n * val;
  }
  friend ModInt operator/(const long long val, const ModInt& n) {
    return ModInt{val} / n;
  }
  friend bool operator==(const long long val, const ModInt& n) {
    return n == val;
  }
  friend bool operator!=(const long long val, const ModInt& n) {
    return !(val == n);
  }
  friend istream& operator>>(istream& is, ModInt& n) {
    unsigned int v;
    return is >> v, n = v, is;
  }
  friend ostream& operator<<(ostream& os, const ModInt& n) {
    return (os << n());
  }
  friend ModInt mod_pow(ModInt x, long long n) {
    ModInt ans = 1;
    while (n) {
      if (n & 1) ans *= x;
      x *= x, n >>= 1;
    }
    return ans;
  }
};
using mod = ModInt<1000000007>;
mod inv[8000000], fac[8000000], finv[8000000];
void make() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < 8000000; i++) {
    inv[i] = 1000000007 - inv[1000000007 % i] * (1000000007 / i);
    fac[i] = fac[i - 1] * i;
    finv[i] = finv[i - 1] * inv[i];
  }
}
mod comb(int a, int b) {
  if (a < b) return 0;
  return fac[a] * finv[b] * finv[a - b];
}
mod F[4000010];
int main() {
  make();
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q;
  IN(n, q);
  vector<int> a(q);
  IN(a);
  for (int i = 0; i <= n; i++) {
    F[0] += comb(3 * i, 0);
    F[1] += comb(3 * i, 1);
  }
  mod v = (mod)1 / 3;
  for (int k = 2; k <= 3 * n; k++) {
    F[k] = (comb(3 * n + 3, k + 1) - 3 * F[k - 1] - F[k - 2]) * v;
  }
  for (int i = 0; i < (int)(5); ++i) {
    (void(0));
  }
  for (int i = 0; i < (int)(q); ++i) {
    cout << F[a[i]] << "\n";
  }
  return 0;
}
