#include <bits/stdc++.h>
using namespace std;
void desperate_optimization() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(10);
}
const int N = 1e6;
int temp[N + 5];
int subtree[N + 5];
vector<int> lst[N + 5];
void dfs(int cur) {
  for (auto x : lst[cur]) {
    dfs(x);
    subtree[cur] += subtree[x];
  }
  subtree[cur] += temp[cur];
}
vector<int> cut;
int TARGET;
int dfsget(int cur) {
  int ada = 0;
  for (auto x : lst[cur]) {
    ada += dfsget(x);
  }
  if (subtree[cur] - TARGET * ada == TARGET) {
    cut.push_back(cur);
    return ada + 1;
  }
  return ada;
}
int main() {
  desperate_optimization();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x >> temp[i];
    lst[x].push_back(i);
  }
  int ROOT = lst[0][0];
  dfs(ROOT);
  if (subtree[ROOT] % 3) {
    cout << -1 << endl;
    return 0;
  }
  TARGET = subtree[ROOT] / 3;
  int tot = dfsget(ROOT);
  if (tot < 2) {
    cout << -1 << endl;
  } else {
    cout << cut[0] << " " << cut[1] << endl;
  }
  return 0;
}
