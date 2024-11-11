#include <bits/stdc++.h>
using namespace std;
int n, k;
char canyon[2][100005];
int bfs(int _n) {
  bool is_visited[2][_n];
  memset(is_visited, 0, sizeof is_visited);
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(0, 0), -1));
  while (q.size()) {
    pair<int, int> p = q.front().first;
    int water = q.front().second;
    q.pop();
    if (p.second < 0 || p.second <= water) {
      continue;
    }
    if (p.second >= n) {
      return 1;
    }
    if (!is_visited[p.first][p.second]) {
      is_visited[p.first][p.second] = 1;
      if (canyon[p.first][p.second] == '-') {
        if (p.first) {
          q.push(make_pair(make_pair(1, p.second + 1), water + 1));
          q.push(make_pair(make_pair(1, p.second - 1), water + 1));
          q.push(make_pair(make_pair(0, p.second + k), water + 1));
        } else {
          q.push(make_pair(make_pair(0, p.second + 1), water + 1));
          q.push(make_pair(make_pair(0, p.second - 1), water + 1));
          q.push(make_pair(make_pair(1, p.second + k), water + 1));
        }
      }
    }
  }
  return 0;
}
int main() {
  cin >> n >> k;
  string s;
  cin >> s;
  for (int x = 0; x < n; x++) {
    canyon[0][x] = s[x];
  }
  cin >> s;
  for (int x = 0; x < n; x++) {
    canyon[1][x] = s[x];
  }
  if (bfs(n)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
