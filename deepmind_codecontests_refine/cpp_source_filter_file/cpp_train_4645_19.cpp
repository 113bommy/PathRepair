#include <bits/stdc++.h>
using namespace std;
int read() {
  int res = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') f = (c == '-') ? -1 : 1, c = getchar();
  while ('0' <= c && c <= '9') res = res * 10 + c - '0', c = getchar();
  return res * f;
}
int f[300009][22], n, d, dep[300009];
void Add(int u, int ff) {
  f[u][0] = ff;
  dep[u] = dep[ff] + 1;
  for (int i = 1; i <= 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];
}
int getlca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 20; ~i; i--)
    if (dep[u] - (1 << i) >= dep[v]) u = f[u][i];
  if (u == v) return u;
  for (int i = 20; ~i; i--)
    if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
  return f[u][0];
}
int dist(int u, int v) {
  int lca = getlca(u, v);
  return dep[u] + dep[v] - 2 * dep[lca];
}
vector<int> s1, s2;
int main() {
  n = read() + 1;
  Add(1, 1);
  s1.push_back(1);
  s1.reserve(n);
  s2.reserve(n);
  for (int i = 2; i <= n; i++) {
    Add(i, read());
    int d1 = s1.empty() ? 0 : dist(s1[0], i);
    int d2 = s2.empty() ? 0 : dist(s2[0], i);
    if (max(d1, d2) > d) {
      d = max(d1, d2);
      if (d1 == d) {
        for (int i = 0; i < s2.size(); i++) {
          int u = s2[i];
          if (dist(u, i) == d1) s1.push_back(u);
        }
        s2.clear();
      } else {
        for (int i = 0; i < s1.size(); i++) {
          int u = s1[i];
          if (dist(u, i) == d2) s2.push_back(u);
        }
        s1.clear();
      }
    }
    if (max(d1, d2) == d) (d1 == d ? s2 : s1).push_back(i);
    printf("%d\n", s1.size() + s2.size());
  }
}
