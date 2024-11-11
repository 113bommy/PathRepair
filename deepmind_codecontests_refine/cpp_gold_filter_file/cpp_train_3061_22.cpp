#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
const int INF = 2e17;
vector<vector<pair<int, vector<int> > > > g;
int n, m;
int is[100][100];
deque<int> path;
bool dfs(int now, int mode) {
  if (now == ((int)path.size()) - 1) return true;
  int id = path.at(now), nex = path.at(now + 1);
  if (is[id][nex] == -1) return false;
  int a = is[id][nex];
  if (!now && (int)g[id][a].second.size() == 0) return true;
  if (mode != 2) {
    if (!mode) {
      for (int i = ((int)g[id][a].second.size()) - 1; i >= 0; i--) {
        int b = g[id][a].second[i];
        path.push_front(b);
        if ((int)path.size() > 2 * n) return false;
        now++;
      }
      if (dfs(now - 1, mode)) return true;
    } else {
      for (int i = 0; i <= ((int)g[id][a].second.size()) - 1; i++) {
        int b = g[id][a].second[i];
        path.push_back(b);
        if ((int)path.size() > 2 * n) return false;
      }
      if (dfs(now + 1, mode)) return true;
    }
  } else if (dfs(now + 1, 1) && (now ? dfs(now - 1, 0) : true))
    return true;
  return false;
}
int main() {
  cin >> n >> m;
  g.resize(n);
  int a, b, c;
  vector<int> temp;
  memset(is, -1, sizeof is);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    g[a].push_back(make_pair(b, temp));
    is[a][b] = ((int)g[a].size()) - 1;
    cin >> c;
    for (int j = 0; j < c; j++) {
      scanf("%d", &b);
      b--;
      g[a][((int)g[a].size()) - 1].second.push_back(b);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (is[i][j] == -1) continue;
      a = is[i][j];
      int can = 0;
      int now = 0;
      for (int k = 0; k < ((int)g[i][a].second.size()) - 1; k++) {
        b = g[i][a].second[k];
        c = g[i][a].second[k + 1];
        if (b == i && c == j) {
          can++;
          now = k;
          break;
        }
      }
      if (!can) continue;
      path.clear();
      for (int k = 0; k < (int)g[i][a].second.size(); k++) {
        b = g[i][a].second[k];
        path.push_back(b);
      }
      if (dfs(now, 2)) {
        ans = (int)path.size();
        break;
      }
    }
    if (ans) break;
  }
  cout << ans << endl;
  if (ans)
    while (!path.empty()) {
      cout << path.front() + 1 << " ";
      path.pop_front();
    }
}
