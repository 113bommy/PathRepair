#include <bits/stdc++.h>
using namespace std;
int n, m, root;
vector<int> tree[100005];
pair<int, int> pnode[100005];
pair<int, int> pedge[300005];
vector<pair<int, int> > from[100005];
void add(int x, int y, int val) {
  while (y < tree[x].size()) {
    tree[x][y] += val;
    y += y & -y;
  }
}
int sum(int x, int y) {
  int ans = 0;
  while (y > 0) {
    ans += tree[x][y];
    y -= y & -y;
  }
  return ans;
}
void dfs(int x, int last, int num) {
  int i;
  tree[num].push_back(0);
  pnode[x] = {num, pnode[last].second + 1};
  for (i = 0; i < from[x].size(); i++) {
    if (from[x][i].first == last) continue;
    dfs(from[x][i].first, x, num);
    pedge[from[x][i].second] = {num, pnode[x].second + 1};
  }
}
int main() {
  int i, x, y, type;
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    from[x].push_back({y, i});
    from[y].push_back({x, i});
  }
  root = 1;
  for (i = 1; i <= n; i++)
    if (from[i].size() > from[root].size()) root = i;
  for (i = 0; i < from[root].size(); i++) {
    tree[i + 1].push_back(0);
    dfs(from[root][i].first, root, i + 1);
    pedge[from[root][i].second] = {i + 1, 1};
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d", &x);
      add(pedge[x].first, pedge[x].second, -1);
    } else if (type == 2) {
      scanf("%d", &x);
      add(pedge[x].first, pedge[x].second, 1);
    } else {
      scanf("%d%d", &x, &y);
      if (x == root) {
        if (sum(pnode[y].first, pnode[y].second))
          printf("-1\n");
        else
          printf("%d\n", pnode[y].second);
      } else if (y == root) {
        if (sum(pnode[x].first, pnode[x].second))
          printf("-1\n");
        else
          printf("%d\n", pnode[x].second);
      } else if (pnode[x].first == pnode[y].first) {
        if (sum(pnode[x].first, max(pnode[x].second, pnode[y].second)) -
            sum(pnode[x].first, min(pnode[x].second, pnode[y].second)))
          printf("-1\n");
        else
          printf("%d\n", (int)fabs(pnode[x].second - pnode[y].second));
      } else {
        if (sum(pnode[x].first, pnode[x].second) +
            sum(pnode[y].first, pnode[y].second))
          printf("-1\n");
        else
          printf("%d\n", pnode[x].second + pnode[y].second);
      }
    }
  }
}
