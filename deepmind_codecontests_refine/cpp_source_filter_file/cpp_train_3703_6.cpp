#include <bits/stdc++.h>
using namespace std;
const int N = 100010 * 2;
int n;
int ans[N];
int x[N];
int y[N];
int vis[N];
vector<int> edge[N];
void dfs(int index, int flag) {
  if (vis[index] == true) return;
  ans[index] = flag;
  vis[index] = true;
  for (int i = 0; i < edge[index].size(); i++) dfs(edge[index][i], flag ^ 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", x + i, y + i);
    edge[x[i]].push_back(y[i]);
    edge[y[i]].push_back(x[i]);
    edge[i * 2 - 1].push_back(i * 2);
    edge[i * 2].push_back(i * 2 - 1);
  }
  for (int i = 1; i <= n; i++) {
    dfs(i, 1);
  }
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", ans[x[i]] + 1, ans[y[i]] + 1);
  }
}
