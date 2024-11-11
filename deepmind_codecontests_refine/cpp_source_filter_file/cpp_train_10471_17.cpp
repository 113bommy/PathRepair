#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int a[200005], dp[200005], vis[200005];
bool flag = false;
vector<int> s[200005];
vector<pair<int, int> > v[200005];
void dfs(int node, int value) {
  if (flag) return;
  if (vis[node]) {
    if (value != dp[node]) {
      flag = true;
    }
    return;
  }
  vis[node] = 1;
  dp[node] = value;
  for (int i = 0; i <= (int)v[node].size() - 1; i++) {
    dfs(v[node][i].first, !(value ^ v[node][i].second));
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &x);
    for (int j = 1; j <= x; j++) {
      scanf("%d", &y);
      s[y].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    v[s[i][0]].push_back(make_pair(s[i][1], a[i]));
    v[s[i][1]].push_back(make_pair(s[i][0], a[i]));
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, 1);
      if (flag) {
        printf("NO");
        return 0;
      }
    }
  }
  printf("YES");
}
