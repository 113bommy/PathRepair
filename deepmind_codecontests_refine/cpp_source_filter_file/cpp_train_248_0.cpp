#include <bits/stdc++.h>
using namespace std;
int ct1, n, m, k, ct;
vector<string> a;
bool visited[501][501];
void dfs(int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= m || ct1 == ct || a[i][j] == '#' ||
      visited[i][j])
    return;
  visited[i][j] = true;
  ct1++;
  dfs(i - 1, j);
  dfs(i + 1, j);
  dfs(i, j - 1);
  dfs(i, j + 1);
}
void solve() {
  cin >> n >> m >> k;
  ct = 0;
  a.clear();
  int x = -1, y = -1;
  string s;
  ct = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) visited[i][j] = false;
  for (int i = 0; i < n; i++) {
    cin >> s;
    a.push_back(s);
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        x = i;
        y = j;
        ct++;
      }
    }
  }
  ct = ct - k;
  ct1 = 0;
  dfs(-1, -1);
  ct1 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j] and a[i][j] == '.' and ct1 < k) {
        a[i][j] = 'X';
        ct1++;
      }
    }
    cout << a[i] << endl;
  }
}
int main() {
  int t;
  t = 1;
  while (t--) solve();
}
