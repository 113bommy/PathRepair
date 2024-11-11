#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int> > p;
int n, m;
int a[2000][2000];
bool vis[2000][2000];
vector<pair<pair<int, int>, pair<int, int> > > ans;
void out() {
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (vis[i][j])
        cout << '.';
      else
        cout << '*';
    cout << endl;
  }
}
void jian(int i, int j) {
  a[i][j]--;
  if (vis[i][j] && a[i][j] <= 1) p.push(pair<int, int>(i, j));
}
void sub(int i, int j) {
  vis[i][j] = 0;
  if (i) jian(i - 1, j);
  if (j) jian(i, j - 1);
  if (i < n - 1) jian(i + 1, j);
  if (j < m - 1) jian(i, j + 1);
}
vector<string> ret;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string H;
    cin >> H;
    for (int j = 0; j < m; j++) {
      char u;
      u = H[j];
      if (u == '*')
        vis[i][j] = 0;
      else
        vis[i][j] = 1;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      a[i][j] += 4;
      if (i == 0) a[i][j]--;
      if (i == n - 1) a[i][j]--;
      if (j == 0) a[i][j]--;
      if (j == m - 1) a[i][j]--;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (vis[i][j] == 0) sub(i, j);
  while (!p.empty()) {
    pair<int, int> tem = p.front();
    p.pop();
    int x = tem.first, y = tem.second;
    if (vis[x][y] == 0) continue;
    if (a[x][y] == 0) {
      cout << "Not unique" << endl;
      return 0;
    }
    int i = x;
    int j = y;
    pair<int, int> next;
    if (i && vis[i - 1][j]) next = pair<int, int>(i - 1, j);
    if (j && vis[i][j - 1]) next = pair<int, int>(i, j - 1);
    if (i < n - 1 && vis[i + 1][j]) next = pair<int, int>(i + 1, j);
    if (j < m - 1 && vis[i][j + 1]) next = pair<int, int>(i, j + 1);
    vis[next.first][next.second] = 0;
    vis[x][y] = 0;
    ans.push_back(pair<pair<int, int>, pair<int, int> >(tem, next));
    sub(x, y);
    sub(next.first, next.second);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (vis[i][j] == 1) {
        cout << "Not unique" << endl;
        return 0;
      }
  ret = vector<string>(n, string(m, '*'));
  for (int i = 0; i < ans.size(); i++) {
    pair<int, int> a1 = ans[i].first, a2 = ans[i].second;
    if (a1.first > a2.first || (a1.first == a2.first && a1.second > a2.second))
      swap(a1, a2);
    if (a1.first == a2.first) {
      ret[a1.first][a1.second] = '<';
      ret[a2.first][a2.second] = '>';
    } else {
      ret[a1.first][a1.second] = '^';
      ret[a2.first][a2.second] = 'v';
    }
  }
  for (int i = 0; i < ret.size(); i++) cout << ret[i] << endl;
  return 0;
}
