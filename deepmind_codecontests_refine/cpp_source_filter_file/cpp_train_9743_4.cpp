#include <bits/stdc++.h>
using namespace std;
vector<int> vec[1000005];
int loop, n, m;
int s[1000005][2];
int flag[1000005];
int vis[1000005];
int dfs(int v) {
  int sum = 0;
  for (int i = 0; i < vec[v].size(); i++) {
    if (flag[vec[v][i]] == 0) flag[vec[v][i]] = 1, sum += dfs(vec[v][i]);
  }
  return sum + 1;
}
int main() {
  scanf("%d%d", &n, &m);
  int a, b;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    if (a == b)
      loop++;
    else {
      vec[a].push_back(b);
      vec[b].push_back(a);
    }
    s[i][0] = a;
    s[i][1] = b;
    vis[a] = 1;
    vis[b] = 2;
  }
  flag[a] = 1;
  dfs(a);
  for (int i = 1; i <= n; i++)
    if (vis[i] == 1 && flag[i] == 0) {
      cout << 0;
      return 0;
    }
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    a = s[i][0];
    b = s[i][1];
    if (a != b) {
      ans += (vec[a].size() - 1 + vec[b].size() - 1 + loop);
    } else {
      ans += (m - 1);
    }
  }
  cout << ans / 2;
  return 0;
}
