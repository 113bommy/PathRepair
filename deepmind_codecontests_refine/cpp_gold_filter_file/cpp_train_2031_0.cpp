#include <bits/stdc++.h>
int N, M, Q, Log[8192];
int adj[13];
std::vector<std::pair<int, int> > LCA[13];
long long f[13][8192][2];
inline int rev(int x) { return (1 << N) - 1 - x; }
long long DFS(int fa, int p, int set, bool check) {
  if (check) {
    for (auto &pair : LCA[p])
      if (!(set >> pair.first & 1) || !(set >> pair.second & 1)) return 0;
    int Adj = adj[p];
    if (Adj >> fa & 1) Adj -= 1 << fa;
    if ((Adj & set) != Adj) return 0;
  }
  if (set == 1 << p) return 1;
  if (f[p][set][check] != -1) return f[p][set][check];
  int s = set - (1 << p), fe = s & -s, sons = adj[p] & set;
  long long O = 0;
  for (int _i = 0; _i <= s - fe;
       _i = (_i + rev(s - fe) + 1 | rev(s - fe)) - rev(s - fe)) {
    int i = _i + fe;
    bool ok = true;
    for (auto &pair : LCA[p])
      if ((i >> pair.first & 1) && (i >> pair.second & 1)) ok = false;
    if (!ok) continue;
    if (i & sons)
      if (~Log[i & sons])
        O += DFS(fa, p, set - i, false) * DFS(p, Log[i & sons], i, true);
      else
        continue;
    else {
      long long sum = 0;
      for (int j = 0; j < N; j++)
        if (i >> j & 1) sum += DFS(p, j, i, true);
      O += DFS(fa, p, set - i, false) * sum;
    }
  }
  return f[p][set][check] = O;
}
int main() {
  scanf("%d%d%d", &N, &M, &Q);
  for (int i = 0; i < 1 << N; i++) Log[i] = -1;
  for (int i = 0; i < N; i++) Log[1 << i] = i;
  for (int i = 1, u, v; i <= M; i++) {
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u] |= 1 << v;
    adj[v] |= 1 << u;
  }
  for (int i = 1, u, v, l; i <= Q; i++) {
    scanf("%d%d%d", &u, &v, &l);
    u--, v--, l--;
    LCA[l].push_back({u, v});
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < 1 << N; j++)
      for (int k = 0; k < 2; k++) f[i][j][k] = -1;
  printf("%lld\n", DFS(-1, 0, (1 << N) - 1, true));
  return 0;
}
