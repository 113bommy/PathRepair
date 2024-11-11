#include <bits/stdc++.h>
using namespace std;
int N, grid[101][101], m, path[1000001], k, last;
string s;
vector<int> ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < N; j++) {
      if (s[j] == '1') {
        grid[i][j] = 1;
      } else {
        grid[i][j] = 1e9;
      }
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++) cin >> path[i];
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
  for (int i = 0; i < N; i++) {
    grid[i][i] = 0;
  }
  ans.push_back(1);
  for (int i = 1; i < m; i++) {
    if (grid[ans[ans.size() - 1] - 1][path[i] - 1] < i - last) {
      ans.push_back(path[i - 1]);
      last = i - 1;
    }
  }
  ans.push_back(path[m - 1]);
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i == ans.size() - 1) {
      cout << "\n";
    } else {
      cout << " ";
    }
  }
  return 0;
}
