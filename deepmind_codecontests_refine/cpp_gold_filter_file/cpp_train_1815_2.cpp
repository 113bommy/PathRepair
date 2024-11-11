#include <bits/stdc++.h>
using namespace std;
int n, q;
const long long mod = 1e9 + 7;
long long sumx[3 * 100010 << 2], sumk[3 * 100010 << 2];
int lsec[3 * 100010], rsec[3 * 100010];
long long level[3 * 100010];
int dfn = 0;
vector<int> edge[3 * 100010];
void dfs(int u) {
  lsec[u] = ++dfn;
  for (int i = 0; i < edge[u].size(); ++i) {
    int v = edge[u][i];
    level[v] = level[u] + 1;
    dfs(v);
  }
  rsec[u] = dfn;
}
void build(int l, int r, int rt) {
  sumx[rt] = sumk[rt] = 0;
  if (l == r) return;
  int mid = l + r >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
}
void pushdown(int rt) {
  sumx[rt << 1] = (sumx[rt << 1] + sumx[rt]) % mod;
  sumx[rt << 1 | 1] = (sumx[rt << 1 | 1] + sumx[rt]) % mod;
  sumk[rt << 1] = (sumk[rt << 1] + sumk[rt]) % mod;
  sumk[rt << 1 | 1] = (sumk[rt << 1 | 1] + sumk[rt]) % mod;
  sumx[rt] = sumk[rt] = 0;
}
void insert(int L, int R, int x, int k, int l, int r, int rt) {
  if (L <= l && r <= R) {
    sumx[rt] = (sumx[rt] + x) % mod;
    sumk[rt] = (sumk[rt] + k) % mod;
    return;
  }
  int mid = l + r >> 1;
  pushdown(rt);
  if (L <= mid) insert(L, R, x, k, l, mid, rt << 1);
  if (R > mid) insert(L, R, x, k, mid + 1, r, rt << 1 | 1);
}
void query(int L, int R, long long &ansx, long long &ansk, int l, int r,
           int rt) {
  if (L <= l && r <= R) {
    ansx = sumx[rt];
    ansk = sumk[rt];
    return;
  }
  int mid = l + r >> 1;
  pushdown(rt);
  if (R > mid)
    query(L, R, ansx, ansk, mid + 1, r, rt << 1 | 1);
  else
    query(L, R, ansx, ansk, l, mid, rt << 1);
}
int main() {
  cin >> n;
  int fa;
  for (int i = 2; i <= n; ++i) {
    cin >> fa;
    edge[fa].push_back(i);
  }
  dfs(1);
  build(1, n, 1);
  cin >> q;
  int op;
  int v;
  long long x, k;
  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> v >> x >> k;
      insert(lsec[v], rsec[v], (x + level[v] * k % mod) % mod, k, 1, n, 1);
    } else {
      cin >> v;
      long long ansx, ansk;
      query(lsec[v], lsec[v], ansx, ansk, 1, n, 1);
      cout << ((ansx - ansk * level[v]) % mod + mod) % mod << endl;
    }
  }
  return 0;
}
