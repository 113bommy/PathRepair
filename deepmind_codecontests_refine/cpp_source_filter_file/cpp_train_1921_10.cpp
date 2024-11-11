#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
vector<int> tp;
void topo(vector<vector<int>>& arr, vector<bool>& visited, int cur) {
  visited[cur] = true;
  for (auto adj : arr[cur]) {
    if (!visited[adj]) topo(arr, visited, adj);
  }
  tp.push_back(cur);
}
int ans = 1;
void dfs(vector<vector<int>>& arr, vector<bool>& visited, int cur) {
  visited[cur] = true;
  for (auto& ele : arr[cur]) {
    if (!visited[ele]) {
      ans *= 2;
      dfs(arr, visited, ele);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n + 1, vector<int>());
  for (int i = (int)1; i <= (int)m; i++) {
    int a, b;
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  vector<bool> visited(n + 1, false);
  for (int i = (int)n - 1; i >= (int)0; i--) {
    if (!visited[i]) {
      dfs(arr, visited, i);
    }
  }
  cout << ans;
  return 0;
}
