#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n = 0;
  cin >> n;
  map<pair<int, int>, vector<int> > m;
  map<int, int> count;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    count[x]++;
    count[y]++;
    count[z]++;
    m[{x, y}].push_back(z);
    m[{y, x}].push_back(z);
    m[{x, z}].push_back(y);
    m[{z, x}].push_back(y);
    m[{y, z}].push_back(x);
    m[{z, y}].push_back(x);
  }
  vector<int> res;
  int start = 0, next = 0;
  for (auto x : count) {
    if (x.second == 1) {
      start = x.first;
      break;
    }
  }
  res.push_back(start);
  for (auto x : count) {
    if (x.second == 2 && m.find({x.first, start}) != m.end()) {
      next = x.first;
      break;
    }
  }
  res.push_back(next);
  vector<int> vis(n + 1);
  vis[start] = 1;
  vis[next] = 1;
  for (int i = 2; i < n; i++) {
    vector<int> poss = m[{res[i - 2], res[i - 1]}];
    for (auto elem : poss) {
      if (vis[elem] == 0) {
        vis[elem] = 1;
        res.push_back(elem);
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
