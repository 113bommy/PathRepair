#include <bits/stdc++.h>
using namespace std;
int adj[1010][1010];
char arr[1010][12][12];
int tab[1010], level[1010];
vector<int> adj2[1010];
set<pair<int, int> > se;
int vis2[1010];
void dfs(int u, int co) {
  for (int i : adj2[u]) {
    if (vis2[i]) continue;
    if (se.count(make_pair(u, i)))
      cout << i + 1 << " 0\n";
    else
      cout << i + 1 << " " << u + 1 << endl;
    vis2[i] = 1;
    dfs(i, co);
  }
}
int findBase(int a) {
  if (tab[a] == a) return a;
  return findBase(tab[a]);
}
void connect(int i, int j) {
  int x = findBase(i), y = findBase(j);
  if (level[x] > level[y])
    tab[y] = x;
  else {
    tab[x] = y;
    if (level[x] == level[y]) level[y]++;
  }
}
void init(int n) {
  for (int i = 0; i < n; i++) tab[i] = i, level[i] = 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, co, w, ans = 0;
  cin >> n >> m >> co >> w;
  for (int i = 0; i < co; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        cin >> arr[i][j][k];
        adj[k][k] = 1e9;
        for (int l = 0; l < i; l++) {
          adj[i][l] += ((arr[i][j][k] == arr[l][j][k]) ? 0 : w);
          adj[l][i] += ((arr[i][j][k] == arr[l][j][k]) ? 0 : w);
        }
      }
    }
  }
  init(co);
  vector<pair<int, pair<int, int> > > el;
  for (int i = 0; i < co; i++) {
    for (int j = 0; j < co; j++)
      el.push_back(make_pair(adj[i][j], pair<int, int>(i, j)));
  }
  sort(el.begin(), el.end());
  vector<pair<int, int> > path;
  int cost = 0;
  for (int i = 0; i < el.size(); i++) {
    pair<int, pair<int, int> > front = el[i];
    int a = front.second.first;
    int b = front.second.second;
    int w = front.first;
    if (findBase(a) != findBase(b)) {
      cost += min(w, n * m);
      if (n * m < w) se.insert(make_pair(a, b)), se.insert(make_pair(b, a));
      path.push_back(make_pair(a, b));
      connect(a, b);
    }
  }
  for (auto i : path)
    adj2[i.first].push_back(i.second), adj2[i.second].push_back(i.first);
  vis2[0] = 1;
  cout << n * m + cost << endl;
  cout << "1 0\n";
  dfs(0, co);
}
