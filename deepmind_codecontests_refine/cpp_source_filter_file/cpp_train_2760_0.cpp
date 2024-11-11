#include <bits/stdc++.h>
using namespace std;
int n, m, c;
char a[1001][1001];
int vis[1001][1001] = {0};
int v[1001][1001];
int e[1001] = {0};
void dfs(int x, int y, int c) {
  if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || a[x][y] == '*' ||
      vis[x][y] == 1)
    return;
  vis[x][y] = 1;
  v[x][y] = c;
  e[c]++;
  dfs(x + 1, y, c);
  dfs(x - 1, y, c);
  dfs(x, y - 1, c);
  dfs(x, y + 1, c);
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  c = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.' && vis[i][j] == 0) {
        dfs(i, j, c);
        c++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      set<int> f;
      if (a[i][j] == '*') {
        if (i + 1 < n) f.insert(v[i + 1][j]);
        if (j + 1 < m) f.insert(v[i][j + 1]);
        if (i - 1 >= 0) f.insert(v[i - 1][j]);
        if (j - 1 >= 0) f.insert(v[i][j - 1]);
        int s = 0;
        for (auto ii : f) s += e[ii];
        s = s + 1;
        cout << s % 10;
      } else
        cout << ".";
    }
    cout << endl;
  }
  return 0;
}
