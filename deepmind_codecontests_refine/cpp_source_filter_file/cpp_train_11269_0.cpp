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
  int deg(int v) { return adj[v].size(); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
const int maxk = 1100000, mod = 1000000007;
long long fac[maxk], ifac[maxk];
long long perm(int n, int m) { return n >= m ? fac[n] * ifac[m] % mod : 0; }
long long calc(int w, int k, int upto) {
  long long ret = 0, tot = fpm(k, w, mod), sub = tot,
            invK = fpm(k, mod - 2, mod);
  for (int a = 1; a <= upto; ++a) {
    tot = tot * k % mod;
    if (a <= w) sub = sub * invK % mod;
    ret +=
        tot - perm(k, k - a) * perm(min(k, k - a + w), k - a) % mod * sub % mod;
    ({}), ({}), ({});
  }
  return (ret % mod + mod) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  int k, w;
  cin >> k >> w;
  fac[0] = 1;
  for (int i = 1; i <= k; ++i) fac[i] = fac[i - 1] * i % mod;
  ifac[k] = fpm(fac[k], mod - 2, mod);
  for (int i = k; i; --i) ifac[i - 1] = ifac[i] * i % mod;
  cout << (calc(w - 1, k, k + 1) + mod - calc(w, k, k)) % mod << endl;
  return 0;
}
