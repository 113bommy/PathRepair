#include <bits/stdc++.h>
using namespace std;
vector<int> adj[102];
vector<int> cleared;
int n, m;
int main() {
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  int sum = 0;
  int cnt = 0;
  bool works = true;
  while (works) {
    cleared.clear();
    for (int i = 0; i < n; i++) {
      if (adj[i].size() == 1) {
        cnt++;
        cleared.push_back(i);
        adj[i].clear();
      }
    }
    for (int k = 0; k < cleared.size(); k++) {
      int i = cleared[k];
      for (int j = 0; j < adj[adj[i][0]].size(); j++) {
        if (adj[adj[i][0]][j] == k) {
          adj[adj[i][0]].erase(adj[adj[i][0]].begin() + j);
        }
      }
    }
    if (cnt == 0) {
      works = false;
    } else {
      sum += 1;
    }
    cnt = 0;
  }
  cout << sum << endl;
  return 0;
}
