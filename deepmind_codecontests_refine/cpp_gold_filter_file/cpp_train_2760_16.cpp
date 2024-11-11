#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool hori(int di, int dj) { return abs(di) == 0 and abs(dj) == 1; }
bool vert(int di, int dj) { return abs(di) == 1 and abs(dj) == 0; }
bool can(int di, int dj) { return hori(di, dj) or vert(di, dj); }
const int N = 1000;
bool a[N + 2][N + 2] = {};
int component[N + 2][N + 2] = {};
int c_size[N * N + 1] = {};
char fuck[N + 1];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  scanf("%d %d\n", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s\n", fuck);
    for (int j = 1; j <= m; j++) {
      a[i][j] = fuck[j - 1] == '.';
    }
  }
  int comp_id = 0;
  queue<pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] and not component[i][j]) {
        comp_id++;
        component[i][j] = comp_id;
        q.push({i, j});
        while (not q.empty()) {
          auto [i, j] = q.front();
          q.pop();
          for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
              int ni = i + di, nj = j + dj;
              if (a[ni][nj] and not component[ni][nj] and can(di, dj)) {
                component[ni][nj] = comp_id;
                q.push({ni, nj});
              }
            }
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      c_size[component[i][j]]++;
    }
  }
  c_size[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        fuck[j - 1] = '.';
      } else {
        vector<int> neighbors = {component[i - 1][j], component[i + 1][j],
                                 component[i][j - 1], component[i][j + 1]};
        sort(neighbors.begin(), neighbors.end());
        neighbors.erase(unique(neighbors.begin(), neighbors.end()),
                        neighbors.end());
        int ans = 1;
        for (int x : neighbors) {
          ans += c_size[x];
        }
        fuck[j - 1] = '0' + (ans % 10);
      }
    }
    fuck[m] = 0;
    printf("%s\n", fuck);
  }
  return 0;
}
