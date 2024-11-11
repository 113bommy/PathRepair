#include <bits/stdc++.h>
using namespace std;
namespace IO {
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (s.size()) {
    setIn(s + ".inp");
    setOut(s + ".out");
  } else {
  }
}
}  // namespace IO
using namespace IO;
namespace Function {
template <typename T1, typename T2>
void amax(T1& a, T2 b) {
  assert(!(typeid(a).name() == typeid(int).name() &&
           typeid(b).name() == typeid(long long).name()));
  if (a < b) a = b;
}
template <typename T1, typename T2>
void amin(T1& a, T2 b) {
  if (a > b) a = b;
}
template <typename T>
void compress(T& a) {
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
}
template <typename T1, typename T2, typename T3>
int position(T1 Begin, T2 sz, T3 val, bool type = 0) {
  if (type == 0) {
    return lower_bound(Begin, Begin + sz, val) - Begin;
  }
  return upper_bound(Begin, Begin + sz, val) - Begin;
}
template <typename T>
long long sqr(T x) {
  return 1LL * x * x;
}
template <typename T1, typename T2>
long long GCD(T1 a, T2 b) {
  return b == 0 ? a : GCD(b, a % b);
}
template <typename T1, typename T2>
long long LCM(T1 a, T2 b) {
  return 1LL * a / GCD(a, b) * b;
}
}  // namespace Function
using namespace Function;
namespace Output {
void print(int x) { cout << x << "\n"; }
void print(unsigned int x) { cout << x << "\n"; }
void print(long unsigned int x) { cout << x << "\n"; }
void print(long long x) { cout << x << "\n"; }
void print(unsigned long long x) { cout << x << "\n"; }
void print(float x) { cout << x << "\n"; }
void print(double x) { cout << x << "\n"; }
void print(long double x) { cout << x << "\n"; }
void print(char x) { cout << x << "\n"; }
void print(char* x) { cout << x << "\n"; }
void print(unsigned char x) { cout << x << "\n"; }
void print(const char* x) { cout << x << "\n"; }
void print(string x) { cout << x << "\n"; }
void print(bool x) { cout << x << "\n"; }
template <class T, class... Ts>
void print(T t, Ts... ts) {
  cout << t << " ";
  print(ts...);
}
template <typename T1, typename T2>
void print(pair<T1, T2> a) {
  print(a.first, a.second);
}
template <typename T>
void print(T a) {
  for (auto it : a) {
    print(it);
  }
}
template <class T, class... Ts>
void prine(T t, Ts... ts) {
  print(t, ts...);
  exit(0);
}
}  // namespace Output
using namespace Output;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int INF = 1e9;
const long long INFL = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e3 + 10;
template <int _MOD>
class Mod {
 private:
  int x;

 public:
  static const int MOD = _MOD;
  Mod() : x(0) {}
  Mod(long long _x) : x(_x % MOD) {
    if (x < 0) x += MOD;
  }
  Mod operator-() const {
    Mod res = *this;
    res.x = MOD - res.x;
    return res;
  }
  explicit operator int() const { return x; }
  friend bool operator==(const Mod& A, const Mod& B) { return A.x == B.x; }
  friend bool operator!=(const Mod& A, const Mod& B) { return A.x != B.x; }
  friend bool operator<(const Mod& A, const Mod& B) { return A.x < B.x; }
  friend bool operator>(const Mod& A, const Mod& B) { return A.x > B.x; }
  friend bool operator<=(const Mod& A, const Mod& B) { return A.x <= B.x; }
  friend bool operator>=(const Mod& A, const Mod& B) { return A.x >= B.x; }
  template <typename T1, typename T2>
  long long inv(T1 A, T2 B) {
    assert(B > 0);
    if (B == 1) return 0;
    A %= B;
    if (A < 0) A += B;
    assert(A != 0);
    if (A == 1) return 1;
    return B - inv(B, A) * B / A;
  }
  Mod& operator+=(const Mod& A) {
    x += A.x;
    if (x >= MOD) x -= MOD;
    return *this;
  }
  Mod& operator-=(const Mod& A) {
    x -= A.x;
    if (x < 0) x += MOD;
    return *this;
  }
  Mod& operator*=(const Mod& A) {
    x = (1LL * x * A.x) % MOD;
    return *this;
  }
  Mod& operator/=(const Mod& A) { return *this *= Mod(inv(A.x, MOD)); }
  Mod& operator^=(long long A) {
    Mod res = 1;
    for (; A > 0; A >>= 1) {
      if (A & 1) {
        res *= x;
      }
      x = (1LL * x * x) % MOD;
    }
    x = res.x;
    return *this;
  }
  Mod& operator<<=(long long A) { return *this *= Mod(2) ^ A; }
  Mod& operator>>=(long long A) { return *this /= Mod(2) ^ A; }
  friend Mod operator+(const Mod& A, const Mod& B) { return Mod(A) += B; }
  friend Mod operator-(const Mod& A, const Mod& B) { return Mod(A) -= B; }
  friend Mod operator*(const Mod& A, const Mod& B) { return Mod(A) *= B; }
  friend Mod operator/(const Mod& A, const Mod& B) { return Mod(A) /= B; }
  friend Mod operator^(const Mod& A, const long long& B) { return Mod(A) ^= B; }
  friend Mod operator<<(const Mod& A, const long long& B) {
    return Mod(A) <<= B;
  }
  friend Mod operator>>(const Mod& A, const long long& B) {
    return Mod(A) >>= B;
  }
  friend istream& operator>>(istream& stream, Mod& A) {
    stream >> A.x;
    return stream;
  }
};
using num = Mod<MOD>;
num dp[N][N];
int main() {
  setIO();
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int mn = 0;
  int val = 0;
  for (char x : s) {
    val += (x == '(' ? 1 : -1);
    amin(mn, val);
  }
  n -= m;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = dp[i - 1][j + 1];
      if (j > 0) {
        dp[i][j] += dp[i - 1][j - 1];
      }
    }
  }
  num res = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = mn; j <= i; j++) {
      if (val + j > n - i) {
        continue;
      }
      res += dp[i][j] * dp[n - i][val + j];
    }
  }
  print((int)res);
  return 0;
}
