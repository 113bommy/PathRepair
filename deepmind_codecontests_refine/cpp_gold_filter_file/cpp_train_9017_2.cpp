#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 5;
string s;
int dist[maxn * maxn];
bool a[maxn][maxn], chek[maxn * maxn];
vector<int> v[maxn * maxn];
void bfs(int x) {
  chek[x] = true;
  queue<int> q;
  q.push(x);
  while (!q.empty()) {
    x = q.front();
    q.pop();
    for (int i = 0; i < (int)v[x].size(); i++)
      if (chek[v[x][i]] == false) {
        q.push(v[x][i]);
        chek[v[x][i]] = true;
        dist[v[x][i]] = dist[x] + 1;
      }
  }
}
int main() {
  int x = 102, y = 102, ii, jj, e[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  cin >> s;
  ii = x;
  jj = y;
  a[ii][jj] = true;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == 'U')
      ii--;
    else if (s[i] == 'D')
      ii++;
    else if (s[i] == 'R')
      jj++;
    else if (s[i] == 'L')
      jj--;
    a[ii][jj] = true;
  }
  for (int i = 0; i < maxn; i++)
    for (int j = 0; j < maxn; j++)
      for (int d = 0; d < 4; d++) {
        if (a[i][j] == false) {
          chek[i * maxn + j] = true;
          continue;
        }
        if (i + e[d][0] >= 0 && i + e[d][0] < maxn && j + e[d][1] < maxn &&
            j + e[d][1] >= 0)
          if (a[i + e[d][0]][j + e[d][1]] == true)
            v[i * maxn + j].push_back((i + e[d][0]) * maxn + j + e[d][1]);
      }
  bfs(x * maxn + y);
  if (dist[ii * maxn + jj] < (int)s.size()) {
    cout << "BUG" << endl;
    return 0;
  }
  cout << "OK" << endl;
  return 0;
}
