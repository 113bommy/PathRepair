#include <bits/stdc++.h>
using namespace std;
const int N = 1010, dx[] = {0, 1, 1, 1, 0, -1, -1, -1},
          dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int n, m, q;
char s[N][N];
int id[N][N], f[N * N], l = 0, S, T;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int Fx(int x) { return f[x] == x ? x : Fx(f[x]); }
bool ch[N], haveans = true;
set<pair<int, int> > frb;
pair<int, int> get(int a, int b) {
  if (a < b) swap(a, b);
  return make_pair(a, b);
}
void init() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) id[i][j] = ++l, f[id[i][j]] = id[i][j];
  S = ++l, T = ++l;
  f[S] = S, f[T] = T;
  for (int j = 1; j <= m; j++)
    id[0][j] = S, id[n + 1][j] = T, s[0][j] = s[n + 1][j] = '#';
  for (int i = 1; i <= n; i++)
    id[i][0] = T, id[i][m + 1] = S, s[i][0] = s[i][m + 1] = '#';
  s[1][1] = 'S', s[n][m] = 'T';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '#') {
        for (int k = 0; k <= 7; k++)
          if (s[i + dx[k]][j + dy[k]] == '#') {
            int fx = find(id[i][j]), fy = find(id[i + dx[k]][j + dy[k]]);
            f[fx] = fy;
          }
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '.') {
        for (int k1 = 0; k1 <= 7; k1++)
          for (int k2 = k1 + 1; k2 <= 7; k2++) {
            int k, t1, t2;
            k = k1, t1 = find(id[i + dx[k]][j + dy[k]]);
            k = k2, t2 = find(id[i + dx[k]][j + dy[k]]);
            frb.insert(get(t1, t2));
          }
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '.' || s[i][j] == '#') {
        for (int k1 = 0; k1 <= 7; k1++)
          for (int k2 = 0; k2 <= 7; k2++) {
            int k, t1, t2;
            k = k1, t1 = find(id[i + dx[k]][j + dy[k]]);
            k = k2, t2 = find(id[i + dx[k]][j + dy[k]]);
            if (t1 == find(S) && t2 == find(T)) haveans = false;
          }
      }
}
int k, ndx[11], ndy[11];
int bk[110], fa[110];
void work() {
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) scanf("%d%d", &ndx[i], &ndy[i]);
  for (int i = 1; i <= k; i++) s[ndx[i]][ndy[i]] = '#';
  bool ans = haveans;
  int l = 0;
  for (int t = 1; t <= k; t++) {
    int i = ndx[t], j = ndy[t];
    bk[++l] = find(id[i][j]);
    for (int k = 0; k <= 7; k++)
      if (s[i + dx[k]][j + dy[k]] == '#')
        bk[++l] = find(id[i + dx[k]][j + dy[k]]);
  }
  bk[++l] = find(S), bk[++l] = find(T);
  sort(bk + 1, bk + l + 1);
  l = unique(bk + 1, bk + l + 1) - bk - 1;
  for (int i = 1; i <= l; i++) fa[i] = find(bk[i]);
  for (int t = 1; t <= k; t++) {
    int i = ndx[t], j = ndy[t];
    for (int k = 0; k <= 7; k++)
      if (s[i + dx[k]][j + dy[k]] == '#') {
        int fx = Fx(id[i][j]), fy = Fx(id[i + dx[k]][j + dy[k]]);
        if (fx != fy) f[fx] = fy;
      }
  }
  if (find(S) == find(T)) ans = false;
  for (int i = 1; i <= l; i++) {
    if (!ans) break;
    for (int j = 1; j <= l; j++)
      if (Fx(bk[i]) == Fx(S) && Fx(bk[j]) == Fx(T) &&
          frb.find(get(bk[i], bk[j])) != frb.end()) {
        ans = false;
        break;
      }
  }
  for (int i = 1; i <= l; i++) f[bk[i]] = fa[i];
  for (int i = 1; i <= k; i++) s[ndx[i]][ndy[i]] = '.';
  if (ans)
    printf("YES\n");
  else
    printf("NO\n");
  fflush(stdout);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  init();
  for (int i = 1; i <= q; i++) work();
  return 0;
}
