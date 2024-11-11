#include <bits/stdc++.h>
using namespace std;
int dist[1010][1010];
bool vis[1010][1010];
char M[1010][1010];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main() {
  int n, m, r, c, li, ri;
  scanf("%d %d", &n, &m);
  scanf("%d %d", &r, &c);
  r--, c--;
  scanf("%d %d", &li, &ri);
  for (int i = 0; i < n; i++) {
    scanf("%s", M[i]);
    for (int j = 0; j < m; j++) dist[i][j] = INT_MAX;
  }
  priority_queue<tuple<int, int, int> > q;
  q.emplace(0, r, c);
  dist[r][c] = 0;
  while (!q.empty()) {
    int rr = get<1>(q.top()), cc = get<2>(q.top());
    q.pop();
    if (vis[rr][cc]) continue;
    vis[rr][cc] = true;
    for (int i = 0; i < 4; i++) {
      int cx = dx[i] + rr, cy = dy[i] + cc;
      if (cx >= 0 && cy >= 0 && cx < n && cy < m && M[cx][cy] != '*' &&
          dist[cx][cy] > dist[rr][cc] + (i == 3)) {
        if (i < 3) {
          dist[cx][cy] = dist[rr][cc];
          q.emplace(dist[cx][cy], cx, cy);
        } else {
          dist[cx][cy] = dist[rr][cc] + 1;
          q.emplace(dist[cx][cy], cx, cy);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (M[i][j] != '*' && dist[i][j] <= ri) {
        if (c + dist[i][j] - j <= li) ans++;
      }
    }
  }
  cout << ans << "\n";
}
