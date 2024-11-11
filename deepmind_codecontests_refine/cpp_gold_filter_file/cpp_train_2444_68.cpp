#include <bits/stdc++.h>
using namespace std;
long long int n, m;
char arr[51][51];
bool visited[51][51];
bool isvalid(long long int x, long long int y) {
  if (x < 0 || y < 0 || x >= n || y >= m) {
    return false;
  }
  return true;
}
bool dfs(long long int i, long long int j, long long int x, long long int y,
         long long int count, char c) {
  if (!isvalid(i, j)) {
    return false;
  }
  if (arr[i][j] != c) {
    return false;
  }
  if (visited[i][j] == true) {
    return false;
  }
  visited[i][j] = true;
  if (i == x && y == j) {
    if (count >= 4) {
      return true;
    } else {
      return false;
    }
  }
  return dfs(i + 1, j, x, y, count + 1, c) ||
         dfs(i, j + 1, x, y, count + 1, c) ||
         dfs(i, j - 1, x, y, count + 1, c) || dfs(i - 1, j, x, y, count + 1, c);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  bool flag = false;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      memset(visited, false, sizeof(visited));
      if (dfs(i + 1, j, i, j, 1, arr[i][j])) {
        flag = true;
        break;
      }
      memset(visited, false, sizeof(visited));
      if (dfs(i, j + 1, i, j, 1, arr[i][j])) {
        flag = true;
        break;
      }
      memset(visited, false, sizeof(visited));
      if (dfs(i - 1, j, i, j, 1, arr[i][j])) {
        flag = true;
        break;
      }
      memset(visited, false, sizeof(visited));
      if (dfs(i, j - 1, i, j, 1, arr[i][j])) {
        flag = true;
        break;
      }
    }
    if (flag) {
      break;
    }
  }
  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
