#include <bits/stdc++.h>
using namespace std;
const int Maxn = 205;
int N, M, Mod;
int G[Maxn][Maxn];
char a[Maxn][Maxn];
int T[Maxn * Maxn];
int id[Maxn * Maxn];
int Ans;
int Find(int X) { return (~T[X] ? T[X] = Find(T[X]) : X); }
int Guass(int N) {
  int Val = 1;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j) (G[i][j] += Mod) %= Mod;
  for (int i = 1; i <= N; ++i) {
    for (int j = i + 1; j <= N; ++j)
      while (G[j][i]) {
        int p = G[i][i] / G[j][i];
        for (int k = i; k <= N; ++k)
          G[i][k] = (G[i][k] - (long long)G[j][k] * p % Mod + Mod) % Mod,
          swap(G[i][k], G[j][k]);
        Val = (Mod - Val) % Mod;
      }
    Val = (long long)Val * G[i][i] % Mod;
  }
  return Val;
}
void addedge(int u, int v) { --G[u][v], --G[v][u], ++G[u][u], ++G[v][v]; }
void Union(int X, int Y) {
  int Fx = Find(X), Fy = Find(Y);
  if (Fx != Fy) T[Fx] = Fy;
}
void Work(bool b) {
  int n = 0;
  memset(G, 0, sizeof(G)), memset(T, -1, sizeof(T));
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) {
      if (((i + j) & 1) != b && a[i][j] == '/')
        Union((((i + 1) - 1) * (M + 1) + (j)), (((i)-1) * (M + 1) + (j + 1)));
      if (((i + j) & 1) == b && a[i][j] == '\\')
        Union((((i)-1) * (M + 1) + (j)), (((i + 1) - 1) * (M + 1) + (j + 1)));
    }
  for (int i = 1; i <= N + 1; ++i)
    for (int j = 1; j <= M + 1; j++)
      if (((i + j) & 1) == b && T[(((i)-1) * (M + 1) + (j))] == -1)
        id[(((i)-1) * (M + 1) + (j))] = ++n;
  if (n > 201) return;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      if (a[i][j] == '*')
        if (((i + j) & 1) == b)
          addedge(id[Find((((i)-1) * (M + 1) + (j)))],
                  id[Find((((i + 1) - 1) * (M + 1) + (j + 1)))]);
        else
          addedge(id[Find((((i + 1) - 1) * (M + 1) + (j)))],
                  id[Find((((i)-1) * (M + 1) + (j + 1)))]);
  (Ans += Guass(n - 1)) %= Mod;
}
int main() {
  scanf("%d %d %d", &N, &M, &Mod);
  for (int i = 1; i <= N; ++i) scanf("%s", a[i] + 1);
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) {
      if (a[i][j] == '/') G[i][j] = 0;
      if (a[i][j] == '\\') G[i][j] = 1;
      if (a[i][j] == '*') G[i][j] = -1;
    }
  Work(0), Work(1);
  printf("%d", Ans);
  return 0;
}
