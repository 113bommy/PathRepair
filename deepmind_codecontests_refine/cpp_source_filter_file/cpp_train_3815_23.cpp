#include <bits/stdc++.h>
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const int MAXN = 1e6 + 5;
const double eps = 1e-9;
using namespace std;
int sz[MAXN], par[MAXN];
int qry(int x) { return x != par[x] ? par[x] = qry(par[x]) : x; }
void join(int x, int y) {
  x = qry(x), y = qry(y);
  if (x == y) return;
  if (sz[x] > sz[y]) swap(x, y);
  par[x] = y;
  sz[y] += sz[x];
}
int main() {
  int n, m;
  scanf("%d", &(n)), scanf("%d", &(m));
  long long ans = 1;
  for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d", &(u)), scanf("%d", &(v));
    if (qry(u) == qry(v)) ans = (ans * 2) % MOD;
    join(u, v);
    printf("%I64d\n", ((ans - 1 + MOD) % MOD));
  }
  return 0;
}
