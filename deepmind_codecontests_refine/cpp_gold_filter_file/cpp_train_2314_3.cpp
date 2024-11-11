#include <bits/stdc++.h>
using namespace std;
const int M = 300005;
int read() {
  int x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, m, cnt, a[M], fa[M];
pair<int, int> tmp[M], b[M][2];
long long ans;
int find(int x) {
  if (x != fa[x]) fa[x] = find(fa[x]);
  return fa[x];
}
void merge(int u, int v) {
  int x = find(u), y = find(v);
  fa[x] = y;
}
void solve() {
  for (int i = 0; i < m; i++) b[i][0] = b[i][1] = tmp[i] = make_pair(-1, -1);
  for (int i = 1; i <= n; i++) {
    int id = find(i);
    if (b[a[i]][0].second == -1)
      b[a[i]][0] = make_pair(a[i], id);
    else if (b[a[i]][1].second == -1 && b[a[i]][0].second != id)
      b[a[i]][1] = make_pair(a[i], id);
  }
  for (int i = 0; i < 18; i++)
    for (int s = 0; s < m; s++)
      if ((s >> i) & 1) {
        int t = s ^ (1 << i);
        for (int j = 0; j < 2; j++) {
          if (b[t][j].first > b[s][0].first) {
            if (b[s][0].second != b[t][j].second) b[s][1] = b[s][0];
            b[s][0] = b[t][j];
          } else if (b[t][j].first > b[s][1].first &&
                     b[s][0].second != b[t][j].second)
            b[s][1] = b[t][j];
        }
      }
  for (int i = 1; i <= n; i++) {
    int s = (m - 1) ^ a[i], id = find(i);
    if (b[s][0].first != -1 && b[s][0].first + a[i] > tmp[id].first &&
        b[s][0].second != id)
      tmp[id] = b[s][0], tmp[id].first += a[i];
    if (b[s][1].first != -1 && b[s][1].first + a[i] > tmp[id].first &&
        b[s][1].second != id)
      tmp[id] = b[s][1], tmp[id].first += a[i];
  }
  for (int i = 1; i <= n; i++)
    if (tmp[i].first != -1 && find(i) != find(tmp[i].second))
      merge(i, tmp[i].second), ans += tmp[i].first, cnt--;
}
signed main() {
  cnt = n = read() + 1;
  m = 1 << 18;
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i < n; i++) a[i] = read(), ans -= a[i];
  while (cnt > 1) solve();
  printf("%lld\n", ans);
}
