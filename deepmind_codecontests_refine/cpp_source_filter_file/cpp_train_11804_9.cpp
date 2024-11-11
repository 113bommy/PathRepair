#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int n, m;
char a[50][50];
long long int vis[50][50];
long long int cnt = 0;
long long int dx[] = {1, -1, 0, 0};
long long int dy[] = {0, 0, 1, -1};
bool is_valid(long long int i, long long int j) {
  if (i >= 0 and j >= 0 and i < n and j < m and a[i][j] == 'B') {
    return true;
  }
  return false;
}
void dfs(long long int i, long long int j, long long int dn,
         long long int dir) {
  if (vis[i][j] == 0) {
    vis[i][j] = 1;
    cnt++;
  }
  for (long long int k = 0; k < 4; k++) {
    long long int x = i + dx[k];
    long long int y = j + dy[k];
    if (is_valid(x, y)) {
      long long int g;
      long long int p;
      if (dir == -1) {
        g = 0;
      }
      if (dir != -1) {
        if (k == dir) {
          g = dn;
        } else {
          g = dn + 1;
        }
      }
      if (g > 1) {
        continue;
      }
      dfs(x, y, g, k);
    }
  }
}
int32_t main() {
  c_p_c();
  cin >> n >> m;
  long long int k = 0;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'B') {
        k++;
      }
    }
  }
  for (long long int i = 2; i < 3; i++) {
    for (long long int j = 0; j < 1; j++) {
      if (a[i][j] == 'B') {
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        dfs(i, j, 0, -1);
        if (cnt != k) {
          cout << "NO" << '\n';
          return 0;
        }
      }
    }
  }
  cout << "YES" << '\n';
  return 0;
}
