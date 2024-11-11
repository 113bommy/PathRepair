#include <bits/stdc++.h>
using namespace std;
int u[200001];
vector<int> g[200001];
int ans;
int n, t, r;
int dfs(int now, int lst) {
  int cnt = u[now];
  for (int i = 0; i < g[now].size(); i++) {
    if (g[now][i] == lst) continue;
    cnt += dfs(g[now][i], now);
  }
  while (cnt * 2 > r) cnt -= 2, r -= 2;
  ans += cnt;
  return cnt;
}
int main() {
  cin >> n >> t;
  r = 2 * t;
  for (int i = 0; i < r; i++) {
    int a;
    cin >> a;
    u[a] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 1);
  cout << ans << endl;
  return 0;
}
