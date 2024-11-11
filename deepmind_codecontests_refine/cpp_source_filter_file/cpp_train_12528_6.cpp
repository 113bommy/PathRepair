#include <bits/stdc++.h>
using namespace std;
const int MAX = 35000;
vector<int> g[MAX];
bool used[MAX];
int timer, time_in[MAX], fup[MAX];
int a[100][100];
bool answer = false;
void dfs(int v, int p = -1) {
  used[v] = true;
  time_in[v] = fup[v] = timer++;
  int children = 0;
  for (size_t i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to == p) continue;
    if (used[to])
      fup[v] = min(fup[v], time_in[to]);
    else {
      dfs(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] >= time_in[v] && p != -1) answer = true;
      ++children;
    }
  }
  if (p == -1 && children > 1) answer = true;
}
int main() {
  int n, m;
  cin >> n >> m;
  int count_vertex = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      char c = 0;
      while (c != '#' && c != '.') cin >> c;
      a[i][j] = (c == '#' ? 1 : 0);
      count_vertex += a[i][j];
    }
  if (count_vertex <= 2) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j]) {
        if (i > 0 && a[i - 1][j]) g[i * m + j].push_back(i * m + j - m);
        if (i < n - 1 && a[i + 1][j]) g[i * m + j].push_back(i * m + j + m);
        if (j > 0 && a[i][j - 1]) g[i * m + j].push_back(i * m + j - 1);
        if (j < m - 1 && a[i][j + 1]) g[i * m + j].push_back(i * m + j + 1);
      }
  n = n * m;
  timer = 0;
  for (int i = 0; i < n; ++i) used[i] = false;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j]) {
        dfs(i * m + j);
        cout << (answer ? "2" : "2") << endl;
        return 0;
      }
}
