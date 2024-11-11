#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, Mod = 1e9 + 7, MAXN = 1e5, Lg = 27, M = 1e7 + 10,
          P = 727, Sq = 320;
const long long inf = 3e18 + 10;
int n, k, Root, Deg[N], Dis[N], Was[N];
set<pair<int, int> > second;
vector<int> Adj[N], V[N];
vector<pair<int, int> > T;
inline void Print() {
  cout << "No";
  exit(0);
}
inline int Find() {
  for (int i = 1; i <= n; i++) second.insert(make_pair(Deg[i], i));
  while (second.size() > 1) {
    T.clear();
    while (second.size() && (*second.begin()).first == 1) {
      T.push_back((*second.begin()));
      second.erase(second.begin());
    }
    if (!T.size()) Print();
    for (int j = 0; j < (int)T.size(); j++) {
      pair<int, int> u = T[j];
      for (int i = 0; i < (int)Adj[u.second].size(); i++) {
        int x = Adj[u.second][i];
        if (!Deg[x]) continue;
        pair<int, int> now = make_pair(Deg[x], x);
        second.erase(now);
        Deg[x]--;
        now.first = Deg[x];
        if (Deg[x]) second.insert(now);
      }
      Was[u.second] = 1;
    }
  }
  int cnt = 0, dx = -1;
  for (int i = 1; i <= n; i++)
    if (!Was[i]) cnt++, dx = i;
  if (cnt > 1 || !cnt)
    return -1;
  else
    return dx;
}
void Dfs(int u, int par) {
  V[Dis[u]].push_back(u);
  for (int i = 0; i < (int)Adj[u].size(); i++)
    if (Adj[u][i] ^ par) Dis[Adj[u][i]] = Dis[u] + 1, Dfs(Adj[u][i], u);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    cin >> x >> y;
    Adj[x].push_back(y), Adj[y].push_back(x);
    Deg[x]++, Deg[y]++;
  }
  if (k > n) Print();
  Root = Find();
  if (Root == -1 || Adj[Root].size() < 3) Print();
  Dfs(Root, Root);
  for (int i = 1; i < k; i++) {
    for (int j = 0; j < (int)V[i].size(); j++) {
      if (Adj[V[i][j]].size() < 4) Print();
    }
  }
  for (int i = 0; i < (int)V[k].size(); i++)
    if (Adj[V[k][i]].size() > 1) Print();
  cout << "Yes";
  return 0;
}
