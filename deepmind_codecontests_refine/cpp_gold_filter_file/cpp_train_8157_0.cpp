#include <bits/stdc++.h>
using namespace std;
const int M = 100 + 20;
pair<int, int> a[M];
char dir;
vector<int> domino;
vector<pair<int, int> > adj[M];
bool mark[M], check[M];
int cnt, start = -1, p[M];
void dfs(int v) {
  while (!adj[v].empty()) {
    int u = adj[v].back().first;
    int ind = adj[v].back().second;
    adj[v].pop_back();
    if (!mark[ind]) {
      mark[ind] = true;
      dfs(u);
    }
  }
  domino.push_back(v);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    adj[a[i].first].push_back({a[i].second, i});
    adj[a[i].second].push_back({a[i].first, i});
  }
  for (int i = 0; i <= 6; i++) {
    if (adj[i].size() % 2 == 1) {
      cnt++;
      start = i;
    }
  }
  if (cnt > 2) {
    cout << "No solution";
    return 0;
  }
  if (start >= 0) {
    dfs(start);
  } else {
    for (int i = 0; i < 7; i++) {
      if (adj[i].size()) start = i;
    }
    dfs(start);
  }
  if (domino.size() != n + 1) {
    cout << "No solution\n";
    return 0;
  }
  for (int i = 0; i < domino.size() - 1; i++) {
    int u = domino[i];
    int v = domino[i + 1];
    for (int j = 1; j <= n; j++) {
      if (!check[j]) {
        if (a[j].first == u && a[j].second == v) {
          cout << j << " "
               << "+"
               << "\n";
          check[j] = true;
          break;
        }
        if (a[j].first == v && a[j].second == u) {
          cout << j << " "
               << "-\n";
          check[j] = true;
          break;
        }
      }
    }
  }
}
