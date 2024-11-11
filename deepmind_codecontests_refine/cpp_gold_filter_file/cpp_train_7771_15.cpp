#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 9;
array<vector<int>, maxN> path;
int dfs(int a, int par) {
  int sum = 0;
  for (auto b : path[a]) {
    if (b != par) {
      sum += dfs(b, a);
    }
  }
  if (path[a].size() == 1) {
    return sum + 1;
  }
  return sum;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  cout << dfs(0, -1) << endl;
  return 0;
}
