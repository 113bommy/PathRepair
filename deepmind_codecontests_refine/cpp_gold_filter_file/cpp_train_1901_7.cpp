#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
vector<int> h, que, d, md;
int n, dist, ans1, ans2, mxh = 0, a, b;
pair<int, int> res;
pair<int, int> ask() {
  cout << "? " << que.size() << " ";
  for (int i = 0; i < que.size(); ++i) cout << que[i] << " ";
  cout << endl;
  que.clear();
  cin >> a >> b;
  return pair<int, int>(a, b);
}
void dfs(int start, int pa) {
  md[start] = h[start];
  int i, j;
  for (i = 0; i < graph[start].size(); ++i) {
    j = graph[start][i];
    if (j != pa) {
      h[j] = h[start] + 1;
      mxh = max(mxh, h[j]);
      dfs(j, start);
      md[start] = max(md[start], md[j]);
    }
  }
}
void get_node(int start, int pa, int d) {
  if (h[start] == d) {
    que.push_back(start);
    return;
  }
  for (int i = 0; i < graph[start].size(); ++i)
    if (graph[start][i] != pa) get_node(graph[start][i], start, d);
}
void find_second(int start, int pa) {
  int i, j;
  for (i = 0; i < graph[start].size(); ++i) {
    j = graph[start][i];
    if (j != pa) {
      d[j] = d[start] + 1;
      if (d[j] == dist) que.push_back(j);
      find_second(j, start);
    }
  }
}
void solve() {
  int i, x, y;
  scanf("%d", &n);
  graph.assign(n + 1, vector<int>());
  for (i = 1; i < n; ++i) {
    scanf("%d %d", &x, &y);
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  h.assign(n + 1, 0);
  md.assign(n + 1, 0);
  for (i = 1; i <= n; ++i) que.push_back(i);
  res = ask();
  que.clear();
  int root = res.first;
  dist = res.second;
  dfs(root, -1);
  int l = (dist + 1) / 2, r = dist, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    get_node(root, -1, mid);
    if (que.size() == 0)
      r = mid - 1;
    else {
      res = ask();
      if (res.second == dist) {
        ans1 = res.first;
        l = mid + 1;
      } else
        r = mid - 1;
    }
  }
  que.clear();
  d.assign(n + 1, 0);
  find_second(ans1, -1);
  res = ask();
  ans2 = res.first;
  cout << "! " << ans1 << " " << ans2 << endl;
  string lmao;
  cin >> lmao;
  graph.clear();
  h.clear();
  d.clear();
  md.clear();
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
