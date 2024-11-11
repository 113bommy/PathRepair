#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
typedef struct {
  int to, id;
} stu;
vector<stu> e[N];
int n;
typedef struct {
  int qi, to, w, r, id;
} stu1;
stu1 p[N], t[N];
int dp[N];
int dp1[N];
void dfs(int u, int fa) {
  int v, id;
  for (int i = 0; i < e[u].size(); i++) {
    v = e[u][i].to, id = e[u][i].id;
    if (v == fa) continue;
    dfs(v, u);
    if (dp[v] > p[id].r) {
      printf("-1\n");
      exit(0);
    }
    int temp = min(p[id].r - dp[v], p[id].w - 1);
    p[id].w -= temp;
    p[id].r -= temp;
    dp[u] += dp[v] + p[id].w;
  }
}
void dfs1(int u, int fa, int id, int mx) {
  if (id != 0) {
    int temp = min(t[id].w - p[id].w, mx);
    p[id].w += temp;
    p[id].r += temp;
    mx = min(mx - temp, p[id].r - dp[u]);
    dp1[id] = temp;
  }
  int v, nextid;
  for (int i = 0; i < e[u].size(); i++) {
    v = e[u][i].to, nextid = e[u][i].id;
    if (v == fa) continue;
    if (id == 0) mx = 2e9;
    dfs1(v, u, nextid, mx);
    mx -= dp1[nextid];
    dp1[id] += dp1[nextid];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d %d %d %d", &p[i].qi, &p[i].to, &p[i].w, &p[i].r);
    t[i] = p[i];
    e[p[i].qi].push_back({p[i].to, i});
    e[p[i].to].push_back({p[i].qi, i});
  }
  dfs(1, 0);
  dfs1(1, 0, 0, 2e9);
  printf("%d\n", n);
  for (int i = 1; i < n; i++) {
    printf("%d %d %d %d\n", p[i].qi, p[i].to, p[i].w, p[i].r);
  }
  return 0;
}
