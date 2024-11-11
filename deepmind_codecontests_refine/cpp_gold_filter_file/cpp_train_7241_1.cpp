#include <bits/stdc++.h>
using namespace std;
int n, m, a[400007], b[400007], k;
vector<int> v[400007];
vector<int> graph[400007];
bool li[400007];
int dp[400007], low[400007];
set<pair<int, int> > bridge;
vector<int> strong[400007];
vector<int> bin[400007];
int ss[400007];
void bcc(int x, int parent) {
  li[x] = true;
  if (parent != -1) dp[x] = dp[parent] + 1;
  low[x] = dp[x];
  for (int i = 0; i < v[x].size(); i++) {
    if (!li[v[x][i]]) {
      bcc(v[x][i], x);
      low[x] = min(low[x], low[v[x][i]]);
      if (low[v[x][i]] > dp[x]) {
        bridge.insert(minmax(x, v[x][i]));
      }
    } else if (v[x][i] != parent) {
      low[x] = min(low[x], dp[v[x][i]]);
    }
  }
}
pair<int, int> maxt;
void dfs(int x) {
  li[x] = true;
  strong[k].push_back(x);
  ss[x] = k;
  for (int i = 0; i < graph[x].size(); i++) {
    if (!li[graph[x][i]]) {
      dfs(graph[x][i]);
    }
  }
}
queue<int> q;
set<int> sp[400007];
void bfs(int x) {
  if (!li[x]) {
    li[x] = true;
    for (int i = 0; i < bin[x].size(); i++) {
      if (!li[bin[x][i]]) {
        sp[x].insert(bin[x][i]);
        q.push(bin[x][i]);
      }
    }
  }
}
set<int> dir[400007];
void dfs2(int x) {
  li[x] = true;
  for (int i = 0; i < graph[x].size(); i++) {
    if (!li[graph[x][i]]) {
      dir[x].insert(graph[x][i]);
      dfs2(graph[x][i]);
    } else {
      if (dir[graph[x][i]].find(x) == dir[graph[x][i]].end()) {
        dir[x].insert(graph[x][i]);
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    v[a[i]].push_back(b[i]);
    v[b[i]].push_back(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (!li[i]) {
      dp[i] = 1;
      bcc(i, -1);
    }
  }
  for (int i = 0; i < m; i++) {
    if (bridge.find(minmax(a[i], b[i])) == bridge.end()) {
      graph[a[i]].push_back(b[i]);
      graph[b[i]].push_back(a[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    li[i] = false;
  }
  maxt = make_pair(-1, -1);
  for (int i = 1; i <= n; i++) {
    if (!li[i]) {
      dfs(i);
      if (int(strong[k].size()) > maxt.first) {
        maxt = make_pair(int(strong[k].size()), k);
      }
      k++;
    }
  }
  for (int i = 1; i <= n; i++) {
    li[i] = false;
  }
  for (int i = 1; i <= n; i++) {
    if (!li[i]) {
      dfs2(i);
    }
  }
  for (pair<int, int> pp : bridge) {
    bin[ss[pp.first]].push_back(ss[pp.second]);
    bin[ss[pp.second]].push_back(ss[pp.first]);
  }
  cout << maxt.first << "\n";
  for (int i = 1; i <= n; i++) {
    li[i] = false;
  }
  q.push(maxt.second);
  while (!q.empty()) {
    bfs(q.front());
    q.pop();
  }
  for (int i = 0; i < m; i++) {
    if (dir[a[i]].find(b[i]) != dir[a[i]].end()) {
      cout << a[i] << " " << b[i] << "\n";
    } else if (dir[b[i]].find(a[i]) != dir[b[i]].end()) {
      cout << b[i] << " " << a[i] << "\n";
    } else {
      if (sp[ss[a[i]]].find(ss[b[i]]) != sp[ss[a[i]]].end()) {
        cout << b[i] << " " << a[i] << "\n";
      } else {
        cout << a[i] << " " << b[i] << "\n";
      }
    }
  }
  return 0;
}
