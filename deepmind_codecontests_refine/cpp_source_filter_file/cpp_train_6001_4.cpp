#include <bits/stdc++.h>
using namespace std;
char ar[55][55];
int m, n;
string s;
bool visited[60][60];
vector<pair<int, int> > vec;
int BFS(int i, int j) {
  memset(visited, false, sizeof(visited));
  queue<pair<int, int> > q;
  q.push({i, j});
  visited[i][j] = true;
  int cnt = 0;
  while (!q.empty()) {
    pair<int, int> u = q.front();
    q.pop();
    int x = u.first + vec[s[cnt] - 48].first,
        y = u.second + vec[s[cnt] - 48].second;
    cnt++;
    if (cnt >= s.length()) break;
    if (x >= 0 && x < m && y >= 0 && y < n) {
      if (ar[x][y] != '#') q.push({x, y});
      if (ar[x][y] == 'E') {
        return true;
      }
      visited[x][y] = true;
    }
  }
  return false;
}
int main() {
  int x, y;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ar[i][j];
      if (ar[i][j] == 'S') x = i, y = j;
    }
  }
  cin >> s;
  vec.push_back({1, 0});
  vec.push_back({-1, 0});
  vec.push_back({0, -1});
  vec.push_back({0, 1});
  sort(vec.begin(), vec.end());
  int ch = 0;
  do {
    if (BFS(x, y)) ch++;
  } while (next_permutation(vec.begin(), vec.end()));
  cout << ch << endl;
  return 0;
}
