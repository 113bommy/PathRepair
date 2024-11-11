#include <bits/stdc++.h>
using namespace std;
vector<int> ady[405];
int N, M, val[405], low[405], vertices, t;
char v[22], h[22];
void Tarjan(int nodo, int anterior) {
  val[nodo] = low[nodo] = ++t;
  for (int i = 0; i < ady[nodo].size(); i++) {
    int destino = ady[nodo][i];
    if (destino == anterior) continue;
    if (!val[destino]) {
      vertices--;
      Tarjan(destino, nodo);
      low[nodo] = min(low[nodo], low[destino]);
    }
    low[nodo] = min(low[nodo], val[destino]);
    if (low[nodo] == val[nodo] && val[nodo] != 1) {
      printf("NO");
      exit(0);
    }
  }
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++) scanf(" %c", &h[i]);
  for (int j = 1; j <= M; j++) scanf(" %c", &v[j]);
  for (int i = 1; i <= N; i++)
    if (h[i] == '<')
      for (int j = M; j >= 2; j--)
        ady[((i - 1) * M) + j].push_back(((i - 1) * M) + j - 1);
    else
      for (int j = 1; j <= M - 1; j++)
        ady[((i - 1) * M) + j].push_back(((i - 1) * M) + j + 1);
  for (int j = 1; j <= M; j++)
    if (v[j] == '^')
      for (int i = N; i >= 2; i--)
        ady[((i - 1) * M) + j].push_back(((i - 2) * M) + j);
    else
      for (int i = 1; i <= N - 1; i++)
        ady[((i - 1) * M) + j].push_back(((i)*M) + j);
  vertices = N * M;
  Tarjan(1, vertices + 1);
  if (vertices > 1)
    printf("NO");
  else
    printf("YES");
  return 0;
}
