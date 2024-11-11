#include <bits/stdc++.h>
using namespace std;
set<int> s;
set<int>::iterator it;
int b[1002][1002], mark[1002][1002], ans[1000003];
int dfs(int i, int j, int cnt) {
  int ans2 = 0;
  mark[i][j] = cnt;
  if (!mark[i - 1][j] && b[i - 1][j]) ans2 += dfs(i - 1, j, cnt) + 1;
  if (!mark[i][j - 1] && b[i][j - 1]) ans2 += dfs(i, j - 1, cnt) + 1;
  if (!mark[i + 1][j] && b[i + 1][j]) ans2 += dfs(i + 1, j, cnt) + 1;
  if (!mark[i][j + 1] && b[i][j + 1]) ans2 += dfs(i, j + 1, cnt) + 1;
  return ans2;
}
int main() {
  int n, m;
  char a;
  int cnt = 1, ansij = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a;
      if (a == '.') b[i][j] = true;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!mark[i][j] && b[i][j] == 1) ans[cnt] = dfs(i, j, cnt) + 1, cnt++;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (b[i][j] == 1)
        cout << '.';
      else {
        s.insert(mark[i - 1][j]);
        s.insert(mark[i][j - 1]);
        s.insert(mark[i + 1][j]);
        s.insert(mark[i][j + 1]);
        for (it = s.begin(); it != s.end(); ++it) ansij += ans[*it];
        cout << (ansij + 1) % 10;
        ansij = 0;
        s.clear();
      }
    }
    cout << endl;
  }
}
