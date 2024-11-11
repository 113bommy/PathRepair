#include <bits/stdc++.h>
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline void sub(long long &a, long long b) {
  a -= b;
  if (a < 0) a += 998244353;
}
inline void add(long long &a, long long b) {
  a += b;
  if (a >= 998244353) a -= 998244353;
}
template <typename T>
inline T const &MAX(T const &a, T const &b) {
  return a > b ? a : b;
}
template <typename T>
inline T const &MIN(T const &a, T const &b) {
  return a < b ? a : b;
}
inline long long qp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 998244353;
    a = a * a % 998244353, b >>= 1;
  }
  return ans;
}
inline long long qp(long long a, long long b, long long c) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % c;
    a = a * a % c, b >>= 1;
  }
  return ans;
}
using namespace std;
const unsigned long long ba = 233;
const double eps = 1e-5;
const long double pi = acos(-1);
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 300000 + 10, maxn = 2000000 + 10, inf = 0x3f3f3f3f;
int fa[N][20], dep[N], a[N];
int lca(int a, int b) {
  if (dep[a] > dep[b]) swap(a, b);
  for (int i = 19; ~i; i--)
    if (((dep[b] - dep[a]) >> i) & 1) b = fa[b][i];
  if (a == b) return a;
  for (int i = 19; ~i; i--)
    if (fa[a][i] != fa[b][i]) a = fa[a][i], b = fa[b][i];
  return fa[a][0];
}
int cal(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
int main() {
  int n;
  scanf("%d", &n);
  set<int> s1, s2;
  s1.insert(1);
  int mx = 1;
  for (int i = 2; i <= n + 1; i++) {
    int x;
    scanf("%d", &x);
    fa[i][0] = x;
    dep[i] = dep[x] + 1;
    for (int j = 1; j < 20; j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
    int x1 = s1.size() ? cal(i, *s1.begin()) : 0;
    int x2 = s2.size() ? cal(i, *s2.begin()) : 0;
    if (max(x1, x2) > mx) {
      mx = max(x1, x2);
      if (mx == x1) {
        for (int p : s2)
          if (cal(p, i) == mx) s1.insert(p);
        s2.clear();
        s2.insert(i);
      } else {
        for (int p : s1)
          if (cal(p, i) == mx) s2.insert(p);
        s1.clear();
        s1.insert(i);
      }
    } else if (max(x1, x2) == mx) {
      if (x1 > x2)
        s2.insert(i);
      else
        s1.insert(i);
    }
    printf("%d\n", s1.size() + s2.size());
  }
  return 0;
}
