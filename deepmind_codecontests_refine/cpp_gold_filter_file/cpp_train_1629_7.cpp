#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6;
int root, all, minn;
vector<int> edge[maxn + 11];
char ch[maxn + 11];
int siz[maxn + 11], a[maxn + 11], val[maxn + 11];
bool vis[maxn + 11] = {false};
long long sum;
int n;
long long ans[maxn + 11], cnt[maxn + 11];
void getroot(int x, int fa) {
  int f = 0;
  siz[x] = 1;
  for (int i = 0; i < edge[x].size(); i++) {
    int v = edge[x][i];
    if (v == fa || vis[v]) continue;
    getroot(v, x);
    siz[x] += siz[v];
    f = max(f, siz[v]);
  }
  f = max(f, all - siz[x]);
  if (f < minn) {
    minn = f;
    root = x;
  }
}
void dfs(int x, int fa, int op) {
  val[x] = val[fa] ^ a[x];
  cnt[val[x]] += op;
  for (int i = 0; i < edge[x].size(); i++) {
    int v = edge[x][i];
    if (v == fa || vis[v]) continue;
    dfs(v, x, op);
  }
}
long long calc(int x, int fa) {
  long long res = 0;
  res += cnt[val[x] ^ a[root]];
  if ((val[x] ^ a[root]) == val[root]) sum += 1;
  for (int i = 0; i < 20; i++) {
    res += cnt[val[x] ^ a[root] ^ (1 << i)];
    if ((val[x] ^ (1 << i)) == 0) sum += 1;
  }
  for (int i = 0; i < edge[x].size(); i++) {
    int v = edge[x][i];
    if (v == fa || vis[v]) continue;
    res += calc(v, x);
  }
  ans[x] += res;
  return res;
}
void solve(int x) {
  vis[x] = true;
  val[x] = a[x];
  cnt[val[x]] = 1;
  for (int i = 0; i < edge[x].size(); i++) {
    int v = edge[x][i];
    if (vis[v]) continue;
    dfs(v, x, 1);
  }
  sum = 0;
  for (int i = 0; i < edge[x].size(); i++) {
    int v = edge[x][i];
    if (vis[v]) continue;
    dfs(v, x, -1);
    sum += calc(v, x);
    dfs(v, x, 1);
  }
  sum /= 2;
  ans[x] += sum;
  cnt[val[x]] -= 1;
  for (int i = 0; i < edge[x].size(); i++) {
    int v = edge[x][i];
    if (vis[v]) continue;
    dfs(v, x, -1);
  }
  for (int i = 0; i < edge[x].size(); i++) {
    int v = edge[x][i];
    if (vis[v]) continue;
    all = siz[v];
    minn = n;
    root = 0;
    getroot(v, x);
    solve(root);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  scanf("%s", ch + 1);
  for (int i = 1; i <= n; i++) a[i] = (1 << (ch[i] - 'a'));
  all = minn = n;
  root = 0;
  getroot(1, 0);
  solve(root);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i] + 1);
}
