#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
vector<pair<int, int> > Q;
vector<int> g[500005];
string s[500005];
pair<int, int> D[4][2] = {
    {{1, 4}, {1, 2}}, {{2, 3}, {1, 2}}, {{2, 3}, {3, 4}}, {{1, 4}, {3, 4}}};
int N, M, C[500005], R[500005], S, W = 1, sx[] = {1, -1, 0, 0},
                                   sy[] = {0, 0, 1, -1}, x, y, X, Y;
void ban(int x, int y, int d);
void tb(int x, int y) {
  for (int j(0); j < 4; j++) {
    int X = x + sx[j], Y = y + sy[j], S = 0;
    if (!~X || !~Y || X == N || Y == M) continue;
    vector<int> o;
    for (int i(0); i < 4; i++)
      if (g[x][y] & 1 << i)
        ++S, o.push_back(D[i][j / 2].first), o.push_back(D[i][j / 2].second);
    sort(o.begin(), o.end());
    for (int k(S); k < (int)o.size(); k++)
      if (o[k] == o[k - S]) ban(X, Y, o[k]);
  }
}
void ban(int x, int y, int d) {
  --d;
  if (!(g[x][y] & 1 << d)) return;
  g[x][y] ^= 1 << d;
  if (!__builtin_popcount(g[x][y])) puts("0"), exit(0);
  if (1 == __builtin_popcount(g[x][y])) return Q.push_back({x, y});
  tb(x, y);
}
int ith(int x, int y) {
  for (int i(0); i < 4; i++)
    if (g[x][y] & 1 << i) return i;
  assert(0);
}
int main(void) {
  scanf("%d%d", &N, &M);
  for (int i(0); i < N; i++) cin >> s[i], g[i] = vector<int>(M, 15);
  for (int i(0); i < N; i++)
    for (int j(0); j < M; j++)
      if (s[i][j] ^ 46)
        C[i] = R[j] = 1, Q.push_back({i, j}), g[i][j] = 1 << (s[i][j] - 49);
  for (int i(0); i < N; i++) S += !C[i];
  for (int i(0); i < M; i++) S += !R[i];
  while (!Q.empty()) {
    x = Q.back().first, y = Q.back().second, Q.pop_back();
    for (int j(0); j < 4; j++) {
      X = x + sx[j], Y = y + sy[j];
      if (!~X || !~Y || X == N || Y == M) continue;
      ban(X, Y, D[ith(x, y)][j / 2].first);
      ban(X, Y, D[ith(x, y)][j / 2].second);
    }
  }
  for (int i(0); i < S; i++) W = W * 2 % 1000003;
  printf("%d\n", W);
  return 0;
}
