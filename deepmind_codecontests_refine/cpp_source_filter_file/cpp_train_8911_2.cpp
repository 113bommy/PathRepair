#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int S, T;
string s[55];
set<pair<int, int>> se;
int dist(int a, int b) { return abs(a / m - b / m) + abs(a % m - b % m); }
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void Dijstra() {
  priority_queue<pair<pair<int, string>, pair<int, int>>,
                 vector<pair<pair<int, string>, pair<int, int>>>,
                 greater<pair<pair<int, string>, pair<int, int>>>>
      Q;
  Q.push({{dist(S, T), ""}, {0, S}});
  pair<pair<int, string>, pair<int, int>> ss, tt;
  string str;
  int book, pos;
  int x, y, xx, yy;
  while (!Q.empty()) {
    ss = Q.top();
    Q.pop();
    str = ss.first.second;
    book = ss.second.first;
    pos = ss.second.second;
    if (!se.count({book, pos})) {
      se.insert({book, pos});
      x = pos / m, y = pos % m;
      for (int i = 0; i < 4; i++) {
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        if (xx >= 0 && xx < n && yy > 0 && yy < m) {
          if (s[xx][yy] == 'T') {
            cout << str << endl;
            exit(0);
          }
          if (__builtin_popcount(book | (1 << (s[xx][yy] - 'a'))) <= k)
            Q.push({{dist(xx * m + yy, T) + str.length() + 1, str + s[xx][yy]},
                    {book | (1 << (s[xx][yy] - 'a')), xx * m + yy}});
        }
      }
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'S') {
        S = i * m + j;
      }
      if (s[i][j] == 'T') {
        T = i * m + j;
      }
    }
  }
  Dijstra();
  cout << -1 << endl;
}
