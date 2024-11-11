#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 10;
const int MXS = MXN * 4;
const int MXK = 2;
int n, m, k, q, bip;
int U[MXN], V[MXN], E[MXN], C[MXN];
int Nxt[MXN], Last[MXN], Col[MXN];
int Par[MXK][MXN], Sz[MXK][MXN], xr[MXK][MXN];
vector<pair<int, int>> tsk[MXS], hist;
pair<int, int> Find(int c, int x) {
  if (Par[c][x] == x) return make_pair(x, xr[c][x]);
  pair<int, int> nw = Find(c, Par[c][x]);
  nw.second ^= xr[c][x];
  return nw;
}
bool Union(int c, int x, int y) {
  pair<int, int> X = Find(c, x), Y = Find(c, y);
  if (X.first == Y.first) {
    bip &= (X.second != Y.second);
    return 0;
  }
  if (Sz[c][X.first] < Sz[c][Y.first]) swap(X, Y);
  Par[c][Y.first] = X.first, Sz[c][X.first] += Sz[c][Y.first];
  assert(!xr[c][Y.first] && !xr[c][X.first]);
  xr[c][Y.first] ^= 1 ^ X.second ^ Y.second;
  hist.push_back(make_pair(c, Y.first));
  return 1;
}
void Undo() {
  int c, x, y;
  tie(c, y) = hist.back();
  x = Par[c][y], hist.pop_back();
  Sz[c][x] -= Sz[c][y], Par[c][y] = y, xr[c][y] = 0;
}
void Ins(int l, int r, int x, int c, int id = 1, int s = 1, int e = q) {
  if (e < l || s > r || r < l || !c) return;
  if (l <= s && e <= r) {
    tsk[id].push_back(make_pair(c, x));
    return;
  }
  Ins(l, r, x, c, (id * 2), s, ((s + e) / 2)),
      Ins(l, r, x, c, (id * 2 + 1), ((s + e) / 2 + 1), e);
}
void divide(int id, int s, int e) {
  int ted = 0;
  int past = bip;
  for (auto X : tsk[id]) ted += Union(X.first, U[X.second], V[X.second]);
  if (s == e) {
    int u = U[E[s]], v = V[E[s]], nc = C[s];
    if (s > 1) cout << (bip ? "YES\n" : "NO\n");
    if (nc) Ins(s + 1, Nxt[s], E[s], (Col[E[s]] = nc));
    while (ted--) Undo();
    bip = past;
    return;
  }
  divide((id * 2), s, ((s + e) / 2)),
      divide((id * 2 + 1), ((s + e) / 2 + 1), e);
  while (ted--) Undo();
  bip = past;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  q = m, k = bip = 1;
  for (int c = 1; c <= k; c++)
    for (int i = 1; i <= n; i++) Sz[c][i] = 1, Par[c][i] = i;
  map<pair<int, int>, int> mp;
  int rm = 0;
  map<pair<int, int>, int> cnt;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (v < u) swap(u, v);
    cnt[{u, v}]++;
    if (mp.find({u, v}) == mp.end()) {
      mp[{u, v}] = ++rm;
      U[rm] = u, V[rm] = v, Last[rm] = q + 1;
    }
    E[i] = mp[{u, v}];
    C[i] = cnt[{u, v}] % 2;
  }
  m = rm;
  q++;
  m++;
  E[q] = rm, C[q] = 1;
  U[rm] = 1e5 + 2;
  V[rm] = 1e5 + 3;
  Last[rm] = q;
  for (int i = q; i; i--) Nxt[i] = Last[E[i]], Last[E[i]] = i;
  divide(1, 1, q);
  return 0;
}
