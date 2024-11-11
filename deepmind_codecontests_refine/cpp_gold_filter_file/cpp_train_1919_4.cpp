#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 1;
const long long mod = 1e9 + 7;
const int maxn = 3e5 + 5;
long long n, parent[maxn], child[maxn], chainID[maxn], chainHead[maxn], h[maxn],
    nchain(1), ncnt, pos[maxn], x, k, u, i, t;
vector<int> v[maxn];
struct Node {
  long long HKX, K;
};
Node St[4 * maxn];
void Dfs(int x) {
  child[x] = 1;
  for (int j : v[x]) Dfs(j), child[x] += child[j];
}
int Level(int x) {
  if (h[x] == -1) h[x] = Level(parent[x]) + 1;
  return h[x];
}
void HLD(int x) {
  if (chainHead[nchain] == 0) chainHead[nchain] = x;
  chainID[x] = nchain;
  pos[x] = ++ncnt;
  int spe = 0;
  for (int j : v[x])
    if (child[j] > child[spe]) spe = j;
  if (spe != 0) HLD(spe);
  for (int j : v[x])
    if (j != spe) nchain++, HLD(j);
}
void Init() {
  cin >> n;
  for (i = 2; i <= n; ++i) {
    cin >> u;
    parent[i] = u;
    v[u].push_back(i);
  }
  Dfs(1);
  h[1] = 0;
  fill(h + 2, h + n + 1, -1);
  for (i = 1; i <= n; ++i) Level(i);
  HLD(1);
}
void Update(int id, int l, int r, int rang1, int rang2) {
  if (r < rang1 || rang2 < l) return;
  if (rang1 <= l && r <= rang2) {
    St[id].HKX += x + h[u] * k;
    St[id].K += k;
    St[id].HKX %= mod;
    St[id].K %= mod;
    return;
  }
  int mid = (l + r) / 2;
  Update(id * 2, l, mid, rang1, rang2);
  Update(id * 2 + 1, mid + 1, r, rang1, rang2);
}
long long Query(int id, int l, int r, int pos) {
  if (pos < l || pos > r) return 0;
  long long ans = (St[id].HKX - St[id].K * h[u] + mod * mod) % mod;
  if (l == r) return ans;
  int mid = (l + r) / 2;
  ans =
      (ans + Query(id * 2, l, mid, pos) + Query(id * 2 + 1, mid + 1, r, pos)) %
      mod;
  return ans;
}
void Solve() {
  int q, kind;
  cin >> q;
  for (i = 1; i <= q; ++i) {
    cin >> kind;
    if (kind == 1) {
      cin >> u >> x >> k;
      Update(1, 1, n, pos[u], pos[u] + child[u] - 1);
    } else {
      cin >> u;
      cout << Query(1, 1, n, pos[u]) << '\n';
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  Init();
  Solve();
}
