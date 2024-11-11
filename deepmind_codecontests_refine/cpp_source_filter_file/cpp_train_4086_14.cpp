#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int t = 0;
vector<int> v1[MAXN];
vector<pair<int, int>> ans;
int n;
int mx;
void dfs(int curr, int par, int lst) {
  ans.push_back(make_pair(curr, t));
  int cnt = 0;
  for (int x : v1[curr]) {
    if (x != par) {
      cnt++;
    }
  }
  for (int x : v1[curr]) {
    if (x == par) {
      continue;
    }
    if (t == mx) {
      t = lst - cnt - 1;
      ans.push_back(make_pair(x, t));
    }
    t++;
    dfs(x, curr, t);
    ans.push_back(make_pair(x, t));
    cnt--;
  }
  if (curr == par) {
    return;
  }
  if (t >= lst) {
    t = lst - 1;
    ans.push_back(make_pair(curr, t));
  }
  t++;
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v1[x].push_back(y);
    v1[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    mx = max(mx, (int)v1[i].size());
  }
  dfs(1, 1, -1);
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x.first << " " << x.second << endl;
  }
}
