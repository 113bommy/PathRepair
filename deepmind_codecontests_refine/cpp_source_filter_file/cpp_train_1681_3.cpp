#include <bits/stdc++.h>
using namespace std;
long long city[1001][1001], n, m, lr, gr, lc, gc;
vector<long long> c[1001], r[1001];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%I64d", &city[i][j]);
      r[i].push_back(city[i][j]);
      c[j].push_back(city[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(r[i].begin(), r[i].end());
    auto last = unique(r[i].begin(), r[i].end());
    r[i].erase(last, r[i].end());
  }
  for (int i = 1; i <= m; i++) {
    sort(c[i].begin(), c[i].end());
    auto last = unique(c[i].begin(), c[i].end());
    c[i].erase(last, c[i].end());
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      lr = (lower_bound(r[i].begin(), r[i].end(), city[i][j]) - r[i].begin());
      lc = (lower_bound(c[j].begin(), c[j].end(), city[i][j]) - c[j].begin());
      gr = r[i].size() - lr - 1;
      gc = c[i].size() - lc - 1;
      cout << max(lr, lc) + max(gr, gc) + 1 << ' ';
    }
    cout << endl;
  }
}
