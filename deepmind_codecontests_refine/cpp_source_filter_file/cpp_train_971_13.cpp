#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
string giraffe[2];
int visited[2][maxn];
int h[2][maxn];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {-1, 1, 0, 0};
queue<pair<int, int>> q;
int n, k;
bool safe(int x, int y) {
  if (y == 0 || y == 1) {
    if (x >= 0 && x < n)
      if (giraffe[y][x] == '-')
        if (!visited[y][x]) return 1;
  }
  return 0;
}
void bfs() {
  while (!q.empty()) {
    pair<int, int> sar = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = sar.first + dx[i];
      int y = sar.second + dy[i];
      if (safe(x, y) && (sar.first > h[sar.second][sar.first])) {
        q.push(make_pair(x, y));
        h[y][x] = h[sar.second][sar.first] + 1;
        visited[y][x] = true;
      }
      if (x >= n) {
        cout << "YES\n";
        exit(0);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> giraffe[0] >> giraffe[1];
  dx[2] = k;
  dx[3] = k;
  q.push(make_pair(0, 0));
  memset(h, -1, sizeof(h));
  visited[0][0] = true;
  bfs();
  cout << "NO\n";
}
