#include <bits/stdc++.h>
using namespace std;
const int Maxn = 3000 + 10;
int n, m;
vector<int> nei[Maxn];
int d[Maxn][Maxn];
bool mark[Maxn];
void input();
void bfs(int v);
void output();
int main() {
  input();
  for (int i = 0; i < n; i++) bfs(i);
  output();
}
void input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    nei[a].push_back(b);
    nei[b].push_back(a);
  }
}
void bfs(int v) {
  for (int i = 0; i < n; i++) mark[i] = false;
  queue<int> q;
  d[v][v] = 0;
  q.push(v);
  mark[v] = true;
  while (!q.empty()) {
    int u = q.front();
    for (int i = 0; i < nei[u].size(); i++)
      if (!mark[nei[u][i]]) {
        q.push(nei[u][i]);
        d[v][nei[u][i]] = d[v][u] + 1;
        mark[nei[u][i]] = true;
      }
    q.pop();
  }
}
void output() {
  int t[2], s[2], l[2];
  cin >> s[0] >> t[0] >> l[0] >> s[1] >> t[1] >> l[1];
  s[0]--;
  t[0]--;
  s[1]--;
  t[1]--;
  int ans = m + 1;
  if (d[s[0]][t[0]] <= l[0] && d[s[1]][t[1]] <= l[1])
    ans = d[s[0]][t[0]] + d[s[1]][t[1]];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (d[s[0]][i] + d[i][j] + d[j][t[0]] <= l[0] &&
          d[s[1]][i] + d[i][j] + d[j][t[1]] <= l[1])
        ans = min(ans,
                  d[s[0]][i] + d[s[1]][i] + d[i][j] + d[t[0]][j] + d[t[1]][j]);
  swap(s[0], t[0]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (d[s[0]][i] + d[i][j] + d[j][t[0]] <= l[0] &&
          d[s[1]][i] + d[i][j] + d[j][t[1]] <= l[1])
        ans = min(ans,
                  d[s[0]][i] + d[s[1]][i] + d[i][j] + d[t[0]][j] + d[t[1]][j]);
  cout << m - ans << endl;
}
