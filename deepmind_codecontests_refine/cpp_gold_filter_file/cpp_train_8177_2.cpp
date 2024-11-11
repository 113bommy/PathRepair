#include <bits/stdc++.h>
using namespace std;
struct pat {
  int x, y;
  pat(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator<(const pat &p) const { return x == p.x ? y < p.y : x < p.x; }
};
template <typename TP>
inline void read(TP &tar) {
  TP ret = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    ret = ret * 10 + (ch - '0');
    ch = getchar();
  }
  tar = ret * f;
}
template <typename TP, typename... Args>
inline void read(TP &t, Args &...args) {
  read(t), read(args...);
}
namespace RKK {
const int N = 2011, M = 500011;
int n, m;
bitset<N << 1> a[N];
int ex[M], ey[M];
void gauss() {
  for (int l = 1; l <= n; l++) {
    int e = 0;
    for (int i = l; i <= n; i++)
      if (a[i][l]) {
        e = i;
        break;
      }
    if (!e) return (void)(cerr << "WDNMD" << endl);
    if (e && e != l) swap(a[e], a[l]);
    for (int i = 1; i <= n; i++)
      if (i != l && a[i][l]) a[i] ^= a[l];
  }
}
int main() {
  read(n, m);
  for (int i = 1; i <= m; i++) read(ex[i], ey[i]), a[ex[i]][ey[i]] = 1;
  for (int i = 1; i <= n; i++) a[i][n + i] = 1;
  gauss();
  for (int i = 1; i <= m; i++) puts(a[ey[i]][n + ex[i]] ? "NO" : "YES");
  return 0;
}
}  // namespace RKK
int main() { return RKK::main(); }
