#include <bits/stdc++.h>
using namespace std;
int ch = 0;
vector<int> use_x(1001), use_y(1001);
vector<vector<int> > v_x(1001), v_y(1001);
void dfs_y(int u);
void dfs_x(int u) {
  use_x[u] = 1;
  for (int i = 0; i < v_x[u].size(); i++) {
    int to = v_x[u][i];
    if (use_y[to] == 0) {
      dfs_y(to);
    }
  }
}
void dfs_y(int u) {
  use_y[u] = 1;
  for (int i = 0; i < v_y[u].size(); i++) {
    int to = v_y[u][i];
    if (use_x[to] == 0) {
      dfs_x(to);
    }
  }
}
int main() {
  int n, x, y;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v_x[x].push_back(y);
    v_y[y].push_back(x);
  }
  for (int i = 0; i < v_x.size(); i++) {
    if (use_x[i] == 0 && v_x[i].size() != 0) {
      ch++;
      dfs_x(i);
    }
  }
  cout << ch--;
}
