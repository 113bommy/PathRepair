#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, F = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') F = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * F;
}
int Tk, n, s, t;
int dep[100000 + 5], md[100000 + 5], F[100000 + 5];
vector<int> G[100000 + 5], tmp[100000 + 5], P;
bool cmp(int s1, int s2) { return s1 > s2; }
void dfs(int x, int fa) {
  tmp[x].assign(3, 0), md[x] = 0;
  for (int i = 0; i < G[x].size(); i++) {
    int v = G[x][i];
    if (v == fa) continue;
    dep[v] = dep[x] + 1;
    dfs(v, x);
    tmp[x].push_back(md[v] + 1);
    md[x] = max(md[x], md[v] + 1);
  }
}
void dfs2(int x, int fa) {
  partial_sort(tmp[x].begin(), tmp[x].begin() + 3, tmp[x].end(), cmp);
  for (int i = 0; i < G[x].size(); i++) {
    int v = G[x][i];
    if (v == fa) continue;
    if (md[v] + 1 == tmp[x][0])
      tmp[v].push_back(tmp[x][1] + 1);
    else
      tmp[v].push_back(tmp[x][0] + 1);
    dfs2(v, x);
  }
}
int dfs3(int x, int fa) {
  int tag = (x == t);
  F[x] = fa, md[x] = 0;
  for (int i = 0; i < G[x].size(); i++) {
    int v = G[x][i];
    if (v == fa) continue;
    if (dfs3(v, x))
      tag = 1;
    else
      md[x] = max(md[x], md[v] + 1);
  }
  return tag;
}
bool check() {
  for (int i = 1; i <= n; i++)
    if (tmp[i][2] >= dep[t]) return 1;
  return 0;
}
int main() {
  Tk = read();
  while (Tk--) {
    n = read(), s = read(), t = read();
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i < n; i++) {
      int u = read(), v = read();
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dep[s] = 0, dfs(s, 0), dfs2(s, 0);
    if (!check()) {
      puts("NO");
      continue;
    }
    dfs3(s, 0);
    P.clear(), P.push_back(md[t]);
    while (t != s) P.push_back(md[t = F[t]]);
    int len = P.size(), l = 0, r = len - 1, L, R;
    L = P[r], R = len - 1 - P[l];
    while (l < r) {
      if (l < L)
        l++, R = min(R, l + (len - 1 - P[l]));
      else if (r > R)
        r--, L = max(L, r - (len - 1 - P[r]));
      else
        break;
    }
    printf("%s\n", (l == r) ? "YES" : "NO");
  }
}
