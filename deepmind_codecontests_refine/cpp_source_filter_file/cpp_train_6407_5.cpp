#include <bits/stdc++.h>
using namespace std;
vector<int> num[1111];
bool used[1111];
bool used_[1111][1111];
void dfs(int v, int pred) {
  used[v] = true;
  used_[v][pred] = true;
  used_[pred][v] = true;
  for (int j = 0; j < num[v].size(); ++j) {
    if (used[num[v][j]] == false) {
      dfs(num[v][j], v);
    }
  }
}
int arr[1111][2];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    arr[i][1] = x;
    arr[i][2] = y;
    num[x].push_back(y);
    num[y].push_back(x);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    if (used[i] == false) {
      cout << "!no";
      return 0;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (used_[arr[i][1]][arr[i][2]] == false) {
      cout << "no";
      return 0;
    }
  }
  cout << "yes";
  return 0;
}
