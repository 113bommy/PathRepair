#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[110];
bool mark[110];
int mat[10][10], deg[10], res[110], top, n;
inline void dfs(int x) {
  for (int i = 0; i < 7; i++)
    if (mat[x][i]) {
      mat[x][i]--;
      mat[i][x]--;
      deg[x]--;
      deg[i]--;
      dfs(i);
    }
  res[top++] = x;
}
inline void solve() {
  int odd = 0;
  for (int i = 0; i < 7; i++)
    if (deg[i] % 2) odd++;
  if (odd && odd != 2) {
    cout << "No solution" << endl;
    return;
  }
  for (int i = 0; i < 7; i++)
    if (odd) {
      if (deg[i] % 2) {
        dfs(i);
        break;
      }
    } else if (deg[i]) {
      dfs(i);
      break;
    }
  if (top != n + 1) {
    cout << "No solution" << endl;
    return;
  }
  for (int k = 0; k < top - 1; k++) {
    int a = res[k], b = res[k + 1];
    for (int i = 0; i < n; i++)
      if (!mark[i])
        if (a == p[i].first && b == p[i].second) {
          cout << i + 1 << " +" << endl;
          mark[i] = 1;
          break;
        } else if (a == p[i].second && b == p[i].first) {
          cout << i + 1 << " -" << endl;
          mark[i] = 1;
          break;
        }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    mat[p[i].first][p[i].second]++;
    mat[p[i].second][p[i].first]++;
    deg[p[i].first]++;
    deg[p[i].second]++;
  }
  solve();
  return 0;
}
