#include <bits/stdc++.h>
using namespace std;
const int N = 160;
const long long INF = 1e18;
int n, m;
long long d[N], ans;
bitset<N> v;
template <typename T>
inline void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= f;
}
struct Edge {
  int x, y, z;
  inline void input() {
    read(x), read(y), read(z);
    --x, --y;
  }
  friend bool operator<(Edge a, Edge b) { return a.z < b.z; }
} E[N];
struct Matrix {
  bitset<N> a[N];
  inline friend bitset<N> operator*(bitset<N> x, Matrix y) {
    bitset<N> z;
    for (int i = 0; i < n; ++i) z[i] = (x & y.a[i]).any();
    return z;
  }
  inline friend Matrix operator*(Matrix x, Matrix y) {
    Matrix z;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (x.a[i][j]) z.a[i] |= y.a[j];
    return z;
  }
} a;
inline Matrix quickpow(Matrix x, int y, bitset<N> &z) {
  while (y) {
    if (y & 1) z = z * x;
    x = x * x;
    y >>= 1;
  }
  return x;
}
int main() {
  read(n);
  read(m);
  for (int i = 0; i < m; ++i) E[i].input();
  sort(E, E + m);
  v[0] = true;
  ans = INF;
  for (int i = 0, pre = 0; i < m; ++i) {
    if (E[i].z >= ans) break;
    int o = E[i].z - pre;
    quickpow(a, o, v);
    a.a[E[i].y][E[i].x] = 1;
    pre = E[i].z;
    queue<int> q;
    for (int x = 0; x < n; ++x)
      if (v[x])
        q.push(x), d[x] = 0;
      else
        d[x] = INF;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y = 0; y < n; ++y) {
        if (a.a[y][x] && d[x] + 1 < d[y]) {
          d[y] = d[x] + 1;
          q.push(y);
        }
      }
    }
    chkmin(ans, pre + d[n - 1]);
  }
  if (ans == INF)
    printf("impossible\n");
  else
    printf("%d\n", ans);
  return 0;
}
