#include <bits/stdc++.h>
using namespace std;
int a[4][2];
int b[4];
int ans = 1e9;
int tar[4][2];
void update(int q[4][2]) {
  int dist = 0;
  for (int i = 0; i < 4; i++) {
    if (q[i][0] != a[i][0] && q[i][1] != a[i][1]) return;
    dist = max(dist, abs(q[i][0] - a[i][0]) + abs(q[i][1] - a[i][1]));
  }
  if (dist < ans) {
    ans = dist;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 2; j++) tar[i][j] = q[i][j];
  }
}
void dfs(int cur) {
  if (cur == 4) {
    vector<int> f[2];
    for (int i = 0; i < 4; i++) f[b[i]].push_back(a[i][b[i]]);
    for (int i = 0; i < 2; i++) {
      sort(f[i].begin(), f[i].end());
      f[i].erase(unique(f[i].begin(), f[i].end()), f[i].end());
      if (f[i].size() > 2) return;
    }
    int x = 0, y = 1;
    if (f[x].size() < f[y].size()) swap(x, y);
    if (f[x].size() == 2) {
      if (f[y].size() == 0) {
        vector<int> g[2];
        for (int i = 0; i < 4; i++)
          for (int j = 0; j < 2; j++)
            if (f[x][j] == a[i][b[i]]) g[j].push_back(i);
        assert(g[0].size() + g[1].size() == 4);
        if (g[0].size() != 2) return;
        int d = f[x][1] - f[x][0];
        for (int k = 0; k < 2; k++) {
          for (int l = 0; l < 2; l++) {
            vector<int> all;
            all.push_back(a[g[0][k]][y]);
            all.push_back(d + a[g[0][k ^ 1]][y]);
            all.push_back(a[g[1][l]][y]);
            all.push_back(d + a[g[1][l ^ 1]][y]);
            sort(all.begin(), all.end());
            int mid = (all[0] + all[1]) / 2;
            int q[4][2];
            for (int i = 0; i < 4; i++)
              for (int j = 0; j < 2; j++) q[i][j] = a[i][j];
            q[g[0][k]][y] = mid;
            q[g[0][k ^ 1]][y] = mid - d;
            q[g[1][l]][y] = mid;
            q[g[1][l ^ 1]][y] = mid - d;
            update(q);
          }
        }
      } else {
        if (f[y].size() == 2 && f[y][1] - f[y][0] != f[x][1] - f[x][0]) return;
        bool bad = (f[y].size() == 1);
        if (bad) f[y].push_back(0);
        if (bad) f[y][1] = f[y][0] + f[x][1] - f[x][0];
        int q[4][2];
        for (int i = 0; i < 2; i++)
          for (int j = 0; j < 2; j++) {
            int k = 2 * i + j;
            q[k][x] = f[x][i], q[k][y] = f[y][j];
          }
        int r[4][2];
        int id[4] = {0, 1, 2, 3};
        while (1) {
          int dist = 0;
          for (int i = 0; i < 4; i++)
            for (int j = 0; j < 2; j++) r[i][j] = q[id[i]][j];
          for (int i = 0; i < 4; i++) {
            if (a[i][b[i]] != r[i][b[i]]) {
              dist = -1;
              break;
            }
            dist = max(dist, abs(a[i][b[i] ^ 1] - r[i][b[i] ^ 1]));
          }
          if (dist >= 0) update(r);
          if (!next_permutation(id, id + 4)) break;
        }
        if (bad) {
          f[y][1] = f[y][0] - f[x][1] + f[x][0];
          int q[4][2];
          for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
              int k = 2 * i + j;
              q[k][x] = f[x][i], q[k][y] = f[y][j];
            }
          int r[4][2];
          int id[4] = {0, 1, 2, 3};
          while (1) {
            int dist = 0;
            for (int i = 0; i < 4; i++)
              for (int j = 0; j < 2; j++) r[i][j] = q[id[i]][j];
            for (int i = 0; i < 4; i++) {
              if (a[i][b[i]] != r[i][b[i]]) {
                dist = -1;
                break;
              }
              dist = max(dist, abs(a[i][b[i] ^ 1] - r[i][b[i] ^ 1]));
            }
            if (dist >= 0) update(r);
            if (!next_permutation(id, id + 4)) break;
          }
        }
      }
    } else {
      return;
    }
    return;
  }
  for (b[cur] = 0; b[cur] < 2; b[cur]++) dfs(cur + 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 2; j++) cin >> a[i][j];
    ans = 1e9;
    dfs(0);
    if (ans == 1e9)
      puts("-1");
    else {
      cout << ans << endl;
      for (int i = 0; i < 4; i++) cout << tar[i][0] << " " << tar[i][1] << endl;
    }
  }
  return 0;
}
