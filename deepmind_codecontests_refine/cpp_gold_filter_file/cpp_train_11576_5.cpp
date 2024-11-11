#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5 + 10;
const int MXM = 4e5 + 10;
const int MXS = MXN * 4;
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 + hash2;
  }
};
int n, m, k, q, last;
int U[MXM], V[MXM], E[2][MXN], typ[MXN], sit[MXM];
int Nxt[2][MXN], Last[MXM], Par[MXN], Sz[MXN];
vector<int> tsk[MXS], hist;
unordered_map<pair<int, int>, int, hash_pair> mp;
int GetId(int u, int v) {
  if (u > v) swap(u, v);
  if (mp.find(make_pair(u, v)) == mp.end()) {
    mp[make_pair(u, v)] = ++m;
    U[m] = u, V[m] = v;
    return m;
  }
  return mp[make_pair(u, v)];
}
int Find(int x) { return (Par[x] == x ? x : Find(Par[x])); }
bool Union(int x, int y) {
  x = Find(x), y = Find(y);
  if (x == y) return 0;
  if (Sz[x] < Sz[y]) swap(x, y);
  Par[y] = x, Sz[x] += Sz[y];
  hist.push_back(y);
  return 1;
}
void Undo() {
  int x, y = hist.back();
  x = Par[y], hist.pop_back();
  Sz[x] -= Sz[y], Par[y] = y;
}
void Ins(int l, int r, int x, int id = 1, int s = 1, int e = q) {
  if (e < l || s > r || r < l) return;
  if (l <= s && e <= r) {
    tsk[id].push_back(x);
    return;
  }
  Ins(l, r, x, (id * 2), s, ((s + e) / 2)),
      Ins(l, r, x, (id * 2 + 1), ((s + e) / 2 + 1), e);
}
void divide(int id, int s, int e) {
  int ted = 0;
  for (auto X : tsk[id]) ted += Union(U[X], V[X]);
  if (s == e) {
    if (typ[s] == 1) {
      sit[E[last][s]] ^= 1;
      if (sit[E[0][s]]) Ins(s + 1, Nxt[0][s], E[0][s]);
      if (sit[E[1][s]]) Ins(s + 1, Nxt[1][s], E[1][s]);
    } else {
      cout << (last = (Find(U[E[last][s]]) == Find(V[E[last][s]])));
    }
    while (ted--) Undo();
    return;
  }
  divide((id * 2), s, ((s + e) / 2)),
      divide((id * 2 + 1), ((s + e) / 2 + 1), e);
  while (ted--) Undo();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  iota(Par, Par + MXN, 0), fill(Sz, Sz + MXN, 1);
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    int u, v;
    cin >> typ[i] >> u >> v;
    E[0][i] = GetId(u, v);
    u %= n, u++, v %= n, v++;
    E[1][i] = GetId(u, v);
  }
  for (int i = 1; i <= m; i++) Last[i] = q;
  for (int i = q; i; i--) {
    if (typ[i] == 2) continue;
    Nxt[0][i] = Last[E[0][i]];
    Nxt[1][i] = Last[E[1][i]];
    Last[E[0][i]] = Last[E[1][i]] = i;
  }
  divide(1, 1, q);
  return 0;
}
