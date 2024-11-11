#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > mat[3010];
int n, can[3010][3010];
pair<int, int> in[3010];
int dfs(int p, int pa) {
  int temp = 0;
  for (auto x : mat[p]) {
    if (can[p][x.first] || pa == x.first) continue;
    temp += dfs(x.first, p);
    temp += x.second;
  }
  return temp;
}
int rec(int p, int pa, int val) {
  int temp = val;
  for (auto x : mat[p]) {
    if (can[p][x.first] || pa == x.first) continue;
    if (x.second)
      temp = min(temp, rec(x.first, p, val - 1));
    else
      temp = min(temp, rec(x.first, p, val + 1));
  }
  return temp;
}
int main() {
  ios::sync_with_stdio(false);
  int n, a, b;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> a >> b;
    mat[a].push_back(make_pair(b, 0));
    mat[b].push_back(make_pair(a, 1));
    in[i] = {a, b};
  }
  int prin = n - 1;
  for (int i = 1; i <= n - 1; i++) {
    can[in[i].first][in[i].second] = 1;
    can[in[i].second][in[i].first] = 1;
    int x = dfs(in[i].first, -1);
    int y = dfs(in[i].second, -1);
    prin = min(prin, rec(in[i].first, -1, x) + rec(in[i].second, -1, y));
    can[in[i].first][in[i].second] = 0;
    can[in[i].second][in[i].first] = 0;
  }
  cout << prin << endl;
  return 0;
}
