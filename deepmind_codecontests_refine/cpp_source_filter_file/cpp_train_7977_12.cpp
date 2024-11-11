#include <bits/stdc++.h>
using namespace std;
int n, p[1005];
vector<int> G[1005];
int dfs(int u) {
  int cnt = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!G[v].size()) {
      cnt++;
    } else
      dfs(v);
  }
  if (G[u].size() && cnt != 3) {
    puts("No");
    exit(0);
  }
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    G[p[i]].push_back(i);
  }
  dfs(1);
  puts("Yes");
  return 0;
}
