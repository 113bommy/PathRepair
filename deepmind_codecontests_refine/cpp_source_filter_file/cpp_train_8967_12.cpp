#include <bits/stdc++.h>
using namespace std;
const int block_size = 320;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 7;
const long double eps = 1e-9;
const double PI = atan(1) * 4;
template <typename T>
inline int sign(const T &a) {
  if (a < 0) return -1;
  if (a > 0) return 1;
  return 0;
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <typename T, typename S>
inline bool upmin(T &a, const S &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool upmax(T &a, const S &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline void in(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
long long twop(int x) { return 1LL << x; }
template <typename A, typename B>
inline void in(A &x, B &y) {
  in(x);
  in(y);
}
template <typename A, typename B, typename C>
inline void in(A &x, B &y, C &z) {
  in(x);
  in(y);
  in(z);
}
template <typename A, typename B, typename C, typename D>
inline void in(A &x, B &y, C &z, D &d) {
  in(x);
  in(y);
  in(z);
  in(d);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
namespace SOLVE {
long long pow(long long base, long long p, long long MOD) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    long long d = pow(base, p / 2, MOD);
    return (d * d) % MOD;
  }
  return (pow(base, p - 1, MOD) * base) % MOD;
}
long long inv(long long x, long long MOD) { return pow(x, MOD - 2, MOD); }
long long gauss(vector<vector<long long>> &a, long long MOD) {
  int n = a.size(), m = a[0].size() - 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= m; j++) a[i][j] = (a[i][j] % MOD + MOD) % MOD;
  vector<int> where(m, -1);
  for (int col = 0, row = 0; col < m && row < n; col++) {
    int sel = row;
    for (int i = row; i < n; i++)
      if (a[i][col] > a[sel][col]) sel = i;
    if (a[sel][col] == 0) {
      where[col] = -1;
      continue;
    }
    for (int i = col; i <= m; i++) swap(a[sel][i], a[row][i]);
    where[col] = row;
    long long c_inv = inv(a[row][col], MOD);
    for (int i = 0; i < n; i++)
      if (i != row) {
        if (a[i][col] == 0) continue;
        long long c = (a[i][col] * c_inv) % MOD;
        for (int j = 0; j <= m; j++)
          a[i][j] = (a[i][j] - c * a[row][j] % MOD + MOD) % MOD;
      }
    row++;
  }
  vector<long long> ans(m, 0);
  long long result = 1;
  for (int i = 0; i < m; i++)
    if (where[i] != -1)
      ans[i] = (a[where[i]][m] * inv(a[where[i]][i], MOD)) % MOD;
    else
      result = (result * MOD) % mod;
  for (int i = 0; i < n; i++) {
    long long sum = a[i][m] % MOD;
    for (int j = 0; j < m; j++)
      sum = (sum + MOD - (ans[j] * a[i][j]) % MOD) % MOD;
    if (sum != 0) return 0;
  }
  return result;
}
void main() {
  vector<vector<long long>> equation;
  for (long long i = 0; i < 11; i++) {
    cout << "? " << i << endl;
    long long val;
    cin >> val;
    vector<long long> tmp;
    tmp.push_back(1);
    for (long long j = 0; j < 10; j++) tmp.push_back(tmp.back() * i % 1000003);
    tmp.push_back(val);
    equation.push_back(tmp);
  }
  gauss(equation, 1000003);
  vector<long long> poly;
  for (long long i = 0; i < 11; i++) {
    poly.push_back(equation[i].back() * inv(equation[i][i], 1000003) % 1000003);
  }
  for (long long i = 0; i < 1000003; i++) {
    long long val = 0;
    for (long long j = 10; j >= 0; j--) {
      val = val * i + poly[j];
      val %= 1000003;
    }
    if (val == 0) {
      cout << "! " << i << endl;
      return;
    }
  }
  cout << -1 << endl;
}
}  // namespace SOLVE
signed main() {
  int t;
  t = 1;
  while (t--) {
    SOLVE::main();
  }
  return 0;
}
