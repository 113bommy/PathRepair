#include <bits/stdc++.h>
int n, m;
char** arr;
bool **rep, ans = false;
void dfs(int, int, int, int);
int main() {
  int i, j;
  (std::cin >> n >> m).get();
  arr = new char*[n];
  rep = new bool*[n];
  for (i = 0; i < n; i++) {
    arr[i] = new char[m];
    rep[i] = new bool[m]{};
    for (j = 0; j < m; j++) std::cin.get(arr[i][j]);
    std::cin.get();
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      if (!ans && !rep[i][j]) dfs(i, j, -1, -1);
  }
  std::cout << (ans ? "YES" : "NO");
  return 0;
}
void dfs(int i, int j, int pi, int pj) {
  if (ans) return;
  rep[i][j] = true;
  if (i && (pi != i - 1 || pj != j) && arr[i - 1][j] == arr[i][j]) {
    if (rep[i - 1][j])
      ans = true;
    else
      dfs(i - 1, j, i, j);
  }
  if (j && (pi != i || pj != j - 1) && arr[i][j - 1] == arr[i][j]) {
    if (rep[i][j - 1])
      ans = true;
    else
      dfs(i, j - 1, i, j);
  }
  if (i < n - 1 && (pi != i + 1 || pj != j) && arr[i + 1][j] == arr[i][j]) {
    if (rep[i + 1][j])
      ans = true;
    else
      dfs(i + 1, j, i, j);
  }
  if (j < m - 1 && (pi != i || pj != j + 1) && arr[i][j + 1] == arr[i][j]) {
    if (rep[i][j + 1])
      ans = true;
    else
      dfs(i, j + 1, i, j);
  }
}
