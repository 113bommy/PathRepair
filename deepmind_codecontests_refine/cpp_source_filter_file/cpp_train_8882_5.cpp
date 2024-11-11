#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e3 + 19;
vector<int> adj[maxn];
queue<int> q;
bool mark[maxn];
int h[maxn];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  char a;
  cin >> n >> m;
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) {
      cin >> a;
      if (a == '#') {
        adj[i].push_back(j + n);
        adj[j + n].push_back(i);
        if (i == n - 1) {
          q.push(j + n);
          mark[j + n] = true;
        }
      }
    }
  while (q.size()) {
    int v = q.front();
    q.pop();
    for (long long int i = 0; i < adj[v].size(); i++) {
      int u = adj[v][i];
      if (!mark[u]) {
        h[u] = h[v] + 1;
        mark[u] = true;
        q.push(u);
        if (u == n - 1) {
          cout << h[u] + 1;
          return 0;
        }
      }
    }
  }
  cout << -1;
  return 0;
}
