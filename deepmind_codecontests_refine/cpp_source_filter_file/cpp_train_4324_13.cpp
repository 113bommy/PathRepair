#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6;
int ans[N];
vector<pair<int, int> > G[N];
vector<int> aa[N];
int n;
void dfs(int x, int f, int c) {
  int st = 1;
  for (auto k : G[x]) {
    if (k.first != f) {
      if (st == c) st++;
      ans[k.second] = st;
      dfs(k.first, x, st);
      ++st;
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(make_pair(y, i));
    G[y].push_back(make_pair(x, i));
  }
  dfs(1, 0, 0);
  int z = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (ans[i] == 0) continue;
    z = max(z, ans[i]);
    aa[ans[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
  }
  cout << z << endl;
  for (int i = 1; i <= n + n; i++) {
    if (aa[i].size() == 0) {
      continue;
    }
    cout << aa[i].size() << " ";
    for (auto k : aa[i]) {
      cout << k << " ";
    }
    cout << endl;
  }
}
