#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char arr[55][55];
int dfs(int i, int j, char prev, char next) {
  queue<pair<int, int> > que;
  que.push(make_pair(i, j));
  int temp(0);
  while (!que.empty()) {
    i = que.front().first;
    j = que.front().second;
    que.pop();
    if (arr[i][j] != prev) continue;
    arr[i][j] = next;
    temp++;
    if (i - 1 >= 0 && arr[i - 1][j] == prev) que.push(make_pair(i - 1, j));
    if (i + 1 <= n && arr[i + 1][j] == prev) que.push(make_pair(i + 1, j));
    if (j - 1 >= 0 && arr[i][j - 1] == prev) que.push(make_pair(i, j - 1));
    if (j + 1 >= 0 && arr[i][j + 1] == prev) que.push(make_pair(i, j + 1));
  }
  return temp;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  for (int i = 0; i < m; i++) {
    if (arr[0][i] == '.') dfs(0, i, '.', '?');
    if (arr[n - 1][i] == '.') dfs(n - 1, i, '.', '?');
  }
  for (int i = 1; i < n - 1; i++) {
    if (arr[i][0] == '.') dfs(i, 0, '.', '?');
    if (arr[i][m - 1] == '.') dfs(i, m - 1, '.', '?');
  }
  vector<pair<int, pair<int, int> > > pos;
  int temp;
  for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < m - 1; j++) {
      if (arr[i][j] == '.') {
        temp = dfs(i, j, '.', '!');
        pos.push_back(make_pair(temp, make_pair(i, j)));
      }
    }
  sort(pos.begin(), pos.end());
  int a, b, ans(0);
  for (int i = 0; i < pos.size() - k; i++) {
    a = pos[i].second.first;
    b = pos[i].second.second;
    ans += pos[i].first;
    dfs(a, b, '!', '*');
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == '?' || arr[i][j] == '!')
        cout << ".";
      else
        cout << "*";
    }
    cout << "\n";
  }
  return 0;
}
