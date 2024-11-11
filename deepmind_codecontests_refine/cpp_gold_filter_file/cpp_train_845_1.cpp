#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
int n, m, p[maxn], c[maxn], d, del[maxn], vis[maxn], flow;
vector<int> e[maxn << 1], g[maxn << 1];
int mat[maxn << 1], vv[maxn << 1], Ans[maxn];
int dfs(int x) {
  vv[x] = 1;
  for (int i = 0; i < e[x].size(); i++) {
    int y = e[x][i];
    if (vv[mat[y]]) continue;
    if (!mat[y] || dfs(mat[y])) {
      mat[x] = y;
      mat[y] = x;
      return 1;
    }
  }
  return 0;
}
int solve(int x) {
  memset(vv, 0, sizeof(vv));
  int flag = dfs(x);
  return flag;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> p[i], p[i]++;
  for (int i = 1; i <= n; i++) cin >> c[i];
  cin >> d;
  for (int i = 1; i <= d; i++) cin >> del[i], vis[del[i]] = 1;
  int ans = 1;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      g[p[i]].push_back(c[i] + n + 1);
    }
  for (int i = 0; i < g[1].size(); i++) e[1].push_back(g[1][i]);
  for (int i = d; i >= 1; i--) {
    while (solve(ans) && ans < n) {
      ans++;
      for (int j = 0; j < g[ans].size(); j++) e[ans].push_back(g[ans][j]);
    }
    Ans[i] = ans;
    if (p[del[i]] <= ans)
      e[p[del[i]]].push_back(c[del[i]] + n + 1);
    else
      g[p[del[i]]].push_back(c[del[i]] + n + 1);
  }
  for (int i = 1; i <= d; i++) cout << Ans[i] - 1 << '\n';
  cout << endl;
}
