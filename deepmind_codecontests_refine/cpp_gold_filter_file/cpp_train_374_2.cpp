#include <bits/stdc++.h>
using namespace std;
vector<int> adj[27];
vector<int> rev[27];
bool mark[27], cycle;
vector<int> stk;
int visited[27];
int N;
vector<string> strs;
string tmp;
void dfs(int u) {
  visited[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == 0) {
      dfs(v);
    } else if (visited[v] == 1) {
      cycle = true;
    }
  }
  visited[u] = 2;
  stk.push_back(u);
}
void dfs2(int u) {
  visited[u] = 1;
  tmp += (char)('a' + u);
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == 0) {
      dfs2(v);
    }
  }
  visited[u] = 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  cycle = false;
  string s;
  for (int i = 0; i < 27; i++) {
    mark[i] = false;
    visited[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    cin >> s;
    strs.push_back(s);
    if (s.length() == 1) {
      mark[s[0] - 'a'] = true;
    }
    for (int j = 0; j < s.length() - 1; j++) {
      int p = s[j] - 'a';
      int q = s[j + 1] - 'a';
      if (!adj[p].size()) {
        adj[p].push_back(q);
      } else if (adj[p].size() && adj[p][0] != q) {
        cycle = true;
      }
      if (!rev[q].size()) {
        rev[q].push_back(p);
      } else if (rev[q].size() && rev[q][0] != p) {
        cycle = true;
      }
      if (cycle) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    if (!visited[i] && (adj[i].size() || mark[i])) {
      dfs(i);
    }
  }
  if (cycle) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < 26; i++) visited[i] = 0;
  reverse(stk.begin(), stk.end());
  set<string> res;
  for (int i = 0; i < stk.size(); i++) {
    if (visited[stk[i]] == 0) {
      tmp = "";
      dfs2(stk[i]);
      res.insert(tmp);
    }
  }
  set<string>::iterator it;
  string ans = "";
  for (it = res.begin(); it != res.end(); it++) {
    ans += *it;
  }
  cout << ans << endl;
}
