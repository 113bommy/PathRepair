#include <bits/stdc++.h>
using namespace std;
int n, m, G, S, f[202], st[50002], top, edge;
long long ans;
struct coord {
  int x, y, s, g;
} v[50002];
int root(int x) {
  if (!f[x]) return x;
  return f[x] = root(f[x]);
}
int cmp(const coord a, const coord b) { return a.g < b.g; }
void read() {
  scanf("%d %d %d %d\n", &n, &m, &G, &S);
  for (int i = 1; i <= m; ++i)
    scanf("%d %d %d %d", &v[i].x, &v[i].y, &v[i].g, &v[i].s);
}
void solve() {
  int i, j;
  sort(v + 1, v + m + 1, cmp);
  ans = 2000000000000000000LL;
  for (i = 1; i <= m; ++i) {
    memset(f, 0, sizeof(f));
    edge = 0;
    for (j = top; j >= 1; --j)
      if (v[st[j]].s > v[i].s)
        st[j + 1] = st[j];
      else
        break;
    ++top;
    st[j + 1] = i;
    for (j = 1; j <= top && (edge < n - 1); ++j) {
      int rx = root(v[st[j]].x), ry = root(v[st[j]].y);
      if (rx != ry) {
        st[++edge] = st[j];
        f[rx] = ry;
      }
    }
    if (edge == n - 1)
      ans = min(ans, 1LL * S * v[st[edge]].s + 1LL * G * v[i].g);
    top = edge;
  }
}
void write() {
  if (edge < n - 1)
    printf("-1\n");
  else
    printf("%I64d\n", ans);
}
int main() {
  read();
  solve();
  write();
  return 0;
}
