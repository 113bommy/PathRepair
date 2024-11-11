#include <bits/stdc++.h>
using namespace std;
vector<int> v[300001];
set<int> ice[300001], used[300001];
int colors[300001];
void dfs(const int nod, const int parent) {
  for (const int x : ice[nod]) {
    if (ice[parent].find(x) != ice[parent].end()) {
      used[nod].insert(colors[x]);
    }
  }
  int nr = 0;
  for (const int x : ice[nod]) {
    if (ice[parent].find(x) == ice[parent].end()) {
      nr++;
      while (used[nod].find(nr) != used[nod].end()) {
        nr++;
      }
      colors[x] = nr;
      used[nod].insert(nr);
    }
  }
  for (const int x : v[nod]) {
    if (x == parent) {
      continue;
    }
    dfs(x, nod);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int cnt;
    cin >> cnt;
    for (int j = 1; j <= cnt; j++) {
      int x;
      cin >> x;
      ice[i].insert(x);
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int sol = 1;
  for (int i = 1; i <= n; i++) {
    sol = max(sol, (int)ice[i].size());
  }
  cout << sol << '\n';
  dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    cout << max(colors[i], 1) << " ";
  }
  cout << '\n';
  return 0;
}
