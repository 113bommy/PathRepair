#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char arr[1042][1042];
map<pair<int, int>, int> M;
void BFS(int x, int y) {
  queue<pair<int, int>> Q;
  Q.push({x, y});
  int cnt = 0;
  vector<pair<int, int>> V;
  while (!Q.empty()) {
    auto f = Q.front();
    V.push_back(f);
    Q.pop();
    x = f.first;
    y = f.second;
    if (x > 0 and arr[x - 1][y] == '*') cnt++;
    if (x < n - 1 and arr[x + 1][y] == '*') cnt++;
    if (y > 0 and arr[x][y - 1] == '*') cnt++;
    if (y < m - 1 and arr[x][y + 1] == '*') cnt++;
    arr[x][y] = '#';
    if (x > 0 and arr[x - 1][y] == '.') {
      Q.push({x - 1, y});
      arr[x - 1][y] = '#';
    }
    if (x < n - 1 and arr[x + 1][y] == '.') {
      arr[x + 1][y] = '#';
      Q.push({x + 1, y});
    }
    if (y > 0 and arr[x][y - 1] == '.') {
      arr[x][y - 1] = '#';
      Q.push({x, y - 1});
    }
    if (y < m - 1 and arr[x][y + 1] == '.') {
      Q.push({x, y + 1});
      arr[x][y + 1] = '#';
    }
  }
  for (auto v : V) M[v] = cnt;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  cin >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (arr[i][j] == '.') BFS(i, j);
  for (int i = 0; i < k; i++) {
    cin >> n >> m;
    cout << M[{n - 1, m - 1}] << endl;
  }
  return 0;
}
