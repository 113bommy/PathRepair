#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100020];
bool visited[100020], odd[100020];
bool isodd;
vector<int> path;
int done[100020];
void dfscomp(int curr) {
  visited[curr] = true;
  if (odd[curr]) isodd = true;
  for (auto nxt : adj[curr])
    if (!visited[nxt]) dfscomp(nxt);
}
void dfs2(int curr, int par = -1) {
  visited[curr] = true;
  path.push_back(curr);
  done[curr]++;
  for (auto nxt : adj[curr]) {
    if (!visited[nxt]) {
      dfs2(nxt, curr), path.push_back(curr);
      done[curr]++;
    }
  }
  if (((odd[curr] && done[curr] % 2 == 0) ||
       (!odd[curr] && done[curr] % 2 == 1)) &&
      par != -1) {
    path.push_back(par), path.push_back(curr);
    done[par]++;
    done[curr]++;
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int p;
    scanf("%d", &p);
    if (p) odd[i + 1] = true;
  }
  vector<int> beg;
  for (int i = 1; i <= n; i++) {
    isodd = false;
    if (!visited[i]) {
      dfscomp(i);
      if (isodd) beg.push_back(i);
    }
  }
  if (beg.size() > 1) {
    cout << "-1";
    return 0;
  }
  if (beg.size() == 0) {
    cout << "0";
    return 0;
  }
  fill(visited, visited + 100020, false);
  dfs2(beg[0], -1);
  int size = path.size();
  vector<int>::iterator last = path.end();
  last--;
  if ((odd[beg[0]] && done[beg[0]] % 2 == 0) ||
      (!odd[beg[0]] && done[beg[0]] % 2 == 1))
    path.erase(last), size--;
  cout << size << endl;
  for (int i = 0; i < path.size(); i++) printf("%d ", path[i]);
  return 0;
};
