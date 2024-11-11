#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void umax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void umin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <class T>
inline T gcd(T a, T b) {
  return __gcd(a, b);
}
template <class T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
long long modpow(long long a, long long n, long long temp) {
  long long res = 1, y = a;
  while (n > 0) {
    if (n & 1) res = (res * y) % temp;
    y = (y * y) % temp;
    n /= 2;
  }
  return res % temp;
}
long long p2(long long n) { return (1ll << n); }
long long getbit(long long j, long long i) { return ((i >> (j - 1ll)) & 1ll); }
long long ison(long long mask, long long pos) { return (mask & (1 << pos)); }
long long cbit(long long n) {
  long long k = 0;
  while (n) n &= (n - 1), k++;
  return k;
}
long long nbit(long long n) {
  long long k = 0;
  while (n) n /= 2, k++;
  return k;
}
long long mod = 1e9 + 7;
int sgn(long long x) { return x < 0 ? -1 : !!x; }
const double eps = 1e-7;
const double pi = acos(-1.0);
inline void inc(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline void dec(long long &x, long long y) {
  x -= y;
  if (x < 0) x += mod;
}
inline void chmax(long long &x, long long y) {
  if (y > x) x = y;
}
inline void mulm(long long &x, long long y) {
  x *= y;
  if (x >= mod) x -= mod;
}
long long xo(long long i) {
  if ((i & 3) == 0) return i;
  if ((i & 3) == 1) return 1;
  if ((i & 3) == 2) return i + 1;
  return 0;
}
long long pa[111111], dist[111111], mpath[111111];
vector<long long> adj[111111];
long long dist2[111111];
void dfs(long long v, long long p) {
  pa[v] = p;
  if (p != -1) dist[v] = dist[p] + 1ll;
  for (long long i = 0; i < adj[v].size(); i++) {
    if (adj[v][i] != p) {
      dfs(adj[v][i], v);
      mpath[v] = max(mpath[v], mpath[adj[v][i]] + 1ll);
    }
  }
}
void dfs2(long long v, long long p) {
  if (p != -1) dist2[v] = dist2[p] + 1ll;
  for (long long i = 0; i < adj[v].size(); i++) {
    if (adj[v][i] != p) {
      dfs2(adj[v][i], v);
    }
  }
}
int main() {
  long long x, m, n, k, s, t, j;
  ios_base::sync_with_stdio(0);
  cin >> n >> x;
  for (long long i = 1; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, -1);
  dfs2(x, -1);
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    if (dist2[i] > dist[i]) ans = max(ans, 2 * (dist[i] + mpath[i]));
  }
  cout << ans;
}
