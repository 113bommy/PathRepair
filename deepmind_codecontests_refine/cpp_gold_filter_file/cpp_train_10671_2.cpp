#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> adj[n + 1];
  int par[n + 1][n + 1];
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      par[i][j] = 0;
    }
  }
  set<tuple<int, int, int>> abc;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= k; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    abc.insert(make_tuple(x, y, z));
  }
  int dist[n + 1][n + 1];
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      dist[i][j] = 1e9;
    }
  }
  queue<pair<int, int>> q;
  dist[1][1] = 0;
  q.push(make_pair(1, 1));
  while (!q.empty()) {
    int dad = q.front().first;
    int grand_dad = q.front().second;
    q.pop();
    for (int i = 0; i < adj[dad].size(); i++) {
      int kid = adj[dad][i];
      if (abc.find(make_tuple(grand_dad, dad, kid)) == abc.end()) {
        if (dist[grand_dad][dad] + 1 < dist[dad][kid]) {
          dist[dad][kid] = dist[grand_dad][dad] + 1;
          q.push(make_pair(kid, dad));
          par[dad][kid] = grand_dad;
        }
      }
    }
  }
  int minn = 1e9, ll = 0;
  for (int l = 1; l < n + 1; l++) {
    if (minn > dist[l][n]) {
      minn = dist[l][n];
      ll = l;
    }
  }
  if (ll == 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << minn << endl;
  vector<int> ans;
  int i = n, j = ll;
  while (i != 1 || j != 1) {
    ans.push_back(i);
    int p = j;
    j = par[j][i];
    i = p;
  }
  ans.push_back(1);
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
  return 0;
}
