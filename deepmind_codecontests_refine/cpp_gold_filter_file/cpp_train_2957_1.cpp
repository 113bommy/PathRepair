#include <bits/stdc++.h>
using namespace std;
int n, m, perm[101001];
vector<vector<int> > adj;
bool check(int x, int y) {
  for (int i = 0; i < adj[x].size(); ++i)
    if (adj[x][i] == y) return 0;
  return 1;
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  adj.resize(n + 1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int it = 1; it <= 100; ++it) {
    for (int i = 1; i <= n; ++i) perm[i] = i;
    random_shuffle(perm + 1, perm + n + 1);
    perm[n + 1] = perm[1];
    bool ok = 1;
    for (int i = 1; i <= m; ++i)
      if (!check(perm[i], perm[i + 1])) {
        ok = 0;
        break;
      }
    if (ok) {
      for (int i = 1; i <= m; ++i)
        cout << perm[i] << " " << perm[i + 1] << endl;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
