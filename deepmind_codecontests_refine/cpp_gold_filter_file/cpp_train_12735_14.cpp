#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > sum, val;
vector<pair<int, int> > graph[100000];
int root = -1, n, x;
pair<int, int> edge[100000 - 1], vertex[100000 - 1];
void dfs(int v, int p = -1) {
  int u;
  for (pair<int, int>& e : graph[v]) {
    if ((u = e.first) != p) {
      if (v == root) {
        sum.push_back(vector<int>());
        val.push_back(vector<int>());
      }
      val.back().push_back(1);
      vertex[u] = edge[e.second] = {val.size() - 1, val.back().size() - 1};
      dfs(u, v);
    }
  }
}
void sumUpdate(int i, int j) {
  n = sum[i].size();
  x = val[i][j] ? -1 : 1;
  val[i][j] += x;
  for (; j < n; j |= j + 1) sum[i][j] += x;
}
int getSum(int i, int j) {
  n = 0;
  for (; j >= 0; j = (j & (j + 1)) - 1) n += sum[i][j];
  return n;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int i, q, x, y, j, t;
  cin >> n;
  for (i = 0; i < n - 1; i++) {
    cin >> x >> y;
    --x;
    --y;
    graph[x].push_back({y, i});
    graph[y].push_back({x, i});
    if (graph[x].size() > 2) root = x;
    if (graph[y].size() > 2) root = y;
  }
  if (root == -1) {
    for (i = 0; i < n; i++) {
      if (graph[i].size() == 1) {
        root = i;
        break;
      }
    }
  }
  dfs(root);
  vertex[root] = {-1, -1};
  for (i = 0, q = val.size(); i < q; i++) {
    sum[i].resize(n = val[i].size());
    for (j = 0; j < n; j++) {
      sum[i][j] += val[i][j];
      if ((j | (j + 1)) < n) sum[i][j | (j + 1)] += sum[i][j];
    }
  }
  cin >> q;
  int c_x, c_y;
  while (q--) {
    cin >> t;
    if (t < 3) {
      cin >> x;
      --x;
      sumUpdate(edge[x].first, edge[x].second);
    } else {
      cin >> x >> y;
      --x;
      --y;
      i = vertex[x].second;
      j = vertex[y].second;
      c_x = vertex[x].first;
      c_y = vertex[y].first;
      if (i > j) {
        swap(i, j);
        swap(c_x, c_y);
      }
      if (c_x == -1) {
        if (getSum(c_y, j) == j + 1)
          cout << j + 1 << "\n";
        else
          cout << "-1\n";
      } else if (c_x == c_y) {
        if (getSum(c_y, j) - getSum(c_x, i) == j - i)
          cout << j - i << "\n";
        else
          cout << "-1\n";
      } else {
        if (getSum(c_y, j) + getSum(c_x, i) == i + j + 2)
          cout << i + j + 2 << "\n";
        else
          cout << "-1\n";
      }
    }
  }
  return 0;
}
