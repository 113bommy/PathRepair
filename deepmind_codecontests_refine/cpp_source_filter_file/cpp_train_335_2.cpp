#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926536;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& mas) {
  for (const auto& x : mas) {
    out << x << ' ';
  }
  return out;
}
void ok() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }
inline long long nxt() {
  long long x;
  cin >> x;
  return x;
}
template <int mod>
struct Modular {
  int val;
  Modular(long long _val = 0) {
    if (_val < 0 || _val >= mod) {
      val = _val % mod;
      if (val < 0) {
        val += mod;
      }
    } else {
      val = _val;
    }
  }
  Modular operator+(const Modular& ot) const {
    int res = val + ot.val;
    if (res >= mod) {
      res -= mod;
    }
    return {res};
  }
  Modular operator-(const Modular& ot) const {
    int res = val - ot.val;
    if (res < 0) {
      res += mod;
    }
    return {res};
  }
  Modular operator*(const Modular& ot) const { return {1ll * val * ot.val}; }
  Modular& operator++() {
    val += 1;
    if (val == mod) {
      val = 0;
    }
    return *this;
  }
  Modular operator++(int) {
    Modular tmp(*this);
    operator++();
    return tmp;
  }
  void operator+=(const Modular& ot) {
    val += ot.val;
    if (val >= mod) {
      val -= mod;
    }
  }
  void operator-=(const Modular& ot) {
    val -= ot.val;
    if (val < 0) {
      val += mod;
    }
  }
  void operator*=(const Modular& ot) { val = 1ll * val * ot.val % mod; }
  bool operator==(const Modular& ot) const { return val == ot.val; }
  bool operator!=(const Modular& ot) const { return val != ot.val; }
};
template <int mod>
ostream& operator<<(ostream& ostr, const Modular<mod>& x) {
  return ostr << x.val;
}
const int mod = 1000000007;
using Mint = Modular<mod>;
const int N = 2e6 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = nxt();
  vector<Mint> dp(N);
  Mint huita = 0;
  dp[0] = 1;
  for (int i = 1; i < N; i++) {
    Mint tmp_huita = huita;
    huita = dp[i - 1] * 2;
    dp[i] = dp[i - 1] + tmp_huita;
  }
  vector<Mint> ans(N);
  for (int i = 0; i < N; i++) {
    if (i <= 3) {
      ans[i] = dp[i];
    } else {
      ans[i] = dp[i] + ans[i - 3];
    }
  }
  while (t--) {
    int n = nxt();
    if (n <= 2) {
      cout << 0 << '\n';
      continue;
    }
    n -= 2;
    cout << ans[n - 1] * 4 << '\n';
  }
  return 0;
}
