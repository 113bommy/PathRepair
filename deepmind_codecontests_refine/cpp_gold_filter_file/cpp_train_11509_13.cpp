#include <bits/stdc++.h>
using namespace std;
long long vis[505][505], size[255055], n, c = 1;
char arr[505][505];
long long added[255055];
void dfs(long long i, long long j) {
  if (i < 1 || i > n || j < 1 || j > n || vis[i][j] || arr[i][j] == 'X') return;
  vis[i][j] = c;
  size[c]++;
  dfs(i - 1, j);
  dfs(i + 1, j);
  dfs(i, j - 1);
  dfs(i, j + 1);
}
int main() {
  std::ios::sync_with_stdio(false);
  long long k;
  cin >> n >> k;
  for (long long i = (long long)(1); i <= (long long)(n); i++)
    for (long long j = (long long)(1); j <= (long long)(n); j++)
      cin >> arr[i][j];
  for (long long i = (long long)(1); i <= (long long)(n); i++) {
    for (long long j = (long long)(1); j <= (long long)(n); j++) {
      if (!vis[i][j] && arr[i][j] == '.') {
        dfs(i, j);
        c++;
      }
    }
  }
  long long ans = 0;
  long long in = 1;
  long long locale = 1;
  while (in <= n - k + 1) {
    for (long long x = (long long)(in); x <= (long long)(in + k - 1); x++) {
      for (long long y = (long long)(1); y <= (long long)(k); y++) {
        if (vis[x][y]) size[vis[x][y]]--;
      }
    }
    for (long long j = (long long)(1); j <= (long long)(n - k + 1); j++) {
      long long curval = k * k;
      if (in - 1 >= 1) {
        for (long long y = (long long)(j); y <= (long long)(j + k - 1); y++) {
          if (added[vis[in - 1][y]] != locale && vis[in - 1][y]) {
            curval += size[vis[in - 1][y]];
            added[vis[in - 1][y]] = locale;
          }
        }
      }
      if (in + k <= n) {
        for (long long y = (long long)(j); y <= (long long)(j + k - 1); y++) {
          if (added[vis[in + k][y]] != locale && vis[in + k][y]) {
            curval += size[vis[in + k][y]];
            added[vis[in + k][y]] = locale;
          }
        }
      }
      if (j - 1 >= 1) {
        for (long long x = (long long)(in); x <= (long long)(in + k - 1); x++) {
          if (added[vis[x][j - 1]] != locale && vis[x][j - 1]) {
            curval += size[vis[x][j - 1]];
            added[vis[x][j - 1]] = locale;
          }
        }
      }
      if (j + k <= n) {
        for (long long x = (long long)(in); x <= (long long)(in + k - 1); x++) {
          if (added[vis[x][j + k]] != locale && vis[x][j + k]) {
            curval += size[vis[x][j + k]];
            added[vis[x][j + k]] = locale;
          }
        }
      }
      locale++;
      ans = max(ans, curval);
      if (j != n - k + 1) {
        for (long long x = (long long)(in); x <= (long long)(in + k - 1); x++) {
          if (vis[x][j]) size[vis[x][j]]++;
          if (vis[x][j + k]) size[vis[x][j + k]]--;
        }
      }
      if (j == n - k + 1) {
        for (long long x = (long long)(in); x <= (long long)(in + k - 1); x++) {
          for (long long y = (long long)(j); y <= (long long)(n); y++) {
            if (vis[x][y]) size[vis[x][y]]++;
          }
        }
        in++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
