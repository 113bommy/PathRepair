#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
bitset<(101 * 101 * 101)> B;
vector<int> g[(101 * 101 * 101)];
char s[(101)][(101)][(101)];
int N, M, K, I[(101)][(101)][(101)], C, sx[] = {1, 0, 0}, sy[] = {0, 1, 0},
                                        sz[] = {0, 0, 1}, a, b, c, S,
                                        D[(101 * 101 * 101)];
int main(void) {
  scanf("%d%d%d", &N, &M, &K);
  for (int i(0); i < N; i++)
    for (int j(0); j < M; j++) scanf("%s", s[i][j]);
  for (int i(0); i < N; i++)
    for (int j(0); j < M; j++)
      for (int k(0); k < K; k++) I[i][j][k] = C++;
  for (int i(0); i < N; i++)
    for (int j(0); j < M; j++)
      for (int k(0); k < K; k++)
        if (s[i][j][k] - 48)
          for (int l(0); l < 3; l++) {
            a = i + sx[l], b = j + sy[l], c = k + sz[l];
            if (s[a][b][c] == 49) (g[I[i][j][k]].push_back(I[a][b][c]));
          }
  for (int i(0); i < C; i++) {
    for (auto &h : g[i])
      for (auto &w : g[h]) ++D[w];
    for (auto &h : g[i])
      for (auto &w : g[h])
        if (1 == D[w]) B[w] = 1;
    for (auto &h : g[i])
      for (auto &w : g[h]) D[w] = 0;
  }
  printf("%d\n", int(B.count()));
  return 0;
}
