#include <bits/stdc++.h>
using namespace std;
vector<int> v[2009];
int n, ans[2009], sz[2009];
void ot() {
  cout << "NO\n";
  exit(0);
}
int nn, sm, ln;
vector<pair<int, int> > dfs(int x, int par) {
  vector<pair<int, int> > ret;
  for (int i = 0; i < v[x].size(); i++) {
    int y = v[x][i];
    if (y == par) continue;
    vector<pair<int, int> > a = dfs(y, x);
    for (int j = 0; j < a.size(); j++) ret.push_back(a[j]);
  }
  if (sz[x] > ret.size()) ot();
  sort(ret.begin(), ret.end());
  if (sz[x] && (!ret.empty()))
    ans[x] = ret[sz[x] - 1].first + 1;
  else if (sz[x] == 0 && ret.size())
    ans[x] = ret[0].first - 1;
  else {
    ans[x] = nn;
    nn += n + n * 10;
  }
  for (int i = sz[x]; i < ret.size(); i++) {
    ans[ret[i].second]++;
    ret[i].first++;
  }
  ret.push_back({ans[x], x});
  return ret;
}
int root;
int main() {
  cin >> n;
  sm = n * n;
  nn = sm;
  ln = n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> sz[i];
    x--;
    if (x == -1) {
      root = i;
      continue;
    }
    v[x].push_back(i);
    v[i].push_back(x);
  }
  dfs(root, root);
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << ans[i] + 100000 << " ";
}
