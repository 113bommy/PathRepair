#include <bits/stdc++.h>
using namespace std;
const int N = 123;
const int M = 1e5 + 123;
int n, a, mt[M], m, x, y, res, sz;
bool used[M];
vector<int> g[M];
vector<pair<int, int> > f[N];
bool try_kuhn(int v) {
  if (used[v]) return 0;
  used[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int x = g[v][i];
    if (mt[x] == -1 || try_kuhn(mt[x])) {
      mt[x] = v;
      return 1;
    }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    for (int j = 2; j * j <= a; j++)
      while (a % j == 0) {
        f[i + 1].push_back(make_pair(j, ++sz));
        a /= j;
      }
    if (a > 1) f[i + 1].push_back(make_pair(a, ++sz));
  }
  while (m--) {
    scanf("%d%d", &x, &y);
    if (x & 1) swap(x, y);
    for (int i = 0; i < f[x].size(); i++)
      for (int j = 0; j < f[y].size(); j++)
        if (f[x][i].first == f[y][j].first)
          g[f[x][i].second].push_back(f[y][j].second);
  }
  memset(mt, -1, sizeof mt);
  for (int i = 1; i <= sz; i++) {
    memset(used, 0, sizeof used);
    try_kuhn(i);
  }
  for (int i = 1; i <= sz; i++)
    if (mt[i] != -1) ++res;
  printf("%d", res);
  return 0;
}
