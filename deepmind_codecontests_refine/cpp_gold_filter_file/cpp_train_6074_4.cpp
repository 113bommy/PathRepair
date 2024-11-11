#include <bits/stdc++.h>
using namespace std;
vector<int> edge[100010];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = ans + (edge[i].size() & 1);
  for (int i = 1; i <= n; i++)
    if (edge[i].size() == 2) {
      int x = edge[i][0], y = edge[i][1];
      if (x == y)
        edge[x].clear(), ans += 2;
      else
        edge[x][edge[x][0] != i] = y, edge[y][edge[y][0] != i] = x;
    }
  cout << ans / 2 << " " << m;
  return 0;
}
