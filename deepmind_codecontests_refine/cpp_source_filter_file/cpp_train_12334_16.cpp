#include <bits/stdc++.h>
using namespace std;
const int MAX = 2009;
const int MOD = 69;
queue<pair<int, int> > oneAdj;
string s[MAX];
int adj[MAX][MAX];
bool v[MAX][MAX];
void checkAdj(int a, int b) {
  adj[a - 1][b]--;
  adj[a + 1][b]--;
  adj[a][b - 1]--;
  adj[a][b + 1]--;
  if (s[a - 1][b] == '.' && adj[a - 1][b] == 1) oneAdj.push({a - 1, b});
  if (s[a + 1][b] == '.' && adj[a - 1][b] == 1) oneAdj.push({a + 1, b});
  if (s[a][b - 1] == '.' && adj[a][b - 1] == 1) oneAdj.push({a, b - 1});
  if (s[a][b + 1] == '.' && adj[a][b + 1] == 1) oneAdj.push({a, b + 1});
  if (adj[a - 1][b] == 0) v[a - 1][b] = 1;
  if (adj[a + 1][b] == 0) v[a + 1][b] = 1;
  if (adj[a][b - 1] == 0) v[a][b - 1] = 1;
  if (adj[a][b + 1] == 0) v[a][b + 1] = 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  s[0].insert(s[0].begin(), m + 2, ' ');
  s[n + 1].insert(s[n + 1].begin(), m + 2, ' ');
  for (int i = 1; i <= n; i++) cin >> s[i], s[i] = " " + s[i] + " ";
  for (int i = 1; i <= n; i++)
    for (int t = 1; t <= m; t++) {
      int num = 0;
      if (s[i - 1][t] == '.') num++;
      if (s[i + 1][t] == '.') num++;
      if (s[i][t - 1] == '.') num++;
      if (s[i][t + 1] == '.') num++;
      adj[i][t] = num;
      if (num == 1 && s[i][t] == '.') oneAdj.push({i, t});
    }
  while (oneAdj.size()) {
    pair<int, int> x = oneAdj.front();
    oneAdj.pop();
    if (v[x.first][x.second]) continue;
    if (s[x.first + 1][x.second] == '.') {
      s[x.first][x.second] = '^';
      s[x.first + 1][x.second] = 'v';
      v[x.first + 1][x.second] = 1;
      checkAdj(x.first + 1, x.second);
    }
    if (s[x.first - 1][x.second] == '.') {
      s[x.first][x.second] = 'v';
      s[x.first - 1][x.second] = '^';
      v[x.first - 1][x.second] = 1;
      checkAdj(x.first - 1, x.second);
    }
    if (s[x.first][x.second + 1] == '.') {
      s[x.first][x.second] = '<';
      s[x.first][x.second + 1] = '>';
      v[x.first][x.second + 1] = 1;
      checkAdj(x.first, x.second + 1);
    }
    if (s[x.first][x.second - 1] == '.') {
      s[x.first][x.second] = '>';
      s[x.first][x.second - 1] = '<';
      v[x.first][x.second - 1] = 1;
      checkAdj(x.first, x.second - 1);
    }
  }
  for (int i = 1; i <= n; i++)
    for (int t = 1; t <= m; t++)
      if (s[i][t] == '.') return cout << "Not unique\n", 0;
  for (int i = 1; i <= n; i++) {
    for (int t = 1; t <= m; t++) cout << s[i][t];
    cout << "\n";
  }
  return 0;
}
