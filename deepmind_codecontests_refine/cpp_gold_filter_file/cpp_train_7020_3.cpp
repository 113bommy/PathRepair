#include <bits/stdc++.h>
using namespace std;
namespace io {
string separator = " ";
}
template <typename T>
inline void write(T x) {
  cout << x << io::separator;
}
template <typename T, typename... Args>
inline void write(T x, Args... args) {
  write(x);
  write(args...);
}
inline void writeln() { cout << '\n'; }
template <typename... Args>
inline void writeln(Args... args) {
  write(args...);
  writeln();
}
template <typename T>
inline void read(T& x) {
  cin >> x;
}
template <typename T, typename... Args>
inline void read(T& x, Args&... args) {
  cin >> x;
  read(args...);
}
template <typename T>
inline void writec(T x) {
  for (auto i = x.begin(); i != x.end(); i++) write(*i);
  writeln();
}
template <typename TL, typename TR>
inline TL GCD(TL a, TR b) {
  TL c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
template <typename TL, typename TR>
inline TL LCM(TL a, TR b) {
  return a / GCD(a, b) * b;
}
template <typename TL, typename TR>
inline TL MAX(TL a, TR b) {
  return a > b ? a : b;
}
template <typename T, typename... Args>
inline T MAX(T a, Args... args) {
  return MAX(a, MAX(args...));
}
template <typename TL, typename TR>
inline TL MIN(TL a, TR b) {
  return a < b ? a : b;
}
template <typename T, typename... Args>
inline T MIN(T a, Args... args) {
  return MIN(a, MIN(args...));
}
inline int64_t fac(int16_t n) {
  static vector<int64_t> f(1, 1);
  for (auto i = f.size(); i <= n; i++) f.push_back(f.back() * i);
  return f[n];
}
inline int64_t suma(int32_t a1, int32_t d, int32_t n) {
  return n * (2 * a1 + (n - 1) * d) / 2;
}
inline int32_t factor(int32_t n) {
  static vector<int32_t> d(2, 2), prime;
  if (n + 1 > d.size()) {
    int32_t np = d.size() - 1;
    int32_t nn = d.size();
    while (n > nn - 1) nn *= 2;
    nn--;
    d.resize(nn + 1);
    for (auto i = 2; i <= nn; i++) {
      if (!d[i]) {
        d[i] = i;
        prime.push_back(i);
      }
      int64_t x;
      for (int32_t j = 0; prime[j] <= d[i] && j < prime.size() &&
                          (x = (int64_t)i * prime[j]) <= nn;
           j++)
        d[x] = prime[j];
    }
  }
  return d[n];
}
inline bool isprime(int32_t n) { return (factor(n) == n); }
inline int32_t prime(int32_t n) {
  static vector<int32_t> p(1, 2);
  if (n + 1 > p.size()) {
    int32_t np = p.size() - 1;
    int32_t nn = p.size();
    while (n > nn - 1) nn *= 2;
    factor(nn * (log(nn) + log(log(nn))));
    nn--;
    p.resize(nn + 1);
    int32_t x = p[np] + 1;
    for (auto i = np + 1; i <= nn; i++) {
      while (!isprime(x)) x++;
      p[i] = x++;
    }
  }
  return p[n];
}
int32_t MOD = 1e9 + 7;
inline int32_t SUM(int32_t x, int32_t y) { return (x + y) % MOD; }
inline int32_t MUL(int32_t x, int32_t y) { return (int64_t)x * y % MOD; }
inline int32_t POW(int32_t x, int32_t n) {
  int32_t y = 1;
  while (n) {
    if (n % 2) y = MUL(y, x);
    x = MUL(x, x);
    n /= 2;
  }
  return y;
}
inline int32_t INV(int32_t x) { return POW(x, MOD - 2); }
inline int32_t DIV(int32_t x, int32_t y) { return MUL(x, INV(y)); }
inline int32_t P(int32_t l, int32_t r) {
  int32_t x = 1;
  for (auto i = l; i <= r; i++) x = MUL(x, i);
  return x;
}
inline int32_t FAC(int32_t n) { return P(2, n); }
inline int32_t C(int32_t n, int32_t k) { return DIV(P(k + 1, n), P(2, n - k)); }
void solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
vector<int16_t> init, goal;
vector<vector<int32_t>> e(0, vector<int32_t>(0));
vector<int32_t> ans;
inline void dfs(int32_t curr, int32_t prev, int16_t ths, int16_t oth) {
  if (init[curr] ^ ths != goal[curr]) {
    ans.push_back(curr + 1);
    ths ^= 1;
  }
  for (auto i : e[curr])
    if (i != prev) dfs(i, curr, oth, ths);
}
inline void solve() {
  int32_t n;
  read(n);
  e.resize(n);
  for (auto i = 0; i <= n - 2; i++) {
    int32_t u, v;
    read(u, v);
    u--;
    v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  init.resize(n);
  goal.resize(n);
  for (auto i = init.begin(); i != init.end(); i++) read(*i);
  for (auto i = goal.begin(); i != goal.end(); i++) read(*i);
  dfs(0, -1, 0, 0);
  writeln(ans.size());
  for (auto x : ans) writeln(x);
}
