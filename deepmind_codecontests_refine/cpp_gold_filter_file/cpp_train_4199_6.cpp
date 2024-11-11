#include <bits/stdc++.h>
using namespace std;
bool Get() {
  char c;
  while (c = getchar(), c != '#' && c != '.')
    ;
  return c == '#';
}
const int inf = 1000000;
bool Map[1000][1000], Flag[1000][1000];
int Fill(int X0, int Y0, int X1, int Y1) {
  int Ans = 0;
  if (X0 == X1) {
    for (int i = Y0; i <= Y1; i++)
      if (!Map[X0][i])
        return -inf;
      else if (!Flag[X0][i]) {
        Flag[X0][i] = true;
        Ans++;
      }
  } else {
    for (int i = X0; i <= X1; i++)
      if (!Map[i][Y0])
        return -inf;
      else if (!Flag[i][Y0]) {
        Flag[i][Y0] = true;
        Ans++;
      }
  }
  return Ans;
}
void Erase(int X0, int Y0, int X1, int Y1) {
  if (X0 == X1)
    for (int i = Y0; i <= Y1; i++) Flag[X0][i] = false;
  else
    for (int i = X0; i <= X1; i++) Flag[i][Y0] = false;
}
int main() {
  int M, N, Size = 0;
  scanf("%d%d", &M, &N);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) Size += Map[i][j] = Get();
  static int X[1000], Y[1000];
  int P = 0, Q = 0;
  for (int i = 0; i < M; i++) {
    bool Find = false;
    for (int j = 1; !Find && j + 1 < N; j++)
      Find = Map[i][j - 1] && Map[i][j] && Map[i][j + 1];
    if (Find) X[P++] = i;
  }
  for (int j = 0; j < N; j++) {
    bool Find = false;
    for (int i = 1; !Find && i + 1 < M; i++)
      Find = Map[i - 1][j] && Map[i][j] && Map[i + 1][j];
    if (Find) Y[Q++] = j;
  }
  if (P > 4) {
    X[2] = X[P - 2];
    X[3] = X[P - 1];
    P = 4;
  }
  if (Q > 4) {
    Y[2] = Y[Q - 2];
    Y[3] = Y[Q - 1];
    Q = 4;
  }
  memset(Flag, 0, sizeof(Flag));
  for (int x0 = 0; x0 < P; x0++)
    for (int y0 = 0; y0 < Q; y0++)
      for (int x1 = x0 + 1; x1 < P; x1++)
        for (int y1 = y0 + 1; y1 < Q; y1++)
          for (int x2 = 0; x2 < P; x2++)
            for (int y2 = 0; y2 < Q; y2++)
              for (int x3 = x2 + 1; x3 < P; x3++)
                for (int y3 = y2 + 1; y3 < Q; y3++) {
                  if (X[x0] == X[x1] - 1) continue;
                  if (X[x2] == X[x3] - 1) continue;
                  if (Y[y0] == Y[y1] - 1) continue;
                  if (Y[y2] == Y[y3] - 1) continue;
                  int Total = 0;
                  Total += Fill(X[x0], Y[y0], X[x0], Y[y1]);
                  Total += Fill(X[x0], Y[y0], X[x1], Y[y0]);
                  Total += Fill(X[x0], Y[y1], X[x1], Y[y1]);
                  Total += Fill(X[x1], Y[y0], X[x1], Y[y1]);
                  Total += Fill(X[x2], Y[y2], X[x2], Y[y3]);
                  Total += Fill(X[x2], Y[y2], X[x3], Y[y2]);
                  Total += Fill(X[x2], Y[y3], X[x3], Y[y3]);
                  Total += Fill(X[x3], Y[y2], X[x3], Y[y3]);
                  if (Total == Size) {
                    printf("YES\n");
                    printf("%d %d %d %d\n", X[x0] + 1, Y[y0] + 1, X[x1] + 1,
                           Y[y1] + 1);
                    printf("%d %d %d %d\n", X[x2] + 1, Y[y2] + 1, X[x3] + 1,
                           Y[y3] + 1);
                    return 0;
                  }
                  Erase(X[x0], Y[y0], X[x0], Y[y1]);
                  Erase(X[x0], Y[y0], X[x1], Y[y0]);
                  Erase(X[x0], Y[y1], X[x1], Y[y1]);
                  Erase(X[x1], Y[y0], X[x1], Y[y1]);
                  Erase(X[x2], Y[y2], X[x2], Y[y3]);
                  Erase(X[x2], Y[y2], X[x3], Y[y2]);
                  Erase(X[x2], Y[y3], X[x3], Y[y3]);
                  Erase(X[x3], Y[y2], X[x3], Y[y3]);
                }
  printf("NO\n");
  return 0;
}
