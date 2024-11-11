#include <bits/stdc++.h>
using namespace std;
const int Nn = 1005;
int N, M, Mar[Nn][Nn], All = 0, Gcd, Nx[4] = {1, 0, -1, 0},
                       Ny[4] = {0, 1, 0, -1};
bool Exit() {
  for (int i = 1; i < N; i++)
    for (int j = 1; j < M; j++)
      if (Mar[i][j] && Mar[i + 1][j] && Mar[i + 1][j + 1] && Mar[i][j + 1]) {
        return 1;
      }
  return 0;
}
bool Vis[Nn][Nn], Flag[Nn];
int Calc(int x, int y) {
  if (x < 1 || y < 1 || x > N || y > M) return 0;
  ;
  if (!Mar[x][y] || Vis[x][y]) return 0;
  Vis[x][y] = 1;
  return Calc(x - 1, y) + Calc(x, y - 1) + Calc(x + 1, y) + Calc(x, y + 1) + 1;
}
bool NotOne() {
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      if (Mar[i][j]) {
        return Calc(i, j) != All;
      }
}
int GetGcd(int x, int y) { return y == 0 ? x : GetGcd(y, x % y); }
bool Check() {
  int cont = 0;
  memset(Vis, 0, sizeof(Vis));
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (Mar[i][j]) {
        int cnt = Mar[i][j - 1] + Mar[i - 1][j] + Mar[i][j + 1] + Mar[i + 1][j];
        cont += cnt & 1;
        if (cont >= 3) return 0;
        if (cnt == 2 && ((Mar[i][j - 1] && Mar[i][j + 1]) ||
                         (Mar[i - 1][j] && Mar[i + 1][j])))
          continue;
        Vis[i][j] = 1;
      }
  Gcd = 1;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (Vis[i][j]) {
        int t;
        for (int k = 0; k < 3; k++) {
          for (t = 1; !Vis[i + Nx[k] * t][j + Ny[k] * t] &&
                      Mar[i + Nx[k] * t][j + Ny[k] * t];
               t++)
            ;
          if (t <= 1) continue;
          Flag[t] = 1;
          Gcd = t;
        }
      }
  for (int i = max(N, M); i > 0; i--)
    if (Flag[i]) Gcd = GetGcd(i, Gcd);
  return Gcd > 1;
}
void Print(int x) {
  for (int i = 2; i < x; i++)
    if (x % i == 0) printf("%d ", i);
  printf("%d\n", x);
}
int main() {
  memset(Mar, 0, sizeof(Mar));
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) scanf("%d", &Mar[i][j]), All += Mar[i][j];
  if (Exit() || NotOne()) {
    printf("-1\n");
    return 0;
  }
  if (Check())
    Print(Gcd);
  else
    printf("-1\n");
  return 0;
}
