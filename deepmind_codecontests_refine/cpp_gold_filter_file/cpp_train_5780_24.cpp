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
long long xo(long long i) {
  if ((i & 3) == 0) return i;
  if ((i & 3) == 1) return 1;
  if ((i & 3) == 2) return i + 1;
  return 0;
}
struct edge {
  long long id, u, v, w, b;
} e[100005];
long long au[100005], av[100005];
bool cmp(edge a, edge b) { return a.b == b.b ? a.w < b.w : a.b > b.b; }
int main() {
  long long n, m, i, j, k;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    e[i].id = i;
    cin >> e[i].w >> e[i].b;
  }
  sort(e + 1, e + m + 1, cmp);
  for (i = 1; i < n; i++) e[i].u = i, e[i].v = i + 1;
  long long p = 0, q = 2;
  for (i = n; i <= m; i++) {
    if (p + 2 == q)
      q++, p = 1;
    else
      p++;
    if (e[i].w < e[q - 1].w) {
      cout << -1;
      return 0;
    }
    e[i].u = p;
    e[i].v = q;
  }
  for (i = 1; i <= m; i++) {
    au[e[i].id] = e[i].u;
    av[e[i].id] = e[i].v;
  }
  for (i = 1; i <= m; i++) cout << au[i] << " " << av[i] << endl;
}
