#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g[100005];
map<pair<int, int>, int> num;
int n, i, j, a, b;
pair<int, int> node[100005];
vector<int> ag[100005];
void go(int v, int prev) {
  int i, j;
  if (prev > 0) {
    for (j = 0; j < g[v].size(); j++)
      if (g[v][j].second == num[make_pair(v, prev)]) {
        swap(g[v][j], g[v][g[v].size() - 1]);
        break;
      }
  }
  for (j = 0; j < g[v].size(); j++) {
    int nxt = g[v][j].first;
    if (nxt == prev) continue;
    go(nxt, v);
  }
}
int main() {
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> a >> b;
    num[make_pair(a, b)] = i;
    num[make_pair(b, a)] = i;
    node[i] = make_pair(a, b);
    g[a].push_back(make_pair(b, i));
    g[b].push_back(make_pair(a, i));
  }
  go(1, 0);
  for (i = 1; i <= n; i++) {
    for (j = 0; j < g[i].size() - 1; j++) {
      ag[g[i][j].second].push_back(g[i][j + 1].second);
    }
  }
  cout << n - 1 << endl;
  for (i = 0; i < n - 1; i++)
    cout << 2 << " " << node[i + 1].first << " " << node[i + 1].second << endl;
  for (i = 1; i <= n; i++)
    for (j = 0; j < ag[i].size(); i++) cout << ag[i][j] << " " << i << endl;
}
