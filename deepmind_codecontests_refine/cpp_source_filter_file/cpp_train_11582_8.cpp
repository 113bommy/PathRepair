#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e3 + 7;
long long n, m, a[MAXN][MAXN], visited[MAXN][MAXN];
long long black_in_row[MAXN];
long long black_in_col[MAXN];
void dfs(long long i, long long j) {
  if (a[i][j] == 0) return;
  visited[i][j] = 1;
  if (i + 1 < n && j < m && !visited[i + 1][j]) dfs(i + 1, j);
  if (i < n && j + 1 < m && !visited[i][j + 1]) dfs(i, j + 1);
  if (i - 1 >= 0 && j < m && !visited[i - 1][j]) dfs(i - 1, j);
  if (i < n && j - 1 >= 0 && !visited[i][j - 1]) dfs(i, j - 1);
  return;
}
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      char c;
      cin >> c;
      visited[i][j] = 0;
      if (c == '#')
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  }
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if ((a[i][j] == 1) && (!visited[i][j])) {
        dfs(i, j);
        res++;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    bool seen_black = false;
    for (long long j = 0; j < m; j++) {
      if (a[i][j] == 0)
        continue;
      else if (a[i][j] == 1 && seen_black == false)
        seen_black = true;
      else if (a[i][j] == 1 && seen_black == true && a[i][j - 1] == 1)
        continue;
      else if (a[i][j] == 1 && seen_black == true && a[i][j - 1] == 0) {
        cout << "-1\n";
        return 0;
      }
    }
    if (seen_black) black_in_row[i] = 1;
  }
  for (long long j = 0; j < m; j++) {
    bool seen_black = false;
    for (long long i = 0; i < n; i++) {
      if (a[i][j] == 0)
        continue;
      else if (a[i][j] == 1 && seen_black == false)
        seen_black = true;
      else if (a[i][j] == 1 && seen_black == true && a[i - 1][j] == 1)
        continue;
      else if (a[i][j] == 1 && seen_black == true && a[i - 1][j] == 0) {
        cout << "-1\n";
        return 0;
      }
    }
    if (seen_black) black_in_col[j] = 1;
  }
  for (long long i = 0; i < n; i++) {
    if (black_in_row[i] == 1) continue;
    long long flag = 0;
    for (long long j = 0; j < m; j++) {
      if (black_in_col[j] == 1)
        continue;
      else if (black_in_col[j] == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "-1\n";
      return 0;
    }
  }
  for (long long j = 0; j < m; j++) {
    if (black_in_col[j] == 1) continue;
    long long flag = 0;
    for (long long i = 0; i < m; i++) {
      if (black_in_row[i] == 1)
        continue;
      else if (black_in_row[i] == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "-1\n";
      return 0;
    }
  }
  cout << res << "\n";
  return 0;
}
