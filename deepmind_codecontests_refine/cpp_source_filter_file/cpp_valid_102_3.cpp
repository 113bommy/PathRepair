#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 998244353;
struct Mint {
  int val;
  Mint() { val = 0; }
  Mint(ll x) {
    val = (-MOD <= x && x < MOD) ? x : x % MOD;
    if (val < 0) val += MOD;
  }
  template <typename U>
  explicit operator U() const {
    return (U)val;
  }
  friend bool operator==(const Mint& a, const Mint& b) {
    return a.val == b.val;
  }
  friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
  friend bool operator<(const Mint& a, const Mint& b) { return a.val < b.val; }
  Mint& operator+=(const Mint& m) {
    if ((val += m.val) >= MOD) val -= MOD;
    return *this;
  }
  Mint& operator-=(const Mint& m) {
    if ((val -= m.val) < 0) val += MOD;
    return *this;
  }
  Mint& operator*=(const Mint& m) {
    val = (ll)val * m.val % MOD;
    return *this;
  }
  friend Mint modex(Mint a, ll p) {
    assert(p >= 0);
    Mint ans = 1;
    for (; p; p >>= 1, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  Mint& operator/=(const Mint& m) { return *this *= modex(m, MOD - 2); }
  Mint& operator++() { return *this += 1; }
  Mint& operator--() { return *this -= 1; }
  Mint operator++(int) {
    Mint result(*this);
    *this += 1;
    return result;
  }
  Mint operator--(int) {
    Mint result(*this);
    *this -= 1;
    return result;
  }
  Mint operator-() const { return Mint(-val); }
  friend Mint operator+(Mint a, const Mint& b) { return a += b; }
  friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
  friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
  friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
  friend ostream& operator<<(ostream& os, const Mint& x) { return os << x.val; }
  friend string to_string(const Mint& b) { return to_string(b.val); }
};
int main() {
  int k, A, h;
  scanf("%d%d%d", &k, &A, &h);
  vector<Mint> powA(33);
  powA[0] = 1;
  for (int i = 1; i <= 32; ++i) powA[i] = powA[i - 1] * A;
  array<array<vector<pair<Mint, ll>>, 2>, 2> val;
  for (int rot = 0; rot < 2; ++rot) {
    int init = 1 + (rot << (k - 1));
    vector<int> p = {-1};
    for (int i = 0; i < k - 1; ++i) {
      for (int j = 0; j < (1 << i); ++j) p.push_back(i + 1);
    }
    42;
    do {
      bool bad = false;
      for (int b = 1; !bad && b < k; ++b) {
        for (int i = 0; !bad && i < p.size(); i += (1 << b)) {
          int num = 0;
          for (int j = i; j < i + (1 << b); ++j) num += p[j] == (k - b);
          if (num != 1) bad = true;
        }
      }
      if (bad) continue;
      Mint cur = 0;
      int z = -1;
      ll q = 0;
      for (int i = (int)p.size() - 1; i >= 0; --i) {
        cur += (init + i) * powA[p[i] == -1 ? 1 : 1 + (1 << p[i])];
        if (p[i] == -1) z = i;
        q <<= 3;
        q += p[i] + 1;
      }
      val[rot][0].push_back({cur, q});
      q += (1 << (3 * z));
      cur += (init + z) * (powA[2] - powA[1]);
      val[rot][1].push_back({cur, q});
    } while (next_permutation(p.begin(), p.end()));
  }
  for (int t = 0; t < 2; ++t) {
    auto& hay = val[1][1 - t];
    sort(hay.begin(), hay.end());
    for (auto& v : val[0][t]) {
      Mint need = h - v.first;
      auto it = lower_bound(hay.begin(), hay.end(), make_pair(need, 0LL));
      if (it == hay.end()) continue;
      if (it->first != need) continue;
      ll tmp = v.second;
      for (int i = 0; i < (1 << (k - 1)); ++i) {
        int x = tmp % 8;
        printf("%d ", x == 0 ? 1 : 1 + (1 << (x - 1)));
        tmp >>= 3;
      }
      tmp = it->second;
      for (int i = 0; i < (1 << (k - 1)); ++i) {
        int x = tmp % 8;
        printf("%d ", x == 0 ? 1 : 1 + (1 << (x - 1)));
        tmp >>= 3;
      }
      printf("\n");
      return 0;
    }
  }
  printf("-1\n");
}
