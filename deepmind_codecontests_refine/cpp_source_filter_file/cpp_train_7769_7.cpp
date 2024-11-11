#include <bits/stdc++.h>
using namespace std;
class customIO {
 public:
  istream& in;
  ostream& out;
  customIO(istream& _in, ostream& _out) : in(_in), out(_out) {}
  string next() {
    string s;
    in >> s;
    return s;
  }
  double nextDouble() { return stod(next()); }
  int nextInt() { return stoi(next()); }
  long long nextLong() { return stoll(next()); }
  template <typename T>
  void print(T t) {
    out << t;
  }
  template <typename T, typename... U>
  void print(T t, U... u) {
    out << t;
    print(u...);
  }
  template <typename T, typename... U>
  void println(T t, U... u) {
    print(t, u..., "\n");
  }
  void println() { print("\n"); }
};
long long dp[1005][1005];
class TaskD {
 public:
  const int mod = (int)1e9 + 7;
  long long k, pa, pb;
  long long ia, ib, iab;
  void solve(customIO& io) {
    k = io.nextInt();
    pa = io.nextInt();
    ia = power(pa, mod - 2);
    pb = io.nextInt();
    ib = power(pb, mod - 2);
    iab = power(pa + pb, mod - 2);
    memset(dp, -1, sizeof dp);
    long long res = solve(0, 0);
    io.println(res);
    return;
  }
  long long solve(int na, int nab) {
    if (nab >= k) return nab;
    if (na + nab >= k) return (1ll * ib * (pa + pb) - 1 + na + nab) % mod;
    long long& res = dp[na][nab];
    if (res != -1) return res;
    res = 0;
    res += pa * 1ll * solve(na + 1, nab);
    res += pb * 1ll * solve(na, nab + na);
    res %= mod;
    res *= iab;
    res %= mod;
    return res;
  }
  long long power(long long base, long long expo) {
    long long res = 1;
    while (expo) {
      if (expo % 2) res = (res * 1ll * base) % mod;
      expo /= 2;
      base = (base * 1ll * base) % mod;
    }
    return res % mod;
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout << std::fixed;
  std::cout.precision(20);
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  customIO io(in, out);
  TaskD solver;
  solver.solve(io);
  return 0;
}
