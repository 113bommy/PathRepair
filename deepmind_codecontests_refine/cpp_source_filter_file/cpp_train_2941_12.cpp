#include <bits/stdc++.h>
using namespace std;
long long n, m, t, y, x, c, now, nxty, nxtx, nxtc;
bool a[1001][1001];
long long chk[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
string s;
struct node {
  long long y, x, c;
};
bool operator<(node a, node b) { return a.c > b.c; }
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) a[i][j] = s[j] - '0';
  }
  priority_queue<node> Q;
  node nd;
  memset(chk, -1, sizeof(chk));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        nxty = i + dy[k];
        nxtx = j + dx[k];
        if (nxty < 0 || nxtx < 0 || nxty >= n || nxtx >= m) continue;
        if (a[i][j] == a[nxty][nxtx]) {
          chk[i][j] = 0;
          nd.y = nxty;
          nd.x = nxtx;
          nd.c = 0;
          Q.emplace(nd);
          break;
        }
      }
    }
  while (!Q.empty()) {
    y = Q.top().y;
    x = Q.top().x;
    c = Q.top().c;
    Q.pop();
    if (c > chk[y][x]) continue;
    for (int k = 0; k < 4; k++) {
      nxty = y + dy[k];
      nxtx = x + dx[k];
      if (nxty < 0 || nxtx < 0 || nxty >= n || nxtx >= m) continue;
      if (chk[nxty][nxtx] != -1) continue;
      nxtc = c;
      if (a[nxty][nxtx] != a[y][x]) nxtc++;
      chk[nxty][nxtx] = nxtc;
      nd.y = nxty;
      nd.x = nxtx;
      nd.c = nxtc;
      Q.emplace(nd);
    }
  }
  while (t--) {
    cin >> y >> x >> c;
    y--;
    x--;
    if (chk[y][x] == -1 || c <= chk[y][x])
      cout << a[y][x] << '\n';
    else {
      c -= chk[y][x];
      if (c % 2)
        cout << !a[y][x] << '\n';
      else
        cout << a[y][x] << '\n';
    }
  }
  return 0;
}
