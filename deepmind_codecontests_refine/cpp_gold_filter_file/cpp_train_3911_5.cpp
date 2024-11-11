#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, m;
int s, t, ds, dt;
vector<pair<int, int> > edges;
int color[MAXN];
int colorCnt = 1;
vector<int> graph[MAXN];
int parent[MAXN];
vector<int> component[MAXN];
set<int> sEdges, tEdges;
vector<int> sOnly, tOnly, shared;
map<int, int> sConvert, tConvert;
vector<pair<int, int> > answer;
int Find(int x) {
  if (parent[x] == x) return x;
  parent[x] = Find(parent[x]);
  return parent[x];
}
void Union(int u, int v) {
  int uSave = u;
  int vSave = v;
  u = Find(u);
  v = Find(v);
  if (u == v) return;
  if (component[u].size() < component[v].size()) swap(u, v);
  parent[v] = u;
  answer.push_back({uSave, vSave});
  for (int i = 0; i < component[v].size(); i++) {
    component[u].push_back(component[v][i]);
  }
  component[v].clear();
}
void DFS(int x) {
  color[x] = colorCnt;
  for (int i = 0; i < graph[x].size(); i++) {
    if (color[graph[x][i]] == -1) {
      DFS(graph[x][i]);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int bridge = 0;
  bool success = false;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges.push_back({u, v});
  }
  cin >> s >> t >> ds >> dt;
  for (int i = 0; i < m; i++) {
    if (edges[i] == make_pair(s, t) || edges[i] == make_pair(t, s)) {
      bridge++;
    }
    if (edges[i].first != s && edges[i].first != t) {
      if (edges[i].second != s && edges[i].second != t) {
        graph[edges[i].first].push_back(edges[i].second);
        graph[edges[i].second].push_back(edges[i].first);
      }
    }
  }
  memset(color, -1, sizeof(color));
  for (int i = 1; i <= n; i++) {
    if (i == s || i == t) continue;
    if (color[i] == -1) {
      DFS(i);
      colorCnt++;
    }
  }
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    component[i] = {i};
  }
  for (int i = 0; i < m; i++) {
    if (color[edges[i].first] == color[edges[i].second] &&
        color[edges[i].first] != -1) {
      Union(edges[i].first, edges[i].second);
    }
  }
  for (int i = 0; i < m; i++) {
    if (edges[i] == make_pair(s, t) || edges[i] == make_pair(t, s)) {
      continue;
    }
    if (edges[i].first == s) {
      sEdges.insert(Find(edges[i].second));
      sConvert[Find(edges[i].second)] = edges[i].second;
    }
    if (edges[i].first == t) {
      tEdges.insert(Find(edges[i].second));
      tConvert[Find(edges[i].second)] = edges[i].second;
    }
    if (edges[i].second == s) {
      sEdges.insert(Find(edges[i].first));
      sConvert[Find(edges[i].first)] = edges[i].first;
    }
    if (edges[i].second == t) {
      tEdges.insert(Find(edges[i].first));
      tConvert[Find(edges[i].first)] = edges[i].first;
    }
  }
  for (auto it = sEdges.begin(); it != sEdges.end(); it++) {
    if (tEdges.count(*it) == true) {
      shared.push_back(*it);
    } else {
      sOnly.push_back(*it);
    }
  }
  for (auto it = tEdges.begin(); it != tEdges.end(); it++) {
    if (sEdges.count(*it) == false) {
      tOnly.push_back(*it);
    }
  }
  if (ds - 1 < sOnly.size() || dt - 1 < tOnly.size()) {
    cout << "No" << '\n';
    return 0;
  }
  int dsCopy = ds, dtCopy = dt;
  if (bridge != 0) {
    ds--;
    dt--;
    if (ds + dt - sOnly.size() - tOnly.size() >= shared.size()) {
      success = true;
      answer.push_back({s, t});
      for (int i = 0; i < sOnly.size(); i++) {
        ds--;
        answer.push_back({s, sConvert[sOnly[i]]});
      }
      for (int i = 0; i < tOnly.size(); i++) {
        dt--;
        answer.push_back({t, tConvert[tOnly[i]]});
      }
      for (int i = 0; i < shared.size(); i++) {
        if (ds != 0) {
          ds--;
          answer.push_back({s, sConvert[shared[i]]});
        } else {
          dt--;
          answer.push_back({t, tConvert[shared[i]]});
        }
      }
    }
  }
  ds = dsCopy;
  dt = dtCopy;
  if (success == false && shared.size() != 0) {
    if (ds + dt - sOnly.size() - tOnly.size() - 2 >= shared.size() - 1) {
      success = true;
      for (int i = 0; i < sOnly.size(); i++) {
        ds--;
        answer.push_back({s, sConvert[sOnly[i]]});
      }
      for (int i = 0; i < tOnly.size(); i++) {
        dt--;
        answer.push_back({t, tConvert[tOnly[i]]});
      }
      ds--;
      dt--;
      answer.push_back({s, sConvert[shared[0]]});
      answer.push_back({t, tConvert[shared[0]]});
      for (int i = 1; i < shared.size(); i++) {
        if (ds != 0) {
          ds--;
          answer.push_back({s, sConvert[shared[i]]});
        } else {
          dt--;
          answer.push_back({t, tConvert[shared[i]]});
        }
      }
    }
  }
  if (success == false) {
    cout << "No" << '\n';
    return 0;
  }
  cout << "Yes" << '\n';
  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i].first << " " << answer[i].second << '\n';
  }
}
