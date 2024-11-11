#include <bits/stdc++.h>
using namespace std;
vector<int> edge[100005];
int mark[100005], t = 0, st;
bool dfs(int now) {
  mark[now] = t;
  int n = edge[now].size();
  if (now == st) n--;
  if (n >= 3) return 0;
  for (int i = 0; i < edge[now].size(); i++) {
    int p = edge[now][i];
    if (mark[p] == t) continue;
    if (!dfs(p)) return 0;
  }
  return 1;
}
int main() {
  int n, i, k, j, x, y;
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  for (i = 1; i <= n; i++) {
    if (edge[i].size() <= 2) continue;
    int cnt = 0;
    t++, mark[i] = t;
    for (k = 0; k < edge[i].size(); k++) {
      int p = edge[i][k];
      st = p;
      if (!dfs(p)) cnt++;
    }
    if (cnt >= 3) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}
