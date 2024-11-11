#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long x, y;
};
int n;
vector<long long> v[40];
bool vis[40];
Point p[40];
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
void dfs(long long s, long long par, int dir, long long d) {
  long long dist = d / 2;
  for (int i = 0; i < v[s].size(); i++) {
    if (v[s][i] == par) continue;
    dir = (dir + 1) % 4;
    p[v[s][i]].x = p[s].x + dx[dir] * dist;
    p[v[s][i]].y = p[s].y + dy[dir] * dist;
    dfs(v[s][i], s, (dir + 2) % 4, dist);
  }
}
int main() {
  cin >> n;
  int x, y;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= 35; i++) {
    if (v[i].size() > 4) {
      printf("NO");
      return 0;
    }
  }
  p[1].x = 0ll;
  p[1].y = 0ll;
  dfs(1, -1, 0, 1LL << 59);
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << p[i].x << " " << p[i].y;
    if (i < n) cout << "\n";
  }
  return 0;
}
