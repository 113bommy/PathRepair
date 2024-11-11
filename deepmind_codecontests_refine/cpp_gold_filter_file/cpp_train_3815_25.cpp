#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 9;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int par[MAXN], power[MAXN];
int find(int x) {
  if (x == par[x])
    return x;
  else
    return par[x] = find(par[x]);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) par[i] = i;
  power[0] = 1;
  for (int i = 1; i <= m; i++) power[i] = power[i - 1] * 2 % MOD;
  int tot = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u = find(u), v = find(v);
    if (u != v) {
      par[u] = v;
    } else {
      tot++;
    }
    printf("%d\n", (power[tot] + MOD - 1) % MOD);
  }
  return 0;
}
