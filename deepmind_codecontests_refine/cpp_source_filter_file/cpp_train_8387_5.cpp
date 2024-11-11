#include <bits/stdc++.h>
using namespace std;
enum { North, East, South, West };
int mi[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int mj[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int MN = 1e+6 + 35;
int n;
vector<int> g[MN];
int val[MN], sum[MN], s[3];
int dp[MN];
pair<int, int> ans;
void dfs(int u, int f) {
  sum[u] = val[u];
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == f) continue;
    dfs(v, u);
    sum[u] += sum[v];
  }
}
int findOne(int u, int f) {
  if (sum[u] == s[1]) return u;
  if (dp[u] != -1) return dp[u];
  int &ret = dp[u] = 0;
  for (int i = 0; i < g[u].size() && !ret; i++) {
    int v = g[u][i];
    if (v == f) continue;
    ret = findOne(v, u);
  }
  return ret;
}
int solveDfs(int u, int f) {
  int ret = 0;
  if (sum[u] == s[2]) {
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (v == f) continue;
      int k = findOne(v, u);
      if (k) {
        ans = {u, k};
        return 1;
      }
    }
  }
  ans = {-1, -1};
  for (int i = 0; i < g[u].size() && !ret; i++) {
    int v = g[u][i];
    if (v == f) continue;
    int k = findOne(v, u);
    if (k) {
      if (ans.first == -1) {
        ans.first = k;
      } else {
        ans.second = k;
        return 1;
      }
    }
  }
  for (int i = 0; i < g[u].size() && !ret; i++) {
    int v = g[u][i];
    if (v == f) continue;
    ret |= solveDfs(v, u);
  }
  return ret;
}
void solve(int root) {
  if (s[0] % 3 != 0) {
    printf("-1\n");
    return;
  }
  s[1] = s[0] / 3;
  s[2] = 2 * s[1];
  dfs(root, root);
  memset(dp, -1, sizeof(dp));
  ans = {-1, -1};
  int flag = solveDfs(root, root);
  if (flag)
    printf("%d %d\n", ans.first, ans.second);
  else
    printf("-1\n");
}
void init() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cout << "[FREOPEN]" << endl;
  return;
}
int main() {
  int root;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x) {
      g[x].push_back(i);
      g[i].push_back(x);
    } else
      root = i;
    val[i] = y;
    s[0] += y;
  }
  solve(root);
  return 0;
}
