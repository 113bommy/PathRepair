#include <bits/stdc++.h>
using namespace std;
bool de;
bool visit[200005];
int dis[200005];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int n, m, i, a, b;
  cin >> n >> m;
  vector<int> v[n + 1];
  vector<int> trs[n + 1];
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    trs[b].push_back(a);
  }
  int pp;
  cin >> pp;
  int path[pp];
  for (i = 0; i < pp; i++) {
    cin >> path[i];
  }
  queue<int> q;
  q.push(path[pp - 1]);
  visit[path[pp - 1]] = 1;
  dis[path[pp - 1]] = 0;
  while (!q.empty()) {
    int nd = q.front();
    q.pop();
    for (int i = 0; i < trs[nd].size(); i++) {
      if (!visit[trs[nd][i]]) {
        dis[trs[nd][i]] = dis[nd] + 1;
        visit[trs[nd][i]] = 1;
        q.push(trs[nd][i]);
      }
    }
  }
  int mn = 0, mx = 0;
  for (i = 0; i < pp - 1; i++) {
    int cnt = 0;
    for (int e = 0; e < v[path[i]].size(); e++) {
      if (dis[path[i]] == dis[v[path[i]][e]] + 1) {
        cnt++;
      }
    }
    if (dis[path[i]] != dis[path[i + 1]] + 1) {
      mn++;
      mx++;
    }
    if (cnt > 1) {
      mx++;
    }
  }
  cout << mn << " " << mx;
  return 0;
}
