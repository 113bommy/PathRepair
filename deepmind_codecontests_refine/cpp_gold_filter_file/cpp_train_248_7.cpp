#include <bits/stdc++.h>
using namespace std;
int v[505][505] = {{0}};
int n, m, k;
string s[505];
void dfs(int i, int j) {
  if (v[i][j] || s[i][j] == '#') return;
  v[i][j] = 1;
  dfs(i - 1, j);
  dfs(i, j - 1);
  dfs(i + 1, j);
  dfs(i, j + 1);
  if (k > 0) {
    s[i][j] = 'X';
    k--;
  } else
    return;
}
int main() {
  cin >> n >> m >> k;
  s[0] = "";
  s[n + 1] = "";
  for (int i = 0; i <= m; i++) {
    s[0] += "#";
    s[n + 1] += "#";
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = "#" + s[i] + "#";
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!v[i][j] && s[i][j] == '.') dfs(i, j);
    }
  }
  for (int i = 1; i <= n; i++) cout << s[i].substr(1, m) << endl;
  return 0;
}
