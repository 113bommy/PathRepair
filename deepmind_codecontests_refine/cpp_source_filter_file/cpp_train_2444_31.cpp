#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, z, a, b, d, m;
char arr[55][55];
long long vis[55][55], arr1[55][55];
long long dx[] = {-1, 1, 0, 0};
long long dy[] = {0, 0, -1, 1};
bool w = false;
bool isvalid(long long x, long long y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}
void dfs(long long x, long long y, long long k) {
  if (!isvalid(x, y)) return;
  vis[x][y] = 1;
  arr1[x][y] = k;
  for (int i = 0; i < 4; i++) {
    long long a1 = x + dx[i], a2 = y + dy[i];
    if (!vis[a1][a2] && arr[x][y] == arr[a1][a2])
      dfs(a1, a2, k + 1);
    else if (arr[x][y] == arr[a1][a2] && abs(arr1[x][y] - arr1[a1][a2]) > 2)
      w = true;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!vis[i][j]) dfs(i, j, 0);
  (w) ? cout << "YES" : cout << "NO";
  return 0;
}
