#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<set<int> > v(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a].insert(b);
    v[b].insert(a);
  }
  int way[n + 1];
  bool vis[n + 1];
  for (int i = 1; i <= n; i++) {
    vis[i] = false;
  }
  for (int i = 1; i <= n; i++) {
    cin >> way[i];
  }
  if (way[1] != 1) {
    cout << "No";
    return 0;
  }
  queue<int> q;
  vector<int> yo;
  yo.push_back(0);
  yo.push_back(1);
  q.push(1);
  vis[1] = true;
  int j = 2;
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (int i = 0; i < v[a].size(); i++) {
      if (v[a].find(way[j]) == v[a].end()) {
        continue;
      }
      if (!vis[way[j]]) {
        q.push(way[j]);
        yo.push_back(way[j]);
        vis[way[j]] = true;
        j++;
      }
    }
  }
  if (yo.size() != n + 1) {
    cout << "No";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (yo[i] != way[i]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
