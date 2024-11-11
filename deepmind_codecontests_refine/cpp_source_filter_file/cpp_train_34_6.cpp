#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
const int MAXE = MAXN << 1;
int N;
int e[MAXE], enxt[MAXE], head[MAXN], ec;
void regi(int u, int v) {
  e[++ec] = v;
  enxt[ec] = head[u];
  head[u] = ec;
}
int visId[MAXN];
vector<int> Loop, stk;
bool FindLoop(int ths, int prev) {
  if (visId[ths] != -1) {
    Loop = vector<int>(stk.begin() + visId[ths], stk.end());
    return true;
  }
  visId[ths] = stk.size();
  stk.push_back(ths);
  bool Flag = false;
  for (int E = head[ths]; E; E = enxt[E])
    if ((prev != e[E]) && (FindLoop(e[E], ths))) {
      Flag = true;
      break;
    }
  stk.pop_back();
  visId[ths] = -1;
  return Flag;
}
int Dist[MAXN], Color[MAXN], Father[MAXN], LoopAddress[MAXN];
int Ance[MAXN][13];
void dfs(int cur, int color, int dist, int father) {
  Dist[cur] = dist;
  Color[cur] = color;
  Father[cur] = father;
  Ance[cur][0] = father;
  for (int i = 1; i <= 12; i++) Ance[cur][i] = Ance[Ance[cur][i - 1]][i - 1];
  for (int E = head[cur]; E; E = enxt[E])
    if (Dist[e[E]] > dist + 1) dfs(e[E], color, dist + 1, cur);
}
int lca(int u, int v) {
  if (Dist[u] > Dist[v]) swap(u, v);
  while (Dist[u] != Dist[v]) v = Ance[v][__builtin_ctz(Dist[v] - Dist[u])];
  if (u == v) return u;
  for (int lv = 31 - __builtin_clz(Dist[u]); lv; lv--)
    if (Ance[u][lv] != Ance[v][lv]) {
      u = Ance[u][lv];
      v = Ance[v][lv];
    }
  return Father[u];
}
void MakeDistance() {
  int i;
  for (i = 0; i <= 12; i++) Ance[0][i] = 0;
  for (i = 1; i <= N; i++) Dist[i] = 2333333;
  for (vector<int>::iterator it = Loop.begin(); it != Loop.end(); it++)
    Dist[*it] = 0;
  for (vector<int>::iterator it = Loop.begin(); it != Loop.end(); it++)
    dfs(*it, *it, 0, 0);
}
int main() {
  scanf("%d", &N);
  int i, j;
  for (i = 1; i <= N; i++) head[i] = 0;
  ec = 0;
  for (i = 1; i <= N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    regi(u + 1, v + 1);
    regi(v + 1, u + 1);
  }
  for (i = 1; i <= N; i++) visId[i] = -1;
  stk.clear();
  FindLoop(1, 0);
  for (i = 1; i <= N; i++) LoopAddress[i] = -1;
  for (i = 0; i <= Loop.size() - 1; i++) LoopAddress[Loop[i]] = i;
  MakeDistance();
  double Ans = 0;
  for (i = 1; i <= N; i++)
    for (j = 1; j <= N; j++)
      if (Color[i] == Color[j])
        Ans += 1.0 / (Dist[i] + Dist[j] - 2 * Dist[lca(i, j)] + 1);
      else {
        int MS, B1, B2;
        MS = Dist[i] + Dist[j] + 2;
        B1 = abs(LoopAddress[Color[i]] - LoopAddress[Color[j]]) - 1;
        B2 = Loop.size() - 2 - B1;
        Ans += 1.0 / (MS + B1);
        Ans += 1.0 / (MS + B2);
        Ans -= 1.0 / (MS + B1 + B2);
      }
  printf("%.14f\n", Ans);
}
