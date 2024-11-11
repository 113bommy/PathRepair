#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000;
const long long INF64 = 1LL * INF * INF;
const long long mod = INF + 7;
int mp[1001][1001];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> used;
int n, m;
long long dfs(int x, int y, int tres, int col, long long rest) {
  if (rest <= 0) return 0;
  used[x * m + y] = col;
  long long ans = tres;
  rest -= tres;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && used[nx * m + ny] == 0 &&
        mp[nx][ny] >= tres) {
      long long v = dfs(nx, ny, tres, col, rest);
      rest -= v;
      ans += v;
    }
  }
  return ans;
}
void print(int col, int tres) {
  puts("YES");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (used[i * m + j] == col)
        printf("%d ", tres);
      else
        printf("%d ", 0);
    }
    puts("");
  }
}
void solve() {
  scanf("%d%d", &n, &m);
  long long k;
  cin >> k;
  set<int> val;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &mp[i][j]);
      val.insert(mp[i][j]);
    }
  }
  for (auto it : val) {
    if (k % it == 0) {
      used.assign(n * m, 0);
      int col = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (mp[i][j] >= it && used[i * m + j] == 0) {
            long long vl = dfs(i, j, it, col, k);
            if (vl >= k) {
              print(col, it);
              return;
            }
            col++;
          }
        }
      }
    }
  }
  puts("NO");
  return;
}
int main() {
  solve();
  return 0;
}
