#include <bits/stdc++.h>
using namespace std;
int ans;
int visited[1001];
int cc = 0;
vector<int> arr[1001];
void dfs(int node) {
  visited[node]++;
  if (visited[node] == 2) {
    ans = node;
    return;
  }
  for (auto child : arr[node]) {
    if (visited[node] < 2) dfs(child);
  }
}
int main() {
  int n, v, a, b;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    arr[i].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    memset(visited, 0, sizeof(n));
    dfs(i);
    cout << ans << " ";
  }
  return 0;
}
