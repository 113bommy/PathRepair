#include <bits/stdc++.h>
using namespace std;
int i, j, cs;
vector<int> v[4003];
const int INF = 1000000000;
int source;
int mn = INF;
void dfs(int u, int depth, int total) {
  for (auto x : v[u]) {
    if (depth > 1 and x != source) {
      dfs(x, depth - 1, total + v[x].size());
    } else if (depth == 1 and x == source) {
      if (total < mn) {
        mn = total - 6;
      }
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  int x, y;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (i = 1; i < n + 1; i++) {
    source = i;
    dfs(i, 3, v[i].size());
  }
  if (mn == INF)
    cout << "-1" << endl;
  else
    cout << mn << endl;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
