#include <bits/stdc++.h>
using namespace std;
int n, q, p, rmq1[17][100002], rmq2[17][100002], in[100002], lvl[200002],
    lg[200002];
int poz1[17][100002], poz2[17][100002];
int k, Lca[18][200002];
vector<int> G[100002];
int euler[200002];
void dfs(int x, int p, int l = 0) {
  euler[++k] = x;
  in[x] = k;
  lvl[k] = l;
  rmq1[0][x] = in[x];
  rmq2[0][x] = in[x];
  poz1[0][x] = x;
  poz2[0][x] = x;
  for (auto it : G[x]) {
    if (it == p) continue;
    dfs(it, x, l + 1);
    euler[++k] = x;
    lvl[k] = l;
  }
}
void Rmq() {
  for (int i = 1; i <= k; i++) Lca[0][i] = i;
  for (int i = 1; (1 << i) < k; i++)
    for (int j = 1; j <= k - (1 << i) + 1; j++) {
      int aux = 1 << (i - 1);
      if (lvl[Lca[i - 1][j + aux]] < lvl[Lca[i - 1][j]])
        Lca[i][j] = Lca[i - 1][j + aux];
      else
        Lca[i][j] = Lca[i - 1][j];
    }
  for (int i = 2; i <= k; i++) lg[i] = lg[i / 2] + 1;
}
int lca(int x, int y) {
  if (x == -1) return y;
  if (y == -1) return x;
  int st = in[x], dr = in[y];
  if (st > dr) swap(st, dr);
  int dist = dr - st + 1;
  int ans = Lca[lg[dist]][st];
  int aux = dist - (1 << lg[dist]);
  if (lvl[ans] > lvl[Lca[lg[dist]][st + aux]]) ans = Lca[lg[dist]][st + aux];
  return euler[ans];
}
void calc(int l, int r, int &x, int &y) {
  if (l > r) {
    x = y = -1;
    return;
  }
  int i = lg[r - l + 1];
  int a = rmq1[i][l];
  int b = rmq1[i][r - (1 << i) + 1];
  if (a < b)
    x = poz1[i][l];
  else
    x = poz1[i][r - (1 << i) + 1];
  a = rmq2[i][l];
  b = rmq2[i][r - (1 << i) + 1];
  if (a > b)
    y = poz2[i][l];
  else
    y = poz2[i][r - (1 << i) + 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    cin >> p;
    G[i].push_back(p);
    G[p].push_back(i);
  }
  dfs(1, 0);
  for (int i = 1; (1 << i) <= n; i++)
    for (int j = 1; j <= n - (1 << i) + 1; j++) {
      rmq1[i][j] = min(rmq1[i - 1][j], rmq1[i - 1][j + (1 << (i - 1))]);
      if (rmq1[i - 1][j] < rmq1[i - 1][j + (1 << (i - 1))])
        poz1[i][j] = poz1[i - 1][j];
      else
        poz1[i][j] = poz1[i - 1][j + (1 << (i - 1))];
      rmq2[i][j] = max(rmq2[i - 1][j], rmq2[i - 1][j + (1 << (i - 1))]);
      if (rmq2[i - 1][j] > rmq2[i - 1][j + (1 << (i - 1))])
        poz2[i][j] = poz2[i - 1][j];
      else
        poz2[i][j] = poz2[i - 1][j + (1 << (i - 1))];
    }
  Rmq();
  int l, r;
  while (q--) {
    cin >> l >> r;
    int x, y;
    calc(l, r, x, y);
    int p, q;
    calc(l, x - 1, p, q);
    int u, v;
    calc(x + 1, r, u, v);
    int nod1 = lca(p, q);
    int nod2 = lca(u, v);
    int nod3 = lca(nod1, nod2);
    calc(l, y - 1, p, q);
    calc(y + 1, r, u, v);
    nod1 = lca(p, q);
    nod1 = lca(p, q);
    nod2 = lca(u, v);
    int nod4 = lca(nod1, nod2);
    if (lvl[in[nod3]] < lvl[in[nod4]]) {
      cout << y << " ";
    } else
      cout << x << " ";
    cout << max(lvl[in[nod3]], lvl[in[nod4]]) << "\n";
  }
  return 0;
}
