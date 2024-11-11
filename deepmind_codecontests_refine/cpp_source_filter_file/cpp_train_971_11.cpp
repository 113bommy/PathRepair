#include <bits/stdc++.h>
using namespace std;
char a[3][100002];
long long d[3][100002];
int used[3][100002];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= 2; i++) {
    for (int k = 1; k <= n; k++) {
      cin >> a[i][k];
    }
  }
  d[1][1] = 0;
  used[1][1] = 1;
  queue<pair<int, int> > q;
  q.push({1, 1});
  int w = 0;
  while (!q.empty()) {
    pair<int, int> t = q.front();
    if (t.second >= n) {
      cout << "YES";
      return 0;
    }
    w = d[t.first][t.second];
    q.pop();
    if (t.second + 1 <= n && used[t.first][t.second + 1] == 0 &&
        a[t.first][t.second + 1] != 'X') {
      d[t.first][t.second + 1] = d[t.first][t.second] + 1;
      q.push({t.first, t.second + 1});
      used[t.first][t.second + 1] = 1;
    }
    if (t.second - 1 > 0 && used[t.first][t.second - 1] == 0 &&
        t.second - 1 > w + 1 && a[t.first][t.second - 1] != 'X') {
      d[t.first][t.second - 1] = d[t.first][t.second] + 1;
      used[t.first][t.second - 1] = 1;
      q.push({t.first, t.second - 1});
    }
    if (t.first == 1) {
      if (used[t.first + 1][t.second + m] == 0 &&
          a[t.first + 1][t.second + m] != 'X') {
        if (t.second + m <= n) {
          d[t.first + 1][t.second + m] = d[t.first][t.second] + 1;
          used[t.first + 1][t.second + m] = 1;
          q.push({t.first + 1, t.second + m});
        } else {
          d[t.first + 1][n] = d[t.first][t.second] + 1;
          used[t.first + 1][n] = 1;
          q.push({t.first + 1, n});
        }
      }
    } else {
      if (used[t.first - 1][t.second + m] == 0 &&
          a[t.first - 1][t.second + m] != 'X') {
        if (t.second + m <= n) {
          d[t.first - 1][t.second + m] = d[t.first][t.second] + 1;
          used[t.first - 1][t.second + m] = 1;
          q.push({t.first - 1, t.second + m});
        } else {
          d[t.first - 1][n] = d[t.first][t.second] + 1;
          used[t.first - 1][n] = 1;
          q.push({t.first - 1, n});
        }
      }
    }
  }
  cout << "NO";
  return 0;
}
