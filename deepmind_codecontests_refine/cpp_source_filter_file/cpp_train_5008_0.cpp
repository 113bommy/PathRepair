#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool readInteger(T& x) {
  char c, r = 0, n = 0;
  x = 0;
  while (true) {
    c = getchar();
    if (c < 0 && !r)
      return 0;
    else if (c == '-' && !r)
      n = 1;
    else if (c >= '0' && c <= '9')
      x = x * 10 + c - '0', r = 1;
    else if (r)
      break;
  }
  if (n) x = -x;
  return 1;
}
template <typename T>
vector<T> readIntegral(int n) {
  vector<T> ret(n);
  for (int i = 0; i < n; i++) readInteger(ret[i]);
  return ret;
}
auto readInts = readIntegral<int>;
auto readLongs = readIntegral<long long>;
int sgn(int x) {
  if (x > 0) {
    return 1;
  }
  if (x < 0) {
    return -1;
  }
  return 0;
}
template <typename T>
vector<vector<T>> make2d(size_t r, size_t c) {
  return vector<vector<T>>(r, vector<T>(c));
}
template <typename T>
vector<vector<T>> make2d(size_t r, size_t c, const T& def) {
  return vector<vector<T>>(r, vector<T>(c, def));
}
template <typename T, T MOD>
struct ModInt {
  T value;
  ModInt() : value(0) {}
  ModInt(T x) {
    x %= MOD;
    if (x < 0) x += MOD;
    value = x;
  }

 public:
  ModInt& operator+=(ModInt x) {
    value += x.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  ModInt& operator-=(ModInt x) {
    value -= x.value;
    if (value < 0) value += MOD;
    return *this;
  }
  ModInt& operator*=(ModInt x) {
    value *= x.value;
    value %= MOD;
    return *this;
  }
  ModInt& operator/=(ModInt x) {
    x.invert();
    return *this *= x;
  }
  ModInt operator+(ModInt x) const {
    ModInt o = *this;
    o += x;
    return o;
  }
  ModInt operator-(ModInt x) const {
    ModInt o = *this;
    o -= x;
    return o;
  }
  ModInt operator*(ModInt x) const {
    ModInt o = *this;
    o *= x;
    return o;
  }
  ModInt operator/(ModInt x) const {
    ModInt o = *this;
    o /= x;
    return o;
  }
  bool operator==(ModInt x) const { return value == x.value; }
  bool operator!=(ModInt x) const { return !(*this == x); }
  ModInt operator-() const { return ModInt(0) - *this; }
  ModInt operator^(long long x) const {
    ModInt ret = 1 % MOD;
    ModInt mul = *this;
    while (x) {
      if (x & 1) ret *= mul;
      mul *= mul;
      x >>= 1;
    }
    return ret;
  }
  ModInt& operator^=(long long x) { return *this = *this ^ x; }

 private:
  void invert() { *this ^= MOD - 2; }

 public:
  friend ostream& operator<<(ostream& out, const ModInt& x) {
    return out << x.value;
  }
};
template <typename T>
using v2d = vector<vector<T>>;
int main() {
  int n, m;
  readInteger(n);
  readInteger(m);
  vector<int> vert(n);
  for (int i = (0); i < int(n); ++i) readInteger(vert[i]);
  vector<int> hor;
  for (int i = (0); i < int(m); ++i) {
    int x1, x2, y;
    readInteger(x1);
    readInteger(x2);
    readInteger(y);
    if (x1 != 1) {
      continue;
    }
    hor.push_back(x2);
  }
  vert.push_back(1e9 + 10);
  sort(vert.begin(), vert.end());
  sort(hor.begin(), hor.end());
  int best = 1e9;
  int idx = 0;
  int crnt = 0;
  for (int x : vert) {
    while (idx < hor.size() && hor[idx] < x) {
      ++idx;
    }
    best = min(best, crnt + (int)hor.size() - idx);
    crnt++;
  }
  printf("%d\n", best);
}
