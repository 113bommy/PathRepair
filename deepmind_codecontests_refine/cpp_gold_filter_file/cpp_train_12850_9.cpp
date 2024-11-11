#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 3 * 1e5 + 10;
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int fir[N], nex[M], to[M], tot = 0;
long long price[N], money[N], mi;
int dfn[N], low[N], num;
int st[N], top;
int co[N], col;
int n, m;
vector<int> v[N];
void Index(int x, int y) {
  to[++tot] = y;
  nex[tot] = fir[x];
  fir[x] = tot;
}
void Tarjan(int u) {
  low[u] = dfn[u] = ++num;
  st[++top] = u;
  for (int i = fir[u]; i; i = nex[i]) {
    int du = to[i];
    if (!dfn[du]) {
      Tarjan(du);
      low[u] = min(low[u], low[du]);
    } else if (!co[du])
      low[u] = min(low[u], dfn[du]);
  }
  if (low[u] == dfn[u]) {
    co[u] = ++col;
    v[col].push_back(u);
    mi = price[u];
    while (st[top] != u) {
      co[st[top]] = col;
      v[col].push_back(st[top]);
      mi = min(mi, price[st[top]]);
      --top;
    }
    --top;
    money[col] = mi;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &price[i]);
  scanf("%d", &m);
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d%d", &x, &y);
    Index(x, y);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) Tarjan(i);
  long long sum = 0;
  for (int i = 1; i <= col; i++) sum += money[i];
  printf("%lld ", sum);
  long long ans = 1;
  for (int i = 1; i <= col; i++) {
    int book = 0;
    for (int j = 0; j < v[i].size(); j++) {
      if (price[v[i][j]] == money[i]) book++;
    }
    ans = (ans * book) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
