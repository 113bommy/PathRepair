#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
const int N = 150;
const long long inf = 1e18;
struct E {
  int x, y, z;
  void get() { x = read() - 1, y = read() - 1, z = read(); }
  friend bool operator<(const E a, const E b) { return a.z < b.z; }
} e[N];
long long d[N], ans;
bitset<N> v;
int n, m;
struct mt {
  bitset<N> a[N];
  friend bitset<N> operator*(bitset<N> x, mt y) {
    bitset<N> z;
    for (int i = (0); i <= (n - 1); ++i) z[i] = (x & y.a[i]).any();
    return z;
  }
  friend mt operator*(mt x, mt y) {
    mt z;
    for (int i = (0); i <= (n - 1); ++i)
      for (int j = (0); j <= (n - 1); ++j) {
        if (x.a[i][j]) z.a[i] |= y.a[j];
      }
    return z;
  }
} a;
inline void fpow(mt x, int y, bitset<N> &z) {
  while (y) {
    if (y & 1) z = z * x;
    y >>= 1;
    x = x * x;
  }
}
int main() {
  n = read(), m = read();
  for (int i = (1); i <= (m); ++i) e[i].get();
  sort(e + 1, e + m + 1);
  v[0] = 1;
  ans = inf;
  int t = 0;
  for (int i = (1); i <= (m); ++i) {
    if (e[i].z >= ans) break;
    int tim = e[i].z - t;
    fpow(a, tim, v);
    a.a[e[i].y][e[i].x] = 1;
    t = e[i].z;
    queue<int> q;
    for (int x = (0); x <= (n - 1); ++x) {
      if (v[x])
        q.push(x), d[x] = 0;
      else
        d[x] = inf;
    }
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y = (0); y <= (n - 1); ++y) {
        if (a.a[y][x] && d[y] == inf) {
          d[y] = d[x] + 1;
          q.push(y);
        }
      }
    }
    ans = min(ans, t + d[n - 1]);
  }
  if (ans == inf)
    puts("Impossible");
  else
    printf("%lld\n", ans);
  return 0;
}
