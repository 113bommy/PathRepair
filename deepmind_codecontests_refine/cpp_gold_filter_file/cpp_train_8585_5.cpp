#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
int n, m, u, v, x, T, fa[N], c[N], vi[N], d[N];
vector<int> ve[N], v1, v2, v3;
struct lin {
  int x, y;
} l[N];
void add(int u, int v) { ve[u].push_back(v); }
void opt(int u, int v, int w) {
  int ok = 0, A, B, C, D;
  for (x = l[u].x; x; x = fa[x])
    if (x == l[v].x) ok = 1;
  if (ok) {
    A = l[u].x, B = l[u].y, C = l[v].x, D = l[v].y;
    if (d[B] < d[D]) {
      for (x = D; x != B; x = fa[x]) v1.push_back(x);
      v1.push_back(B);
      for (x = A; x != C; x = fa[x]) v1.push_back(x);
      v1.push_back(C);
      v2.push_back(D);
      v2.push_back(C);
      for (x = C; x != D; x = fa[x]) v3.push_back(x);
      v3.push_back(D);
      reverse(v3.begin(), v3.end());
    } else {
      for (x = B; x != D; x = fa[x]) v1.push_back(x);
      v1.push_back(D);
      v1.push_back(C);
      v2.push_back(B);
      for (x = A; x != C; x = fa[x]) v2.push_back(x);
      v2.push_back(C);
      for (x = C; x != B; x = fa[x]) v3.push_back(x);
      v3.push_back(B);
      reverse(v3.begin(), v3.end());
    }
  } else {
    if (d[l[v].y] < d[l[u].y]) swap(u, v);
    A = l[u].x, B = l[u].y, C = l[v].x, D = l[v].y;
    for (x = D; x != B; x = fa[x]) v1.push_back(x);
    v1.push_back(B);
    for (x = A; x != w; x = fa[x]) v1.push_back(x);
    v1.push_back(w);
    v2.push_back(D);
    for (x = C; x != w; x = fa[x]) v2.push_back(x);
    v2.push_back(w);
    for (x = w; x != D; x = fa[x]) v3.push_back(x);
    v3.push_back(D);
    reverse(v3.begin(), v3.end());
  }
  puts("YES");
  cout << v1.size() << ' ';
  for (int v : v1) cout << v << ' ';
  cout << '\n';
  cout << v2.size() << ' ';
  for (int v : v2) cout << v << ' ';
  cout << '\n';
  cout << v3.size() << ' ';
  for (int v : v3) cout << v << ' ';
  cout << '\n';
  exit(0);
}
void dfs(int u) {
  vi[u] = 1;
  for (int v : ve[u])
    if (v != fa[u]) {
      if (vi[v] && d[v] < d[u]) {
        l[++T] = (lin){u, v};
        for (x = u; x != v; x = fa[x]) c[x] ? opt(T, c[x], x), 0 : c[x] = T;
      } else if (!vi[v])
        fa[v] = u, d[v] = d[u] + 1, dfs(v);
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &u, &v), add(u, v), add(v, u);
  for (int i = 1; i <= n; i++)
    if (!vi[i]) dfs(i);
  puts("NO");
}
