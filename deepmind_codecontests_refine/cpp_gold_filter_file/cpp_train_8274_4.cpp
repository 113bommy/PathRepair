#include <bits/stdc++.h>
using namespace std;
int N, M, n, m, MOD;
char mirror[505][505];
bool color[505][505];
int g[2][50005];
map<int, int> graph[2];
long long lap[2][505][505];
int find(int k, int c) {
  if (k == 0 && c == 1) return -1;
  return g[c][k] == k ? k : g[c][k] = find(g[c][k], c);
}
bool merge(int a, int b, int c) {
  int x = find(a, c), y = find(b, c);
  if (x == y) return true;
  g[c][x] = g[c][y] = min(x, y);
  return false;
}
void connect(int a, int b, int c) {
  a = find(a, c), b = find(b, c);
  if (a == b) return;
  a = graph[c][a], b = graph[c][b];
  lap[c][a][a]++, lap[c][b][b]++, lap[c][a][b]--, lap[c][b][a]--;
}
void addEdge(int x, int y) {
  bool c = color[x][y];
  int t = x * m + y;
  connect(t, t + m + 1, c);
  connect(t + 1, t + m, !c);
}
long long inv(long long x, long long y, long long p, long long q, long long r,
              long long s) {
  if (y == 0) return (p % MOD + MOD) % MOD;
  return inv(y, x % y, r, s, p - r * (x / y), q - s * (x / y));
}
long long det(long long F[505][505], int D) {
  long long ans = 1;
  for (int i = 0; i < D; i++) {
    int r = i;
    while (r < D && F[r][i] == 0) ++r;
    if (r >= D) return 0;
    if (r != i) ans = ans * (MOD - 1) % MOD;
    for (int j = i; j < D; j++) swap(F[r][j], F[i][j]);
    ans = ans * F[i][i] % MOD;
    long long t = inv(F[i][i], MOD, 1, 0, 0, 1);
    for (int j = i; j < D; j++) F[i][j] = (F[i][j] * t) % MOD;
    for (int r = i + 1; r < D; r++)
      if (F[r][i] != 0) {
        long long s = F[r][i];
        for (int j = i; j < D; j++) {
          F[r][j] = (F[r][j] - s * F[i][j]) % MOD;
          if (F[r][j] < 0) F[r][j] += MOD;
        }
      }
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &N, &M, &MOD);
  for (int i = 0; i < N; i++) scanf("%s", mirror[i]);
  n = N + 1, m = M + 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) color[i][j] = (i % 2) ^ (j % 2);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) g[color[i][j]][i * m + j] = i * m + j;
  bool fail = false;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int t = i * m + j;
      if (mirror[i][j] == '/')
        fail |= merge(t + m, t + 1, !color[i][j]);
      else if (mirror[i][j] == '\\')
        fail |= merge(t, t + m + 1, color[i][j]);
    }
  }
  if (fail) {
    puts("0");
    return 0;
  }
  for (int k = 0; k < 2; k++) {
    for (int i = 0, cnt = 0; i < n * m; i++) {
      if (find(i, k) != i) continue;
      graph[k][i] = cnt++;
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (mirror[i][j] == '*') addEdge(i, j);
  for (int k = 0; k < 2; k++) {
    int sz = graph[k].size();
    for (int i = 0; i < sz; i++)
      for (int j = 0; j < sz; j++) lap[k][i][j] = (lap[k][i][j] + MOD) % MOD;
  }
  printf("%d\n", (int)(det(lap[0], graph[0].size() - 1) +
                       det(lap[1], graph[1].size() - 1)) %
                     MOD);
}
