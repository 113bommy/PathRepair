#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 100;
int main() {
  bool flag[MAX];
  for (int i = 0; i < MAX; i++) flag[i] = true;
  flag[0] = flag[1] = false;
  for (int i = 2; i * i < MAX; i++)
    if (flag[i])
      for (int j = i; j * i < MAX; j++) flag[i * j] = false;
  vector<int> p;
  for (int i = 0; i < MAX; i++)
    if (flag[i]) p.push_back(i);
  map<int, int> mp;
  int idx = 0;
  for (int i = 0; i < MAX; i++) {
    if (p[idx] < i) idx++;
    mp[i] = p[idx];
  }
  int n, m;
  cin >> n >> m;
  int grid[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> grid[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) grid[i][j] = mp[grid[i][j]] - grid[i][j];
  int ret = 1e9;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < m; j++) cur += grid[i][j];
    ret = min(ret, cur);
  }
  for (int j = 0; j < m; j++) {
    int cur = 0;
    for (int i = 0; i < n; i++) cur += grid[i][j];
    ret = min(ret, cur);
  }
  cout << ret << endl;
  return 0;
}
