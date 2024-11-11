#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 8;
const int INF = 1e9 + 1e5 + 2;
const int mod = 1e9 + 7;
vector<int> adj[100];
bool visted[10];
int vis = 0;
void dfs(int second) {
  visted[second] = 1;
  vis = 0;
  for (int i = 0; i < adj[second].size(); ++i) {
    if (visted[adj[second][i]]) {
      ++vis;
    }
  }
}
void intili() {
  for (int i = 0; i < 100; ++i) visted[i] = 0;
}
int main() {
  int edg, nod;
  cin >> nod >> edg;
  int x, y;
  map<int, int> m;
  for (int i = 0; i < edg; ++i) {
    cin >> x >> y;
    m[x]++;
    m[y]++;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int ans = 0;
  while (1) {
    vector<int> v;
    for (int i = 1; i <= nod; ++i) {
      if (m[i] == 1) v.push_back(i);
    }
    if (v.empty()) break;
    ++ans;
    for (int j = 0; j < v.size(); ++j) {
      m[v[j]]--;
      for (int k : adj[j]) m[k]--;
    }
  }
  cout << ans;
}
