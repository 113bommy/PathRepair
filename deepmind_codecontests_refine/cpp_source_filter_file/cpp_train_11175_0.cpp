#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int h, w; cin >> h >> w && h | w;) {
    vector<string> grid(h);
    for (int i = int(0); i < int(h); i++) cin >> grid[i];
    int si = -1, sj = -1;
    for (int i = int(0); i < int(h); i++)
      for (int j = int(0); j < int(w); j++)
        if (grid[i][j] == 'S') {
          grid[i][j] = '.';
          si = i;
          sj = j;
        }
    vector<string> g(2 * h);
    for (int i = int(0); i < int(2 * h); i++)
      for (int j = int(0); j < int(2); j++) g[i] += grid[i % h];
    vector<vector<int> > vis(2 * h, vector<int>(2 * w));
    queue<pair<int, int> > q;
    q.emplace(si, sj);
    while (q.size()) {
      int ci = q.front().first, cj = q.front().second;
      q.pop();
      if (ci < 0 || 2 * h <= ci || cj < 0 || 2 * w <= cj || g[ci][cj] == '#' ||
          vis[ci][cj])
        continue;
      vis[ci][cj] = 1;
      for (int k = int(0); k < int(4); k++) {
        int ni = ci + "\xff\x1\0\0"[k], nj = cj + "\0\0\xff\x1"[k];
        ni = (ni + 2 * h) % (2 * h);
        nj = (nj + 2 * h) % (2 * h);
        q.emplace(ni, nj);
      }
    }
    bool res = false;
    for (int i = int(0); i < int(h); i++)
      for (int j = int(0); j < int(w); j++)
        if (vis[i][j] + vis[i][j + w] + vis[i + h][j] + vis[i + h][j + w] >= 2)
          res = true;
    cout << (res ? "Yes" : "No") << endl;
  }
  return 0;
}
