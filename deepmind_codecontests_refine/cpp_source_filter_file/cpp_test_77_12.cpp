#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> a;
bool vis[1001][1001];
bool isNext(int i, int j, int u, int v, int dir) {
  int val1 = a[i][j], val2 = a[u][v];
  bitset<4> dir1(val1);
  bitset<4> dir2(val2);
  if (dir == 1) {
    return !dir1[1] && !dir2[3];
  } else if (dir == 2)
    return !dir1[2] && !dir2[0];
  else if (dir == 3)
    return !dir1[0] && !dir2[2];
  else
    return !dir1[3] && !dir2[1];
}
void dfs(int i, int j, int &sz) {
  if (i + 1 < n && !vis[i + 1][j] && isNext(i, j, i + 1, j, 1)) {
    vis[i + 1][j] = 1;
    sz++;
    dfs(i + 1, j, sz);
  }
  if (j + 1 < m && !vis[i][j + 1] && isNext(i, j, i, j + 1, 2)) {
    vis[i][j + 1] = 1;
    sz++;
    dfs(i, j + 1, sz);
  }
  if (i - 1 >= 0 && !vis[i - 1][j] && isNext(i, j, i - 1, j, 4)) {
    vis[i - 1][j] = 1;
    sz++;
    dfs(i - 1, j, sz);
  }
  if (j - 1 >= 0 && !vis[i][j - 1] && isNext(i, j, i, j - 1, 3)) {
    vis[i][j - 1] = 1;
    sz++;
    dfs(i, j - 1, sz);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  a.resize(n);
  for (auto &i : a) i.resize(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int sz = 1;
      if (!vis[i][j]) {
        vis[i][j] = 1;
        dfs(i, j, sz);
        ans.push_back(sz);
      }
    }
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  for (auto i : ans) cout << i << endl;
}
