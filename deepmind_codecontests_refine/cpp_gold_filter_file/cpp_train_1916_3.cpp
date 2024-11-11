#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 100;
int n, m, h[N * N], a[N * N], ans, beg, en;
char c[N][N];
vector<int> adj[N * N];
void addedge(int i, int j) {
  if (c[i][j] == 'T') return;
  int v = i * m + j;
  int up = (i - 1) * m + j;
  int lft = i * m + j - 1;
  if (i && c[i - 1][j] != 'T') {
    adj[up].push_back(v);
    adj[v].push_back(up);
  }
  if (j && c[i][j - 1] != 'T') {
    adj[lft].push_back(v);
    adj[v].push_back(lft);
  }
}
void BFS() {
  queue<int> q;
  memset(h, -1, sizeof h);
  h[en] = 0;
  q.push(en);
  while (q.size()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v])
      if (h[u] == -1) h[u] = h[v] + 1, q.push(u);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> c[i][j];
      if (c[i][j] == 'T') continue;
      if (c[i][j] == 'S')
        beg = i * m + j;
      else if (c[i][j] == 'E')
        en = i * m + j;
      else
        a[i * m + j] = (int)c[i][j] - '0';
      addedge(i, j);
    }
  BFS();
  for (int i = 0; i < n * m; i++)
    if (h[i] <= h[beg] && h[i] != -1) ans += a[i];
  cout << ans << endl;
}
