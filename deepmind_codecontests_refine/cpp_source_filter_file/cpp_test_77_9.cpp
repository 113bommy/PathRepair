#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[101][101];
bool fl[101][101];
int s = 0;
vector<int> v;
void Dfs(int r, int c) {
  fl[r][c] = 1;
  s += 1;
  int k = a[r][c];
  if (k % 2 == 0) {
    if (c > 1 && fl[r][c - 1] == 0) Dfs(r, c - 1);
  }
  k /= 2;
  if (k % 2 == 0) {
    if (r < n && fl[r + 1][c] == 0) Dfs(r + 1, c);
  }
  k /= 2;
  if (k % 2 == 0) {
    if (c < m && fl[r][c + 1] == 0) Dfs(r, c + 1);
  }
  k /= 2;
  if (k % 2 == 0) {
    if (r > 1 && fl[r - 1][c] == 0) Dfs(r - 1, c);
  }
}
int main() {
  cin >> n >> m;
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (fl[i][j] == 0) s = 0, Dfs(i, j), v.push_back(s);
    }
  }
  sort(v.begin(), v.end());
  for (i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
  cout << endl;
  return 0;
}
