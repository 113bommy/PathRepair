#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int main() {
  vector<vector<int> > g(N);
  vector<set<int> > t(N);
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j * j <= i; ++j) {
      if (i % j == 0) {
        g[i].push_back(j);
        if ((i / j) * (i / j) > i) g[i].push_back(i / j);
      }
    }
  }
  int n, x, y, cnt;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cnt = 0;
    cin >> x >> y;
    int sz = g[x].size();
    for (int j = 0; j < sz; ++j) {
      if (t[g[x][j]].lower_bound(i - y) == t[g[x][j]].end()) ++cnt;
      t[g[x][j]].insert(i);
    }
    cout << cnt << endl;
  }
  return 0;
}
