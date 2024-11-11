#include <bits/stdc++.h>
using namespace std;
int rot[100010], vst[100010], h[100010], l[100010], cnt[100010];
int find_root(int u) {
  if (u == rot[u]) return u;
  return rot[u] = find_root(rot[u]);
}
int main() {
  int n, m, u, v, uu, vv, i, j;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    rot[i] = i;
    h[i] = 0;
    l[i] = 0;
    cnt[i] = 1;
  }
  for (i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    uu = find_root(u);
    vv = find_root(v);
    if (uu == vv) {
      l[uu]++;
      continue;
    }
    if (h[uu] > h[vv]) swap(uu, vv);
    rot[uu] = vv;
    h[vv] = max(h[vv], h[uu] + 1);
    l[vv] += l[uu] + 1;
    cnt[vv] += cnt[uu];
  }
  memset(vst, 0, sizeof(vst));
  for (i = 1; i <= n; i++) {
    vst[rot[i]] = 1;
  }
  int jin = 0;
  for (i = 1; i <= n; i++) {
    if (vst[i] == 0) continue;
    if (l[i] == cnt[i] - 1) jin++;
  }
  printf("%d\n", jin);
}
