#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000000];
int vis[1000000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    int x, y;
    for (int i = 1; i <= n - 1; i++) {
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
      vis[i] = INT_MAX;
    }
    vis[a] = 0;
    queue<int> q;
    q.push(a);
    while (q.size() > 0) {
      int x = q.front();
      for (int j = 0; j < v[x].size(); j++) {
        if (vis[v[x][j]] == INT_MAX) {
          vis[v[x][j]] = vis[x] + 1;
          q.push(v[x][j]);
        }
      }
      q.pop();
    }
    if (vis[b] <= da) {
      for (int i = 1; i <= n; i++) {
        v[i].clear();
      }
      cout << "Alice" << endl;
      continue;
    }
    int maxx = 0;
    int ind = 0;
    for (int i = 1; i <= n; i++) {
      if (vis[i] > maxx) {
        maxx = vis[i];
        ind = i;
      }
    }
    for (int i = 1; i <= n; i++) {
      vis[i] = INT_MAX;
    }
    q.push(ind);
    vis[ind] = 0;
    while (q.size() > 0) {
      int x = q.front();
      for (int j = 0; j < v[x].size(); j++) {
        if (vis[v[x][j]] == INT_MAX) {
          vis[v[x][j]] = vis[x] + 1;
          q.push(v[x][j]);
        }
      }
      q.pop();
    }
    int maxx1 = 0;
    for (int i = 1; i <= n; i++) {
      if (vis[i] > maxx1) {
        maxx1 = vis[i];
      }
    }
    for (int i = 1; i <= n; i++) {
      v[i].clear();
    }
    if (maxx1 <= 2 * da) {
      cout << "Alice" << endl;
      continue;
    }
    if (db > 2 * da) {
      cout << "Bob" << endl;
    } else {
      cout << "Alice" << endl;
    }
  }
  return 0;
}
