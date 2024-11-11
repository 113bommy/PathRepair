#include <bits/stdc++.h>
using namespace std;
const int MAX_NUMBER = 55;
vector<int> path[MAX_NUMBER];
int vis[MAX_NUMBER];
int degree[MAX_NUMBER];
int flag, n, ans_1, ans_2;
void dfs(int cnt_point) {
  if (cnt_point == ans_2) {
    flag = 1;
    return;
  }
  for (int i = 0; i < path[cnt_point].size() && !flag; i++) {
    int next_point = path[cnt_point][i];
    if (!vis[next_point]) {
      vis[next_point] = 1;
      dfs(next_point);
    }
  }
}
int main() {
  scanf("%d", &n);
  memset(degree, 0, sizeof(degree));
  for (int i = 1; i <= n * (n - 1) / 2 - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    path[y].push_back(x);
    degree[x]++;
    degree[y]++;
  }
  memset(vis, 0, sizeof(vis));
  int first = 1;
  for (int i = 1; i <= n; i++) {
    if (degree[i] != (n - 1)) {
      if (first) {
        ans_1 = i;
        first = 0;
      } else {
        ans_2 = i;
      }
    }
  }
  vis[ans_1] = 1;
  dfs(ans_1);
  if (flag) {
    printf("%d %d\n", ans_1, ans_2);
  } else {
    printf("%d %d\n", ans_2, ans_1);
  }
  return 0;
}
