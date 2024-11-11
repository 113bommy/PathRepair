#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m, K, u[maxn], v[maxn], room, c, t, man[2][maxn], key[2][maxn], f[maxn];
bool d[2][maxn][maxn];
char buf[11];
map<string, int> id;
int F(int x) { return x == f[x] ? x : f[x] = F(f[x]); }
inline void U(int a, int b) { f[F(a)] = F(b); }
inline void solve(int id) {
  for (int i = 0; i < n; ++i) f[i] = i;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (F(u[j]) == F(key[id][j]) || F(v[j]) == F(key[id][j])) U(u[j], v[j]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (F(i) == F(j)) d[id][i][j] = true;
}
inline bool check() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (d[0][i][j] != d[1][i][j]) return false;
  for (int i = 0; i < K; ++i)
    if (!d[1][man[0][i]][man[1][i]]) return false;
  for (int i = 0; i < m; ++i)
    if (!d[1][key[0][i]][key[1][i]]) return false;
  return true;
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 0; i < m; ++i) scanf("%d%d", &u[i], &v[i]), --u[i], --v[i];
  for (int i = 0; i < K; ++i) {
    scanf("%s%d%d", buf, &room, &c);
    id[buf] = id.size() - 1;
    man[0][i] = --room;
    while (c--) {
      scanf("%d", &t);
      key[0][--t] = room;
    }
  }
  for (int i = 0; i < K; ++i) {
    scanf("%s%d%d", buf, &room, &c);
    int x = id[buf];
    man[1][x] = --room;
    while (c--) {
      scanf("%d", &t);
      key[1][--t] = room;
    }
  }
  solve(0);
  solve(1);
  puts(check() ? "YES" : "NO");
  return 0;
}
