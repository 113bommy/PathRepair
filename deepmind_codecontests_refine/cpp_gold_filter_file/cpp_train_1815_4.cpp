#include <bits/stdc++.h>
using namespace std;
ifstream in("test.in");
ofstream out("test.out");
const int DIM = 3e5 + 5;
const int MOD = 1e9 + 7;
int lev[DIM], lef[DIM], rig[DIM];
vector<int> edg[DIM];
pair<int, int> sgt[2][DIM << 2];
void dfs(int x, int f, int &dt) {
  lev[x] = lev[f] + 1;
  lef[x] = ++dt;
  for (int y : edg[x]) dfs(y, x, dt);
  rig[x] = dt;
  return;
}
void update_l(int k, int n, int l, int r) {
  if (sgt[k][n].second != 0) {
    sgt[k][n].first = (sgt[k][n].first + sgt[k][n].second) % MOD;
    if (l != r) {
      sgt[k][n << 1].second = (sgt[k][n << 1].second + sgt[k][n].second) % MOD;
      sgt[k][n << 1 | 1].second =
          (sgt[k][n << 1 | 1].second + sgt[k][n].second) % MOD;
    }
    sgt[k][n].second = 0;
  }
  return;
}
void update(int k, int n, int l, int r, int st, int en, int x) {
  update_l(k, n, l, r);
  if (l > r || l > en || st > r) return;
  if (st <= l && r <= en) {
    sgt[k][n].second += x;
    update_l(k, n, l, r);
    return;
  }
  int m = (l + r) >> 1;
  update(k, n << 1, l, m, st, en, x);
  update(k, n << 1 | 1, m + 1, r, st, en, x);
  sgt[k][n].first = (sgt[k][n << 1].first + sgt[k][n << 1 | 1].first) % MOD;
  return;
}
long long query(int k, int n, int l, int r, int p) {
  update_l(k, n, l, r);
  if (l == r) return sgt[k][n].first;
  int m = (l + r) >> 1;
  if (p <= m)
    return query(k, n << 1, l, m, p);
  else
    return query(k, n << 1 | 1, m + 1, r, p);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    edg[x].push_back(i);
  }
  int dt = 0;
  dfs(1, 0, dt);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int v, x, k;
      cin >> v >> x >> k;
      update(0, 1, 1, n, lef[v], rig[v], (x + 1LL * lev[v] * k) % MOD);
      update(1, 1, 1, n, lef[v], rig[v], k);
    } else {
      int v;
      cin >> v;
      cout << (query(0, 1, 1, n, lef[v]) -
               1LL * lev[v] * query(1, 1, 1, n, lef[v]) % MOD + MOD) %
                  MOD
           << "\n";
    }
  }
  return 0;
}
