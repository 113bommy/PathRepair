#include <bits/stdc++.h>
using namespace std;
const int Max_N = 55;
const int dx[] = {233, 0, 0, 1, -1};
const int dy[] = {233, 1, -1, 0, 0};
namespace Disjoint_set {
int fa[Max_N * Max_N], siz[Max_N * Max_N];
int getf(int u) { return fa[u] == u ? u : fa[u] = getf(fa[u]); }
void init(int n) {
  for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
}
void merge(int u, int v) {
  u = getf(u), v = getf(v);
  if (u == v) return;
  if (siz[u] > siz[v]) swap(u, v);
  siz[v] += siz[u], fa[u] = v;
}
}  // namespace Disjoint_set
using namespace Disjoint_set;
int N, r1, c1, r2, c2;
char Map[Max_N][Max_N];
inline int encode(int x, int y) { return (x - 1) * N + y; }
inline bool inside(int n, int m) {
  return 1 <= n && n <= N && 1 <= m && m <= N;
}
int main() {
  scanf("%d", &N);
  scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
  for (int i = 1; i <= N; i++) scanf("%s", Map[i] + 1);
  init(N * N);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (Map[i][j] == '0')
        for (int k = 1; k <= 4; k++)
          if (inside(i + dx[k], j + dy[k]) && Map[i + dx[k]][j + dy[k]] == '0')
            merge(encode(i, j), encode(i + dx[k], j + dy[k]));
  if (getf(encode(r1, c1)) == getf(encode(r2, c2))) return printf("%d\n", 0), 0;
  int Ans = 2 * N * N, f1 = getf(encode(r1, c1)), f2 = getf(encode(r2, c2));
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (getf(encode(i, j)) == f1)
        for (int k = 1; k <= N; k++)
          for (int w = 1; w <= N; w++)
            if (getf(encode(k, w)) == f2)
              Ans = min(Ans, abs(i - k) * abs(i - k) + abs(j - w) * abs(j - w));
  printf("%d\n", Ans);
  return 0;
}
