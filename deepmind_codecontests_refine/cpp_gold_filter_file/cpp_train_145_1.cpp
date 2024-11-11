#include <bits/stdc++.h>
using namespace std;
struct why {
  int en, e_id;
} next, u;
int vis[100000 + 10], mask[100000 + 10];
;
vector<why> ve[100000 + 10];
vector<int> q[100000 + 10];
int dfs(int x) {
  vector<int> qq, qqq;
  int find = 0, flag = 0, i;
  vis[x] = 1;
  for (i = 0; i < ve[x].size(); i++) {
    int edge_id = ve[x][i].e_id;
    find = 0;
    if (!mask[edge_id]) {
      flag++;
      mask[edge_id] = 1;
      if (!vis[ve[x][i].en]) {
        find = dfs(ve[x][i].en);
        if (find) qq.push_back(ve[x][i].en);
      }
      if (!find) qqq.push_back(ve[x][i].en);
    }
  }
  if (!flag) return 0;
  if (qq.size()) {
    for (i = 0; i < qq.size(); i++) {
      int temp = qq[i];
      printf("%d %d %d\n", x, temp, q[temp][0]);
    }
    for (i = 0; i < qqq.size(); i += 2) {
      if (i + 1 == qqq.size()) {
        q[x].push_back(qqq[i]);
        return 1;
      }
      printf("%d %d %d\n", qqq[i], x, qqq[i + 1]);
    }
    return 0;
  } else {
    for (i = 0; i < qqq.size(); i += 2) {
      if (i + 1 == qqq.size()) {
        q[x].push_back(qqq[i]);
        return 1;
      }
      printf("%d %d %d\n", qqq[i], x, qqq[i + 1]);
    }
    return 0;
  }
}
int main() {
  int n, m, i, j, x, y, ans = 0;
  scanf("%d %d", &n, &m);
  memset(mask, 0, sizeof(mask));
  memset(vis, 0, sizeof(vis));
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    u.en = y, u.e_id = ans;
    ve[x].push_back(u);
    u.en = x, u.e_id = ans;
    ve[y].push_back(u);
    ans++;
  }
  if (m % 2 == 1) {
    printf("No solution\n");
    return 0;
  }
  dfs(1);
  return 0;
}
