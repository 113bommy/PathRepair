#include <bits/stdc++.h>
using namespace std;
long long fpm(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
T gcd(T x, T y) {
  for (T t; x; t = x, x = y % x, y = t)
    ;
  return y;
}
template <class edge>
struct Graph {
  vector<vector<edge> > adj;
  Graph(int n) {
    adj.clear();
    adj.resize(n + 5);
  }
  Graph() { adj.clear(); }
  void resize(int n) { adj.resize(n + 5); }
  void add(int s, edge e) { adj[s].push_back(e); }
  void del(int s, edge e) { adj[s].erase(find(iter(adj[s]), e)); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
const int N = 110000, mod = 1000000007;
long long f[N], g[N], M2[N], Mb[N];
char L[N], R[N];
long long inv9 = fpm(9, mod - 2, mod);
long long calc(char *x) {
  int n = strlen(x);
  long long ret = 0, pre = 0;
  for (int _end_ = (n - 1), i = (0); i <= _end_; ++i) {
    int y = n - 1 - i;
    if (x[i] == '7') {
      long long b = (Mb[y] - 1) * inv9 % mod;
      ret += ((pre + 7 * Mb[y] + 4 * b) % mod) *
             ((pre + 4 * Mb[y] + 7 * b) % mod) % mod;
      long long p = (pre + 4 * Mb[y]) % mod;
      ret += (M2[y] - 1) * p % mod * p % mod;
      ret += g[y] * p % mod;
      ret += f[y];
    }
    pre = (pre + Mb[y] * (x[i] - '0')) % mod;
  }
  return ret % mod;
}
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  f[1] = 28, g[1] = 11;
  M2[0] = Mb[0] = 1;
  for (int _end_ = (N - 2), i = (1); i <= _end_; ++i) {
    M2[i] = M2[i - 1] * 2 % mod;
    Mb[i] = Mb[i - 1] * 10 % mod;
  }
  for (int _end_ = (N - 2), i = (1); i <= _end_; ++i) {
    long long p10 = Mb[i], p2 = M2[i] - 1, b = (p10 - 1) * inv9 % mod;
    f[i + 1] = (2 * f[i] + 65 * p10 % mod * p10 % mod * p2 % mod +
                11 * p10 % mod * g[i] % mod +
                ((4 * p10 + b * 7) % mod) * ((7 * p10 + b * 4) % mod) % mod) %
               mod;
    g[i + 1] = (2 * g[i] + 11 * p10 % mod * M2[i] % mod +
                11 * (10 * b % mod + 1) % mod) %
               mod;
  }
  cin >> L >> R;
  cout << (calc(R) + mod - calc(L)) % mod << endl;
  return 0;
}
