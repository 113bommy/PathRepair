#include <bits/stdc++.h>
using namespace std;
const int NMax = 100005;
const int INF = 1000000005;
int N, M;
vector<int> G[NMax];
int Furthest[NMax];
int Path[NMax], top, Pos[NMax], Cycle[NMax], cycle, PCycle[NMax], startNode,
    totalPaths, nbPaths[NMax], resNode = -1, copyCycle[NMax];
bool Used[NMax];
void Read() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
  }
}
void initializeUsed() {
  for (int i = 1; i <= N; i++) Used[i] = false;
}
void findCycle(int node) {
  Used[node] = true;
  Path[++top] = node;
  Pos[node] = top;
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i];
    if (Used[neighb] && cycle == 0 && Pos[neighb] != 0)
      for (int i = Pos[neighb]; i <= top; i++)
        Cycle[++cycle] = Path[i], PCycle[Path[i]] = cycle;
    if (!Used[neighb]) findCycle(neighb);
  }
  Pos[node] = 0;
  --top;
}
int DistOnCycle(int a, int b) {
  if (a < b) return b - a;
  return cycle - a + b;
}
int DFS(int node) {
  if (Furthest[node] != -1) return Furthest[node];
  int Max = 0, pMax = 0;
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i];
    if (!Used[neighb] && PCycle[neighb] == 0) {
      int resNeighb = DFS(neighb);
      if (resNeighb != 0 &&
          Max < DistOnCycle(PCycle[startNode], PCycle[resNeighb])) {
        Max = DistOnCycle(PCycle[startNode], PCycle[resNeighb]);
        pMax = resNeighb;
      }
    }
    if (PCycle[neighb] != 0) {
      int resNeighb = neighb;
      if (resNeighb != 0 &&
          Max < DistOnCycle(PCycle[startNode], PCycle[resNeighb])) {
        Max = DistOnCycle(PCycle[startNode], PCycle[resNeighb]);
        pMax = resNeighb;
      }
    }
  }
  Furthest[node] = pMax;
  return pMax;
}
void findPaths() {
  initializeUsed();
  for (int i = 1; i <= cycle; i++) {
    startNode = Cycle[i];
    int Max = 0, pMax = 0;
    for (int j = 0; j < G[startNode].size(); j++) {
      int neighb = G[startNode][j];
      if (PCycle[neighb] == 0) {
        int resNeighb = DFS(neighb);
        if (resNeighb != 0 &&
            Max < DistOnCycle(PCycle[startNode], PCycle[resNeighb])) {
          Max = DistOnCycle(PCycle[startNode], PCycle[resNeighb]);
          pMax = resNeighb;
        }
      }
      if (PCycle[neighb] != 0) {
        int resNeighb = neighb;
        if (resNeighb != 0 &&
            Max < DistOnCycle(PCycle[startNode], PCycle[resNeighb])) {
          Max = DistOnCycle(PCycle[startNode], PCycle[resNeighb]);
          pMax = resNeighb;
        }
      }
    }
    if (pMax != 0) {
      ++totalPaths;
      nbPaths[PCycle[pMax]]++;
      if (PCycle[startNode] != cycle) nbPaths[PCycle[startNode] + 1]--;
      if (PCycle[startNode] < PCycle[pMax]) nbPaths[1]++;
    }
  }
}
void findResult() {
  for (int i = 1; i <= cycle; i++) {
    nbPaths[i] += nbPaths[i - 1];
    if (nbPaths[i] == totalPaths) {
      resNode = Cycle[i];
      return;
    }
  }
}
bool checkWithoutCycle() {
  initializeUsed();
  for (int i = 1; i <= cycle; i++) Used[Cycle[i]] = true;
  for (int i = 1; i <= N; i++) PCycle[i] = 0, Path[i] = 0;
  cycle = 0;
  top = 0;
  for (int i = 1; i <= N; i++) {
    if (!Used[i] && cycle == 0) findCycle(i);
  }
  return (cycle == 0);
}
bool checkValidity() {
  initializeUsed();
  Used[resNode] = true;
  for (int i = 1; i <= N; i++) PCycle[i] = 0, Path[i] = 0;
  cycle = 0;
  top = 0;
  for (int i = 1; i <= N; i++) {
    if (!Used[i] && cycle == 0) findCycle(i);
  }
  return (cycle == 0);
}
int main() {
  Read();
  for (int i = 1; i <= N; i++) {
    if (!Used[i] && cycle == 0) findCycle(i);
    Furthest[i] = -1;
  }
  int newCycle = cycle;
  for (int i = 1; i <= cycle; i++) copyCycle[i] = Cycle[i];
  if (checkWithoutCycle()) {
    printf("-1\n");
    return 0;
  }
  cycle = newCycle;
  for (int i = 1; i <= cycle; i++)
    Cycle[i] = copyCycle[i], PCycle[Cycle[i]] = i;
  findPaths();
  findResult();
  if (resNode == -1)
    printf("-1\n");
  else {
    if (checkValidity())
      printf("%d\n", resNode);
    else
      printf("-1\n");
  }
  return 0;
}
