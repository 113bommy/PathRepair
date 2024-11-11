#include <bits/stdc++.h>
using namespace std;
namespace Bit {
const int bcnt{20};
const int size{1 << bcnt};
const int full{size - 1};
inline int size_of(int n) {
  int r = 1;
  while (n >>= 1) r++;
  return r;
}
inline int count(int mask) { return __builtin_popcount(mask); }
inline int at(int mask, int b) { return mask >> b & 1; }
inline int flip(int mask) { return full ^ mask; }
inline int flip_b(int mask, int b) { return mask ^ (1 << b); }
inline int parity(int mask) { return __builtin_parity(mask); }
inline void print(int mask) {
  cout << "bitset<32>(mask)"
       << " = " << (bitset<32>(mask)) << "\n";
}
};  // namespace Bit
const int MOD = 1e9 + 7;
struct mint {
  int v;
  mint(int v = 0) : v(v){};
  inline bool operator==(const mint &b) { return v == b.v; }
  inline void operator+=(const mint &b) {
    if ((v += b.v) >= MOD) v -= MOD;
  }
  inline void operator-=(const mint &b) {
    if ((v += MOD - b.v) >= MOD) v -= MOD;
  }
  inline void operator*=(const mint &b) { v = v * 1ll * b.v % MOD; }
  inline mint operator^(int b) const {
    mint r{1};
    for (auto a = *this; b; b >>= 1) {
      if (b & 1) r *= a;
      a *= a;
    }
    return r;
  }
  inline mint inv() const { return operator^(MOD - 2); }
  inline void operator/=(const mint &b) { operator*=(b.inv()); }
};
inline mint operator+(const mint &a, const mint &b) {
  auto r = a;
  r += b;
  return r;
}
inline mint operator-(const mint &a, const mint &b) {
  auto r = a;
  r -= b;
  return r;
}
inline mint operator*(const mint &a, const mint &b) {
  auto r = a;
  r *= b;
  return r;
}
inline mint operator/(const mint &a, const mint &b) {
  auto r = a;
  r /= b;
  return r;
}
const int N = 1e6 + 7;
int a[N];
mint pw2[N];
static void glo_init() {
  pw2[0] = 1;
  for (int i = 1; i < N; i++) pw2[i] = pw2[i - 1] + pw2[i - 1];
}
int subcnt[Bit::size];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) subcnt[Bit::flip(a[i])] += 1;
  for (int b = 0; b < Bit::bcnt; b++) {
    for (int mask = 0; mask < Bit::size; mask++) {
      if (!Bit::at(mask, b)) continue;
      subcnt[mask] += subcnt[Bit::flip_b(mask, b)];
    }
  }
  mint res = pw2[n];
  for (int mask = 1; mask < Bit::size; mask++) {
    int supcnt = subcnt[Bit::flip(mask)];
    bool is_positive = Bit::parity(mask) == false;
    if (is_positive)
      res += pw2[supcnt];
    else
      res -= pw2[supcnt];
  }
  cout << res.v << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  glo_init();
  solve();
  return 0;
}
