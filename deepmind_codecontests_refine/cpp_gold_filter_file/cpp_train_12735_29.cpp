#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100 * 1000 + 10;
int N, M, cur, Root, Brn[MAX_N], Brnstrt[MAX_N], POS[MAX_N], D[MAX_N],
    Deg[MAX_N];
vector<int> adj[MAX_N];
pair<int, int> E[MAX_N];
bool mrk[MAX_N];
struct Type_BIS {
  int Tree[MAX_N];
  int C(int x) {
    int RET = 0;
    for (; x > 0; x -= x & (-x)) RET += Tree[x];
    return RET;
  }
  int Sum(int i, int j) {
    if (j < i) return 0;
    return C(j) - C(i - 1);
  }
  void Add(int x, int val) {
    for (; x <= N; x += x & (-x)) Tree[x] += val;
  }
} BIT;
void DFS(int x) {
  POS[x] = cur++;
  mrk[x] = true;
  for (int i = 0; i < (int)adj[x].size(); i++)
    if (!mrk[adj[x][i]]) {
      if (x == Root)
        Brn[adj[x][i]] = i + 1, Brnstrt[i + 1] = cur;
      else
        Brn[adj[x][i]] = Brn[x];
      D[adj[x][i]] = D[x] + 1;
      DFS(adj[x][i]);
    }
}
int Distance(int u, int v) {
  if (min(Brn[u], Brn[v]) == 0) return max(D[u], D[v]);
  if (Brn[u] == Brn[v]) return max(D[u] - D[v], D[v] - D[u]);
  return D[u] + D[v];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  for (int i = 1; i <= N - 1; i++) {
    cin >> E[i].first >> E[i].second;
    adj[E[i].first].push_back(E[i].second);
    adj[E[i].second].push_back(E[i].first);
    Deg[E[i].first]++;
    Deg[E[i].second]++;
  }
  for (int i = 1; i <= N; i++)
    if (Root == 0 || Deg[Root] < Deg[i]) Root = i;
  DFS(Root);
  cin >> M;
  while (M--) {
    int Type;
    cin >> Type;
    if (Type == 1 || Type == 2) {
      int id;
      cin >> id;
      BIT.Add(max(POS[E[id].first], POS[E[id].second]), (Type == 1 ? -1 : +1));
    } else {
      int u, v;
      cin >> u >> v;
      bool Flag;
      if (u == v)
        Flag = true;
      else if (Brn[u] == Brn[v])
        Flag = (BIT.Sum(min(POS[u], POS[v]) + 1, max(POS[u], POS[v])) == 0);
      else if (min(Brn[u], Brn[v]) == 0)
        Flag = (BIT.Sum(max(Brnstrt[Brn[u]], Brnstrt[Brn[v]]),
                        max(POS[u], POS[v])) == 0);
      else
        Flag = (BIT.Sum(Brnstrt[Brn[u]], POS[u]) == 0) &&
               (BIT.Sum(Brnstrt[Brn[v]], POS[v]) == 0);
      if (!Flag)
        cout << -1 << endl;
      else
        cout << Distance(u, v) << endl;
    }
  }
  return 0;
}
