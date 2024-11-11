#include <bits/stdc++.h>
using namespace std;
int in = -1;
void dfs(int i, int c, vector<vector<int> >& a, int& sum, vector<int>& vis) {
  if (c > sum) {
    sum = c;
    if (a[i].size() && vis[a[i][0]]) in = i;
  }
  vis[i] = 1;
  for (int k = 0; k < a[i].size(); k++) {
    if (!vis[a[i][k]]) dfs(a[i][k], c + 1, a, sum, vis);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  int sum = 0;
  vector<vector<int> > a(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a[x - 1].push_back(y - 1);
    a[y - 1].push_back(x - 1);
  }
  int count = 0;
  vector<int> vis(n);
  int i = 0;
  dfs(i, count, a, sum, vis);
  for (int j = 0; j < n; j++) vis[j] = 0;
  dfs(in, count, a, sum, vis);
  cout << sum;
  return 0;
}
