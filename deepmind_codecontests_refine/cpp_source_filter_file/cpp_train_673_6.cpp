#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100010, MOD = 1000000007;
int N, K, S[10 * NMAX], A[NMAX], B[NMAX], X[NMAX], MarsUp[NMAX], MarsDown[NMAX],
    Ans, Pow2[10 * NMAX];
int Anc[20][NMAX], Level[NMAX];
vector<int> G[NMAX];
bool Used[NMAX];
void DFS(int Node, int Father) {
  Used[Node] = 1;
  Anc[0][Node] = Father;
  Level[Node] = Level[Father] + 1;
  for (int i = 0; i < G[Node].size(); ++i) {
    int Vec = G[Node][i];
    if (!Used[Vec]) DFS(Vec, Node);
  }
}
void BuildAnc() {
  for (int i = 1; (1 << i) <= N; ++i)
    for (int j = 1; j <= N; ++j) Anc[i][j] = Anc[i - 1][Anc[i - 1][j]];
}
int GetLCA(int X, int Y) {
  if (Level[X] < Level[Y]) swap(X, Y);
  for (int i = 19; i >= 0; --i)
    if (Level[X] - (1 << i) >= Level[Y]) X = Anc[i][X];
  if (X == Y) return X;
  for (int i = 19; i >= 0; --i)
    if (Anc[i][X] && Anc[i][X] != Anc[i][Y]) X = Anc[i][X], Y = Anc[i][Y];
  return Anc[0][X];
}
void DFS_Mars(int Node, int Father) {
  for (int i = 0; i < G[Node].size(); ++i) {
    int Vec = G[Node][i];
    if (Vec != Father) DFS_Mars(Vec, Node);
  }
  for (int i = 0; i < G[Node].size(); ++i) {
    int Vec = G[Node][i];
    if (Vec != Father)
      MarsUp[Node] += MarsUp[Vec], MarsDown[Node] += MarsDown[Vec];
  }
}
int main() {
  Pow2[0] = 1;
  for (int i = 1; i < 10 * NMAX; ++i) Pow2[i] = (1LL * Pow2[i - 1] * 2) % MOD;
  scanf("%i", &N);
  for (int i = 1; i < N; ++i) {
    scanf("%i %i %i", &A[i], &B[i], &X[i]);
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  DFS(1, 0);
  BuildAnc();
  scanf("%i", &K);
  for (int i = 1; i <= K; ++i) scanf("%i", &S[i]);
  S[0] = 1;
  for (int i = 0; i < K; ++i) {
    int LCA = GetLCA(S[i], S[i + 1]);
    MarsUp[S[i]]++;
    MarsUp[LCA]--;
    MarsDown[S[i + 1]]++;
    MarsDown[LCA]--;
  }
  DFS_Mars(1, 0);
  for (int i = 1; i < N; ++i) {
    if (X[i] == 0) continue;
    if (Level[A[i]] + 1 == Level[B[i]])
      Ans = (Ans + Pow2[MarsDown[B[i]]] - 1) % MOD;
    else
      Ans = (Ans + Pow2[MarsUp[A[i]]] - 1) % MOD;
    if (Ans < 0) Ans += MOD;
  }
  printf("%i\n", Ans);
}
