#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
bitset<4005> f[4005];
int n, m, u[500005], v[500005];
void gauss() {
  for (register int i = (1); i <= (n); ++i) {
    int p = i;
    while (p < n && !f[p][i]) ++p;
    if (i != p) swap(f[i], f[p]);
    for (register int j = (1); j <= (n); ++j)
      if (i != j && f[j][i]) f[j] ^= f[i];
  }
}
signed main() {
  n = read(), m = read();
  for (register int i = (1); i <= (m); ++i)
    u[i] = read(), v[i] = read(), f[u[i]][v[i]] = 1;
  for (register int i = (1); i <= (n); ++i) f[i][i + n] = 1;
  gauss();
  for (register int i = (1); i <= (m); ++i)
    puts(!f[v[i]][u[i] + n] ? "YES" : "NO");
  return 0;
}
