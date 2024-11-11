#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
using namespace std;
template <class T>
inline T gcd(T x, T y) {
  return y ? gcd(y, x % y) : x;
}
template <class T>
inline T lcm(T x, T y) {
  return x / gcd(x, y) * y;
}
template <class T>
inline void adj(T &x, T y) {
  if (x >= y) x = x % y;
  while (x < 0) x = x + y;
}
template <class T>
inline T qpow(T x, long long y, T z) {
  for (; y; y >>= 1, x = x * x)
    if (y & 1) z = z * x;
  return z;
}
template <class T>
inline T mpow(long long w, T x, long long y, T z) {
  for (; y; y >>= 1, x = x * x, x = x % w)
    if (y & 1) z = z * x, z = z % w;
  return z;
}
template <class T>
inline T exgcd(T a, T b, T &x, T &y) {
  T t = a;
  b ? (t = exgcd(b, a % b, y, x), y = y - (a / b) * x) : (x = 1, y = 0);
  return t;
}
const long long MOD = 1000000007LL;
const int M = 5000005;
const int N = 300005;
int n, a[N], b[N], c[N], bb, cc, ans, t, tt;
vector<int> g[N];
void dfs(int x, int y) {
  for (auto &i : g[x])
    if (i != y) {
      dfs(i, x);
      if ((b[i] == bb && !c[i]) || (!b[i] && c[i] == cc)) ans++;
      b[x] += b[i];
      c[x] += c[i];
    }
  b[x] += (a[x] == 1);
  c[x] += (a[x] == 2);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1) bb++;
    if (a[i] == 2) cc++;
  }
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &t, &tt);
    g[t].push_back(tt);
    g[tt].push_back(t);
  }
  dfs(1, 0);
  printf("%d\n", ans);
  return 0;
}
