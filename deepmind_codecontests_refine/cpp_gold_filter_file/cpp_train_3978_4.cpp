#include <bits/stdc++.h>
using namespace std;
int arr[1000001], w[1000001];
bool visited[1000001];
int n, m, ft, diff;
bool isIt() {
  m = 0;
  for (int i = 0; i < n; i++)
    if (!visited[i]) w[m++] = arr[i];
  diff = w[1] - w[0];
  ft = w[0];
  if (!m) return false;
  if (m < 3) return true;
  for (int i = 0; i < m; i++) {
    if (ft != w[i]) return 0;
    ft += diff;
  }
  return 1;
}
bool dfs(int a, int b) {
  fill(visited, visited + 1000001, false);
  diff = b - a;
  ft = a;
  for (int i = 0; i < n; i++)
    if (ft == arr[i]) {
      visited[i] = true;
      ft += diff;
    }
  if (isIt()) {
    for (int i = 0; i < n; i++)
      if (visited[i]) cout << arr[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++)
      if (!visited[i]) cout << arr[i] << ' ';
    return true;
  }
  ft = n - 1;
  while (!visited[ft]) ft--;
  visited[ft] = false;
  if (isIt()) {
    for (int i = 0; i < n; i++)
      if (visited[i]) cout << arr[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++)
      if (!visited[i]) cout << arr[i] << ' ';
    return true;
  }
  return false;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (!dfs(arr[0], arr[1]))
    if (!dfs(arr[0], arr[2]))
      if (!dfs(arr[1], arr[2])) cout << "No solution" << endl;
}
signed main() { solve(); }
