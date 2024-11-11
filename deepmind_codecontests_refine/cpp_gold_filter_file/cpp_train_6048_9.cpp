#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001010;
const long long int inf = 2e17 + 7;
bool flag = true;
struct edge {
  int to_;
  long long int val;
  edge(int ty = 0, long long int tv = 0) : to_(ty), val(tv) {}
};
vector<edge> v[maxn];
int vis[maxn], n, m;
int tx, ty, fat[maxn];
long long int fval[maxn], vson[maxn], tv;
long long int ans = -inf, sum = 0;
void dfs1(int x) {
  vis[x] = 1;
  int siz = v[x].size();
  for (int i = 0; i < siz; i++) {
    int t = v[x][i].to_;
    if (vis[t]) continue;
    fat[t] = x;
    fval[t] = v[x][i].val;
    dfs1(t);
  }
}
int dfs2(int x) {
  int sumv = 0;
  if (!vis[x]) {
    sumv = 1;
    vson[fat[x]] = fval[x];
  }
  vis[x] = 1;
  int siz = v[x].size();
  for (int i = 0; i < siz; i++) {
    int t = v[x][i].to_;
    if (vis[t]) continue;
    sumv += dfs2(t);
  }
  return sumv;
}
void proc() {
  long long int las = fval[n], sumv = 0;
  for (int poin = fat[n]; poin != 1; poin = fat[poin]) {
    ans = max(ans, -las - fval[poin]);
    las = fval[poin];
  }
  las = inf;
  for (int poin = n; poin != 0; poin = fat[poin]) {
    if (vson[poin]) {
      ans = max(ans, -las + vson[poin]);
      if (poin != 1) ans = max(ans, -fval[poin] + vson[poin]);
    }
    las = fval[poin];
  }
  int poin = n;
  for (; vson[poin] == 0 && poin != 0; poin = fat[poin]) {
    sumv += fval[poin];
  }
  las = sumv + vson[poin];
  sumv += fval[poin];
  poin = fat[poin];
  for (; poin != 0; poin = fat[poin]) {
    if (vson[poin]) {
      ans = max(ans, -sumv + las + vson[poin]);
      las = max(las, sumv + vson[poin]);
    }
    sumv += fval[poin];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    scanf("%d%d%lld", &tx, &ty, &tv);
    v[tx].push_back(edge(ty, tv));
    v[ty].push_back(edge(tx, tv));
  }
  dfs1(1);
  memset(vis, 0, sizeof(vis));
  for (int poin = n; poin != 0; poin = fat[poin]) vis[poin] = 1;
  for (int poin = n; poin != 0; poin = fat[poin]) {
    sum += fval[poin];
    if (dfs2(poin) > 1) {
      flag = false;
    }
  }
  if (flag) proc();
  for (int i = 1; i <= m; i++) {
    scanf("%lld", &tv);
    if (!flag) {
      printf("%lld\n", sum);
    } else {
      printf("%lld\n", sum + min((long long int)0, ans + tv));
    }
  }
}
