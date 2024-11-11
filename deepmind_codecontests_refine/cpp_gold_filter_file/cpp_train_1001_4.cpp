#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<pair<int, int> > G[100005];
int Colour[100005], Stack[100005], P[100005], top;
pair<int, int> E[100005];
bool bipartite = 1;
long long Res[100005], C[100005];
vector<int> Cycle;
int Level[100005];
bool Use[100005];
map<pair<int, int>, int> Map;
void Read() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> C[i];
  for (int i = 1; i <= M; i++) {
    int x, y;
    cin >> x >> y;
    Map[make_pair(min(x, y), max(x, y))] = i;
    E[i] = make_pair(x, y);
    G[x].push_back(make_pair(y, i));
    G[y].push_back(make_pair(x, i));
  }
}
void DFS(int node, int colour) {
  Colour[node] = colour;
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i].first;
    if (Colour[neighb] == 0)
      DFS(neighb, 3 - colour);
    else {
      if (Colour[neighb] == Colour[node]) bipartite = 0;
    }
  }
}
void SolveCase1(int node, int father, int edge) {
  long long sum = 0;
  Use[node] = 1;
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i].first, e = G[node][i].second;
    if (neighb == father) continue;
    if (Use[neighb] == 1) continue;
    SolveCase1(neighb, node, e);
    sum += Res[e];
  }
  Res[edge] = C[node] - sum;
}
void findCycle(int node, int father) {
  Use[node] = 1;
  Level[node] = Level[father] + 1;
  Stack[++top] = node;
  P[node] = top;
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i].first, e = G[node][i].second;
    if (neighb == father) continue;
    if (Cycle.size() == 0 && Use[neighb] == 1 && Level[neighb] < Level[node] &&
        (Level[node] - Level[neighb] + 1) % 2 == 1) {
      for (int j = P[neighb]; j <= top; j++) Cycle.push_back(Stack[j]);
    }
    if (Use[neighb] == 0) findCycle(neighb, node);
  }
  --top;
}
void SolveCase2(int node, int father, int edge) {
  long long sum = 0;
  Use[node] = 1;
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i].first, e = G[node][i].second;
    if (neighb == father) continue;
    if (Use[neighb] == 1) continue;
    SolveCase2(neighb, node, e);
    sum += Res[e];
  }
  Res[edge] = C[node] - sum;
}
void Solve() {
  for (int i = 1; i <= N; i++) Use[i] = 0;
  SolveCase2(Cycle[0], 0, 0);
  int edge =
      Map[make_pair(min(Cycle[0], Cycle.back()), max(Cycle[0], Cycle.back()))];
  Res[edge] += Res[0] / 2;
  int sign = 1;
  for (int i = 0; i < Cycle.size() - 1; i++) {
    int e = Map[make_pair(min(Cycle[i], Cycle[i + 1]),
                          max(Cycle[i], Cycle[i + 1]))];
    Res[e] += sign * Res[0] / 2;
    sign *= -1;
  }
}
int main() {
  Read();
  DFS(1, 1);
  if (bipartite == 1) {
    SolveCase1(1, 0, 0);
    if (Res[0] != 0) {
      cout << "NO\n";
      return 0;
    }
  } else {
    findCycle(1, 0);
    Solve();
  }
  cout << "YES\n";
  for (int i = 1; i <= M; i++) cout << Res[i] << "\n";
  return 0;
}
