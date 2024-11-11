#include <bits/stdc++.h>
using namespace std;
const int BLOCK = 316;
const int N = 100100;
const int N2 = N + N;
vector<int> vc, g[N];
int col[N], l[N], r[N], nm[N], fen[N2], kol[N], ans[N];
int tin[N], tout[N], n, q, kl[N];
void dfs(int v, int p) {
  tin[v] = ((int)vc.size());
  vc.push_back(v);
  for (int u : g[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
  tout[v] = ((int)vc.size()) - 1;
}
bool cmp(int x, int y) {
  int lx = l[x] / BLOCK;
  int ly = l[x] / BLOCK;
  if (lx == ly) {
    if (lx & 1)
      return r[x] > r[y];
    else
      return r[x] < r[y];
  } else
    return lx < ly;
}
void update(int x, int vl) {
  for (; x < N2; x = (x | (x + 1))) fen[x] += vl;
}
int sum(int x) {
  int res = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) res += fen[x];
  return res;
}
void add(int ps) {
  int cur = col[vc[ps]];
  update(N + kol[cur], -1);
  kol[cur]++;
  update(N + kol[cur], +1);
}
void del(int ps) {
  int cur = col[vc[ps]];
  update(N + kol[cur], -1);
  kol[cur]--;
  update(N + kol[cur], +1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> col[i];
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0, -1);
  for (int i = 0; i < q; i++) {
    int v;
    cin >> v >> kl[i];
    v--;
    l[i] = tin[v];
    r[i] = tout[v];
    nm[i] = i;
  }
  sort(nm, nm + q, cmp);
  int lf = 0, rt = -1;
  for (int i = 0; i < n; i++) update(N, +1);
  for (int it = 0; it < q; it++) {
    int i = nm[it];
    while (lf < l[i]) del(lf++);
    while (rt < r[i]) add(++rt);
    while (lf > l[i]) add(--lf);
    while (rt > r[i]) del(rt--);
    ans[i] = n - sum(N + kl[i] - 1);
  }
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
  return 0;
}
