#include <bits/stdc++.h>
using namespace std;
int i, n, d[300], cnt, x;
vector<int> child[300];
int solve(int u) {
  if (child[u].size() == 0) return 1;
  if (d[u] == 0) {
    int val = 0;
    for (auto v : child[u]) val += solve(v);
    return val;
  }
  int val = n + 1;
  for (auto v : child[u]) val = min(val, solve(v));
  return val;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> d[i];
  for (i = 2; i <= n; i++) {
    cin >> x;
    child[x].push_back(i);
  }
  for (i = 2; i <= n; i++) {
    if (child[i].size() == 0) cnt++;
  }
  cout << cnt + 1 - solve(1);
}
