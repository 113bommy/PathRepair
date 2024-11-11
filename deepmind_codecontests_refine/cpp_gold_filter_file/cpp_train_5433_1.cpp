#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using ll = long long;
using VL = vector<ll>;
const int MaxN = 41;
int N, M;
VVI G;
VL adj;
int C{-1}, I{-1};
ll IS{-1};
ll p2[MaxN];
VI vis;
void ReadData();
void Solve();
ll F(VI S);
int CntConnectedComponents();
int CntIsolatedNodes();
ll CntIndependentSets();
ll GetP2(int exp);
bool OddCycle();
void DFS(int node, int val = 1);
int main() {
  ReadData();
  Solve();
  return 0;
}
void ReadData() {
  cin >> N >> M;
  G = VVI(N + 1);
  adj = VL(N + 1);
  int x, y;
  for (int idx = 0; idx < M; ++idx) {
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
    adj[x] |= (1LL << (y - 1));
    adj[y] |= (1LL << (x - 1));
  }
}
void Solve() {
  ll res = F({0, 1, 2});
  res -= F({0, 1});
  res -= F({1, 2});
  res -= F({0, 2});
  res += F({0});
  res += F({1});
  res += F({2});
  res -= F(VI());
  cout << res << '\n';
}
ll F(VI S) {
  if (S.size() == 3 && S[0] == 0 && S[1] == 1 && S[2] == 2) return GetP2(N);
  if (S.size() == 2 && S[0] == 0 && S[1] == 1) return CntIndependentSets();
  if (S.size() == 2 && S[0] == 0 && S[1] == 2)
    return GetP2(CntConnectedComponents());
  if (S.size() == 2 && S[0] == 1 && S[1] == 2) return CntIndependentSets();
  if (S.size() == 1 && S[0] == 0) return GetP2(CntIsolatedNodes());
  if (S.size() == 1 && S[0] == 1)
    return !OddCycle() ? GetP2(CntConnectedComponents()) : 0;
  if (S.size() == 1 && S[0] == 2) return GetP2(CntIsolatedNodes());
  if (S.empty()) return M == 0 ? GetP2(N) : 0;
  return -1;
}
int CntConnectedComponents() {
  if (C != -1) return C;
  vis = VI(N + 1);
  C = 0;
  for (int i = 1; i <= N; ++i)
    if (!vis[i]) {
      DFS(i);
      ++C;
    }
  return C;
}
int CntIsolatedNodes() {
  if (I != -1) return I;
  I = 0;
  for (int i = 1; i <= N; ++i)
    if (G[i].empty()) ++I;
  return I;
}
ll CntIndependentSets() {
  if (IS != -1) return IS;
  int m1{N / 2};
  int m2{N - m1};
  VI nmasks(1 << m2);
  ll mask;
  for (int m = 0; m < (1 << m1); ++m) {
    mask = 0;
    bool ok{true};
    for (int i = 0; i < m1 && ok; ++i)
      if ((1 << i) & m) {
        if (mask & (1 << i)) ok = false;
        mask |= (1 << i);
        mask |= adj[i + 1];
      }
    if (ok) {
      ++nmasks[mask >> m1];
    }
  }
  for (int i = 0; i < m2; ++i)
    for (int m = 0; m < (1 << m2); ++m)
      if (m & (1 << i)) nmasks[m] += nmasks[m ^ (1 << i)];
  ll ans{0};
  for (int m = 0; m < (1 << m2); ++m) {
    mask = 0;
    bool ok{true};
    for (int i = m1; i < N && ok; ++i)
      if ((1 << (i - m1)) & m) {
        if (mask & (1LL << i)) ok = false;
        mask |= (1LL << i);
        mask |= adj[i + 1];
      }
    if (ok) {
      ans += 1LL * nmasks[m ^ ((1 << m2) - 1)];
    }
  }
  return IS = ans;
}
ll GetP2(int exp) {
  if (exp == 0) return 1;
  if (p2[exp] != 0) return p2[exp];
  return p2[exp] = 2LL * GetP2(exp - 1);
}
bool OddCycle() {
  vis = VI(N + 1);
  for (int i = 1; i <= N; ++i)
    if (!vis[i]) DFS(i);
  for (int i = 1; i <= N; ++i)
    for (const int& v : G[i])
      if (vis[i] == vis[v]) return true;
  return false;
}
void DFS(int node, int val) {
  vis[node] = val;
  for (const int& v : G[node])
    if (!vis[v]) DFS(v, 3 - val);
}
