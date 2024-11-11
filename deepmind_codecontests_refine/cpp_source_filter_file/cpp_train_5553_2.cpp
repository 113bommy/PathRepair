#include <bits/stdc++.h>
using namespace std;
struct UFDS {
  int n;
  int p[2010], rank[2010], size[2010];
  UFDS(int n) : n(n) {
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      rank[i] = 0;
      size[i] = 1;
    }
  }
  int findSet(int i) {
    if (p[i] == i) return i;
    return p[i] = findSet(p[i]);
  }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int sizeOfSet(int i) { return size[findSet(i)]; }
  void unionSet(int i, int j) {
    int x = findSet(i);
    int y = findSet(j);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      p[x] = y;
      size[y] += size[x];
    } else {
      p[y] = x;
      size[x] += size[y];
      if (rank[y] == rank[x]) rank[x]++;
    }
  }
  void printSet(int i) {
    cout << "set id:" << findSet(i) << ":" << endl;
    for (int j = 0; j <= n; j++) {
      if (isSameSet(i, j)) cout << j << endl;
    }
    cout << "size:" << sizeOfSet(i) << endl;
  }
};
int n;
vector<int> adjList[2010];
bitset<2010> visited;
UFDS like(2010);
int dfs(int c) {
  if (visited[c]) return 0;
  visited[c] = 1;
  int ans = like.sizeOfSet(c);
  for (int i = 0; i < adjList[c].size(); i++) {
    if (!visited[adjList[c][i]]) {
      ans = max(ans, dfs(adjList[c][i]));
    }
  }
  return ans;
}
int main() {
  cin >> n;
  int k, m;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    like.unionSet(u, v);
  }
  set<int> superNodes;
  for (int i = 1; i <= n; i++) {
    superNodes.insert(like.p[i]);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    int x = like.findSet(u);
    int y = like.findSet(v);
    if (x == y) superNodes.erase(x);
  }
  int ans = 0;
  for (set<int>::iterator si = superNodes.begin(); si != superNodes.end();
       si++) {
    ans = max(ans, like.sizeOfSet(*si));
  }
  cout << ans << endl;
}
