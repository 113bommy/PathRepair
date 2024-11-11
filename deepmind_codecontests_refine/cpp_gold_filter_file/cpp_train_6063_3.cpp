#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int maxn = 3e5 + 100;
const int maxm = 2e6 + 100;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
int t;
int n;
int a[maxn];
vector<int> v[maxn];
int dep[maxn], sz[maxn];
void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  sz[x] = 1;
  for (auto y : v[x]) {
    if (y == fa) continue;
    dfs(y, x);
    sz[x] += sz[y];
  }
}
bool cmp(int a, int b) { return dep[a] - sz[a] > dep[b] - sz[b]; }
int vis[maxn];
long long ans;
void g(int x, int fa) {
  if (vis[x]) {
    ans += 1ll * (dep[x] - 1) * sz[x];
    return;
  }
  for (auto y : v[x]) {
    if (y == fa) continue;
    g(y, x);
  }
}
int main() {
  int k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
    a[i] = i;
  }
  a[n] = n;
  dfs(1, 0);
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= k; i++) {
    vis[a[i]] = 1;
  }
  g(1, 0);
  printf("%lld", ans);
  return 0;
}
