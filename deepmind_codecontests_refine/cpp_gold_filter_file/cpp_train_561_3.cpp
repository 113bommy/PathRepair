#include <bits/stdc++.h>
using namespace std;
char ar[505][505];
int main() {
  int n, m, k, x, y;
  int s = 0;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> ar[i][j];
      if (ar[i][j] == '.') {
        x = i;
        y = j;
        s++;
      }
    }
  }
  queue<pair<int, int> > q;
  q.push(make_pair(x, y));
  int cnt = 0;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    ar[p.first][p.second] = 'a';
    cnt++;
    if (cnt == s - k) break;
    if (p.first + 1 <= n) {
      if (ar[p.first + 1][p.second] == '.') {
        ar[p.first + 1][p.second] = 'b';
        q.push(make_pair(p.first + 1, p.second));
      }
    }
    if (p.first - 1 >= 1) {
      if (ar[p.first - 1][p.second] == '.') {
        ar[p.first - 1][p.second] = 'b';
        q.push(make_pair(p.first - 1, p.second));
      }
    }
    if (p.second + 1 <= m) {
      if (ar[p.first][p.second + 1] == '.') {
        ar[p.first][p.second + 1] = 'b';
        q.push(make_pair(p.first, p.second + 1));
      }
    }
    if (p.second - 1 >= 1) {
      if (ar[p.first][p.second - 1] == '.') {
        ar[p.first][p.second - 1] = 'b';
        q.push(make_pair(p.first, p.second - 1));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ar[i][j] == 'a')
        cout << '.';
      else if (ar[i][j] == '.' || ar[i][j] == 'b')
        cout << 'X';
      else
        cout << ar[i][j];
    }
    cout << endl;
  }
  return 0;
}
