#include <bits/stdc++.h>
using namespace std;
set<int> G[27];
bool dfs(int root, int v[]) {
  v[root] = 0;
  for (int node : G[root]) {
    if (v[node] == 0) return true;
    if (v[node] == 1) continue;
    if (dfs(node, v)) return true;
  }
  v[root] = 1;
  return false;
}
bool isCyclic() {
  int i, v[27];
  memset(v, -1, sizeof(v));
  for (i = 0; i < 26; i++)
    if (v[i] == -1)
      if (dfs(i, v)) return true;
  return false;
}
vector<char> Topo(int inDeg[]) {
  vector<char> v;
  queue<int> q;
  for (int i = 0; i < 26; i++)
    if (inDeg[i] == 0) q.push(i);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    v.push_back(char(cur + 'a'));
    for (int node : G[cur]) {
      inDeg[node]--;
      if (inDeg[node] == 0) q.push(node);
    }
  }
  return v;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, i, j, temp;
  int inDeg[27];
  string s1, s2;
  vector<char> ans;
  bool flag;
  flag = false;
  memset(inDeg, 0, sizeof(inDeg));
  cin >> n;
  cin >> s1;
  for (i = 1; i < n; i++) {
    cin >> s2;
    int cur = 0;
    while (cur < s1.size() && cur < s2.size() && s1[cur] == s2[cur]) cur++;
    if (cur == s1.size() || cur == s2.size()) {
      if (s1.size() < s2.size()) flag = true;
      s1 = s2;
      continue;
    }
    if ((G[s1[cur] - 'a'].find(s2[cur] - 'a')) == G[s1[cur] - 'a'].end()) {
      G[s1[cur] - 'a'].insert(s2[cur] - 'a');
      inDeg[s2[cur] - 'a']++;
    }
    s1 = s2;
  }
  if (flag || isCyclic())
    cout << "Impossible";
  else {
    ans = Topo(inDeg);
    for (char c : ans) cout << c;
  }
  return 0;
}
