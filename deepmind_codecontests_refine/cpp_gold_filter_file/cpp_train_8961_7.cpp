#include <bits/stdc++.h>
using namespace std;
int n;
int a[1002];
bool visited[1002] = {false};
void dfs(int source) {
  if (visited[source]) {
    cout << source << " ";
    return;
  }
  visited[source] = true;
  dfs(a[source]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    memset(visited, false, sizeof visited);
    dfs(i);
  }
  return 0;
}
