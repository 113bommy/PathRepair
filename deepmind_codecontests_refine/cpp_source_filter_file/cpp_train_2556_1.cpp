#include <bits/stdc++.h>
using namespace std;
int n, r, d[100010][10], c[10][1 << 9], id[100010], dc[10][10];
long long t;
char ss[100010];
void up(int x, int c) {
  if (x == r) t += c;
  if (x > r) {
    r = x;
    t = c;
  }
}
vector<int> v[100010];
void bfs(int s) {
  queue<int> q;
  for (auto i : v[s]) q.push(i);
  for (int i = 1; i <= n; i++) {
    if (ss[i] == s + 'a')
      d[i][s] = 0;
    else
      d[i][s] = 0x3f3f3f3f;
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (d[x - 1][s] == 0x3f3f3f3f) {
      d[x - 1][s] = d[x][s] + 1;
      q.push(x - 1);
    }
    if (d[x + 1][s] == 0x3f3f3f3f) {
      d[x + 1][s] = d[x][s] + 1;
      q.push(x + 1);
    }
  }
}
void add(int p) { c[ss[p] - 'a'][id[p]]++; }
int main() {
  cin >> n >> ss + 1;
  for (int i = 1; i <= n; i++) v[ss[i] - 'a'].push_back(i);
  for (int i = 0; i < 8; i++) bfs(i);
  memset(dc, 0x3f, sizeof(dc));
  for (int i = 0; i < 8; i++) dc[i][i] = 0;
  for (int k = 1; k <= n; k++)
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++) dc[i][j] = min(dc[i][j], d[k][i] + d[k][j]);
  for (int k = 0; k < 8; k++)
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        dc[i][j] = min(dc[i][j], dc[i][k] + dc[k][j] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 8; j++)
      for (int k = 0; k < 8; k++)
        d[i][k] = min(d[i][k], d[i][j] + dc[j][k] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 8; j++) id[i] |= ((d[i][j] - dc[ss[i] - 'a'][j]) << j);
  for (int r = 1; r <= n; r++)
    for (int l = max(1, r - 15); l < r; l++) {
      int mn = r - l;
      for (int j = 0; j < 8; j++) mn = min(mn, d[l][j] + d[r][j] + 1);
      up(mn, 1);
    }
  int j = 1;
  for (int i = 17; i <= n; i++, j++) {
    add(j);
    for (int k = 0; k < 8; k++)
      for (int l = 0; l < 256; l++)
        if (c[k][l]) {
          int mn = 1e9;
          for (int c = 0; c < 8; c++)
            mn = min(mn, dc[k][c] + d[i][c] + ((l >> c) & 1));
          up(mn, c[k][l]);
        }
  }
  cout << r << ' ' << t;
}
