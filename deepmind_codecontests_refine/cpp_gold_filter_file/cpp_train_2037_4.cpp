#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
template <class T>
inline T isqrt(T k) {
  T r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
template <class T>
inline T icbrt(T k) {
  T r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
const int maxn = 100 + 10;
const int maxk = 40 + 10;
int n, k;
vector<int> adj[maxn];
int dep[maxn];
int f[maxn][maxk][maxk];
void dfs(int u, int p = -1) {
  for (int i = (0); i < (int((adj[u]).size())); i++) {
    int v = adj[u][i];
    if (v != p) {
      dfs(v, u);
      chkmax(dep[u], dep[v] + 1);
    }
  }
}
int calc(int u, int pv, int mn, int p = -1) {
  if (pv > k && mn > k) return 0;
  int& res = f[u][pv][mn];
  if (~res) return res;
  res = 0;
  if (!mn) {
    res = 1;
    for (int i = (0); i < (int((adj[u]).size())); i++) {
      int v = adj[u][i];
      if (v != p) {
        int tmp = 0;
        for (int j = (0); j < (2 * k + 5); j++) {
          addmod(tmp, calc(v, 1, j, u));
        }
        if (dep[v] + 1 <= k) {
          addmod(tmp, 1);
        }
        res = mult(res, tmp);
      }
    }
  } else {
    res = 0;
    int p1 = 1, p2 = 1, tot = 0;
    for (int i = (0); i < (int((adj[u]).size())); i++) {
      int v = adj[u][i];
      if (v != p) {
        tot++;
        int tmp1 = 0, tmp2 = 0;
        for (int j = (mn - 1); j < (2 * k + 5); j++) {
          if (j == mn - 1) {
            addmod(tmp1, calc(v, min(pv + 1, k + 1), j, u));
          } else {
            addmod(tmp1, calc(v, min(min(pv + 1, mn + 1), k + 1), j, u));
            addmod(tmp2, calc(v, min(min(pv + 1, mn + 1), k + 1), j, u));
          }
        }
        if (dep[v] + 1 + min(pv, mn) <= k) {
          addmod(tmp1, 1);
          addmod(tmp2, 1);
        }
        p1 = mult(p1, tmp1);
        p2 = mult(p2, tmp2);
      }
    }
    if (tot) {
      submod(p1, p2);
      res = p1;
    }
  }
  return res;
}
void solve() {
  cin >> n >> k;
  for (int i = (0); i < (n - 1); i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  dfs(0);
  memset(f, -1, sizeof(f));
  int ans = 0;
  for (int i = (0); i < (2 * k + 5); i++) {
    addmod(ans, calc(0, k + 1, i));
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
