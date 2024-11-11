#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Print(T v, long long st = 0, long long end = -1) {
  if (end == -1) end = (long long)v.size() - 1;
  for (long long i = st; i <= end; i++) cout << v[i] << (" ");
  cout << '\n';
}
long long MOD = 998244353;
struct Mint {
  long long val;
  bool operator==(const Mint& other) { return val == other.val; }
  Mint operator+(const Mint& other) {
    long long res = val + other.val;
    while (res >= MOD) res -= MOD;
    while (res < 0) res += MOD;
    return Mint(res);
  }
  Mint operator-(const Mint& other) {
    long long res = val - other.val;
    while (res >= MOD) res -= MOD;
    while (res < 0) res += MOD;
    return Mint(res);
  }
  Mint operator*(const Mint& other) {
    return Mint((val * 1ll * other.val) % MOD);
  }
  void operator-=(const Mint& other) { *this = *this - other; }
  void operator+=(const Mint& other) { *this = *this + other; }
  void operator*=(const Mint& other) { *this = *this * other; }
  Mint pow(long long y) {
    Mint z(1);
    Mint x(val);
    while (y > 0) {
      if (y % 2 == 1) z = z * x;
      x = x * x;
      y /= 2;
    }
    return z;
  }
  Mint operator/(const Mint& other) {
    return Mint(val) * Mint(other.val).pow(MOD - 2);
  }
  void operator/=(const Mint& other) { *this = *this / other; }
  Mint() { val = 0; }
  Mint(long long x) {
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    val = x;
  }
};
ostream& operator<<(ostream& out, const Mint& x) { return out << x.val; }
long long INF = 998244353;
long long LINF = 1000000000000000000;
long long mod1 = 998244353;
long long mod2 = 1000000007;
long double pi = acos(-1);
long double eps = 1e-11;
const long long N = 'z' - 'a', M = 24;
long long cnt[M][N + 1];
long long sum[1 << M];
signed main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for (long long j = 0; j <= N; j++) {
      while (s.back() == char(j + 'a')) {
        cnt[i][j]++;
        s.pop_back();
      }
    }
  }
  for (long long i = 1; i < (1 << n); i++) {
    sum[i] = 1;
    for (long long j = 0; j <= N; j++) {
      long long m = INF;
      for (long long k = 0; k < n; k++) {
        if (1 << k & i) m = min(m, cnt[k][j]);
      }
      sum[i] *= m + 1;
      sum[i] %= MOD;
    }
  }
  for (long long i = 1; i < (1 << n); i++) {
    if (__builtin_popcount(i) % 2) {
      sum[0] += sum[i];
      if (sum[0] >= MOD) sum[0] -= MOD;
    } else {
      sum[0] -= sum[i];
      if (sum[0] < 0) sum[0] += MOD;
    }
  }
  long long all = sum[0];
  for (long long i = 0; i < n; i++) {
    for (long long m = 0; m < (1 << n); m++) {
      if (!((1 << i) & m)) {
        sum[m] -= sum[m ^ (1 << i)];
        if (sum[0] < 0) sum[0] += MOD;
      }
    }
  }
  for (long long i = 0; i < n; i++)
    for (long long m = 0; m < (1 << n); m++)
      if ((1 << i) & m) {
        sum[m] += sum[m ^ (1 << i)];
        if (sum[0] >= MOD) sum[0] -= MOD;
      }
  long long re = 0;
  for (long long i = 0; i < (1 << n); i++) {
    long long k = 0, s = 0;
    long long t = all - sum[((1 << n) - 1) - i];
    if (t < 0) t += MOD;
    for (long long j = 0; j < n; j++)
      if ((1 << j) & i) k++, s += j;
    re ^= k * (s + k) * t;
  }
  cout << (re) << '\n';
}
