#include <bits/stdc++.h>
using namespace std;
int pre[5005], prelt[5005], len[5005];
int to[10010], nx[10010], ghead[5005], lt[10010], gcnt;
void addedge(int l, int r, int _lt) {
  nx[gcnt] = ghead[l], to[gcnt] = r, lt[gcnt] = _lt, ghead[l] = gcnt++;
}
int cant, n;
long long son[5005];
int fa[5005];
void DFS(int u, int fi) {
  int i, v;
  son[u] = 1;
  for (i = ghead[u]; i != -1; i = nx[i]) {
    if ((v = to[i]) == fi) continue;
    fa[v] = u, DFS(v, u);
    son[u] += son[v];
  }
}
long long totf[5005], tot[5005];
void DDFS(int u, int fa) {
  int i, v;
  tot[u] = 0;
  for (i = ghead[u]; i != -1; i = nx[i]) {
    if ((v = to[i]) == fa) continue;
    totf[v] = totf[u] + (n - son[v]) * lt[i];
    DDFS(v, u);
    tot[u] += tot[v] + son[v] * lt[i];
  }
}
inline int Abs(int x) { return x < 0 ? -x : x; }
int TOT;
long long toMove(int u, int fi, int flag) {
  int i, v;
  long long tc;
  for (i = ghead[u]; i != -1; i = nx[i]) {
    if ((v = to[i]) == fi) continue;
    if (flag) {
      if ((tc = TOT - son[v] - son[v]) < 0)
        return toMove(v, u, flag) + tc * lt[i];
    } else {
      if (v == fa[u]) {
        if ((tc = TOT - 2 * (n - son[u])) < 0)
          return toMove(v, u, flag) + tc * lt[i];
      } else {
        if ((tc = TOT - 2 * son[v]) < 0) return toMove(v, u, flag) + tc * lt[i];
      }
    }
  }
  return 0;
}
long long ans;
void dfs(int u, int fa) {
  int i, v;
  long long delta1, delta2, MAX;
  for (i = ghead[u]; i != -1; i = nx[i]) {
    if (fa == (v = to[i])) continue;
    TOT = n - son[v], delta1 = toMove(u, v, 0);
    TOT = son[v], delta2 = toMove(v, u, 1);
    MAX = delta1 * son[v] + delta2 * (n - son[v]);
    if (MAX < ans) ans = MAX;
    dfs(v, u);
  }
}
int main() {
  int tt, i, l, r, lt, cal = 0;
  gcnt = 0;
  memset(ghead, -1, sizeof(ghead));
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d%d%d", &l, &r, &lt);
    addedge(l, r, lt);
    addedge(r, l, lt);
  }
  memset(fa, -1, sizeof(fa));
  fa[1] = 0, DFS(1, 0);
  totf[1] = 0, DDFS(1, 0);
  long long Ans = 0;
  for (i = 1; i <= n; i++) Ans += totf[i];
  ans = 0, dfs(1, 0);
  printf("%I64d\n", Ans + ans);
  return 0;
}
