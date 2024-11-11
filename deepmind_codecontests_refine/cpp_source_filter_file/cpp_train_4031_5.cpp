#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000 * 1000 * 1000 + 7;
vector<vector<int> > g(100002);
int qan[100002];
vector<pair<int, int> > ans;
void dfs(int v, int p) {
  if (g[v].size() == 1 && g[v][0] == p) {
    cout << v << endl;
  }
  for (int i = 0; i <= (int)g[v].size() - 1; i++) {
    int to = g[v][i];
    if (to != p) {
      if (p == -1) cout << v << " ";
      dfs(to, v);
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= (int)n - 1; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    qan[x]++;
    qan[y]++;
  }
  int k = 0;
  for (int i = 1; i <= (int)n; i++)
    if (qan[i] >= 3) k++;
  if (k >= 2) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 1; i <= (int)n; i++) {
    if (qan[i] >= 3) {
      cout << "YES" << endl;
      cout << qan[i] << endl;
      dfs(i, -1);
      return 0;
    }
  }
  cout << "YES" << endl;
  cout << qan[1] << endl;
  dfs(1, -1);
  return 0;
}
