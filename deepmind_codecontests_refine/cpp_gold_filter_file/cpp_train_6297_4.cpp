#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111111;
int comps[MAXN];
int par[MAXN];
int ranks[MAXN];
void init(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    ranks[i] = 0;
    comps[i] = 0;
  }
}
int find(int x) {
  if (par[x] == x)
    return x;
  else
    return par[x] = find(par[x]);
}
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (ranks[x] < ranks[y])
    par[x] = y;
  else {
    par[y] = x;
    if (ranks[x] == ranks[y]) ranks[x]++;
  }
}
bool same(int x, int y) { return find(x) == find(y); }
int N, M, m, n, a, b, c;
int eadj[MAXN * 2], eprev[MAXN * 2], elast[MAXN], eind;
int visit[MAXN];
struct Edges {
  int a, b;
} edges[MAXN];
bool dfs(int n, int c) {
  visit[n] = c;
  for (int t = elast[n]; t != -1; t = eprev[t]) {
    int th = eadj[t];
    if (visit[th] == 0) {
      if (!dfs(th, 3 - c)) return false;
    } else if (visit[th] != 3 - c)
      return false;
  }
  return true;
}
int main() {
  scanf("%d%d", &N, &M);
  memset(elast, -1, sizeof elast);
  init(N + 1);
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d", &a, &b, &c);
    if (c)
      unite(a, b);
    else
      edges[m++] = {a, b};
  }
  for (int i = 1; i <= N; i++)
    if (comps[find(i)] == 0) comps[find(i)] = ++n;
  for (int i = 0; i < m; i++) {
    if (same(edges[i].a, edges[i].b)) {
      printf("0");
      return 0;
    }
    int a = comps[find(edges[i].a)], b = comps[find(edges[i].b)];
    eadj[eind] = b;
    eprev[eind] = elast[a];
    elast[a] = eind++;
    eadj[eind] = a;
    eprev[eind] = elast[b];
    elast[b] = eind++;
  }
  int con = 0;
  for (int i = 1; i <= n; i++)
    if (visit[i] == 0) {
      con++;
      if (!dfs(i, 1)) {
        printf("0");
        return 0;
      }
    }
  con--;
  int t = 1, m = 2, MOD = 1e9 + 7, ans = 1;
  while (t <= con) {
    if (con & t) ans = ans * 1LL * m % MOD;
    t <<= 1;
    m = m * 1LL * m % MOD;
  }
  printf("%d", ans);
  return 0;
}
