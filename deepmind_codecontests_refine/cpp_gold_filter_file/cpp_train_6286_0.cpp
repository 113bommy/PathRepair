#include <bits/stdc++.h>
using namespace std;
int fa[505];
int n, m;
int u[10010], v[10010];
vector<int> lft, rht;
int lid[10010], rid[10010], rec[505][505];
inline int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
inline bool Union(int x, int y) {
  return getfa(x) == getfa(y) ? 0 : (fa[getfa(x)] = getfa(y));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &u[i], &v[i]);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    lid[i] = lft.size();
    if (Union(u[i], v[i])) lft.push_back(i);
  }
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = m; i >= 1; i--) {
    rid[i] = rht.size();
    if (Union(u[i], v[i])) rht.push_back(i);
  }
  for (int l = 0; l <= lft.size(); l++) {
    for (int i = 1; i <= n; i++) fa[i] = i;
    int ans = n;
    for (int rl = 0; rl < l; rl++) ans -= Union(u[lft[rl]], v[lft[rl]]);
    for (int r = 0; r <= rht.size(); r++) {
      rec[l][r] = ans;
      if (r < rht.size()) ans -= Union(u[rht[r]], v[rht[r]]);
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int ql, qr;
    scanf("%d%d", &ql, &qr);
    printf("%d\n", rec[lid[ql]][rid[qr]]);
  }
  return 0;
}
