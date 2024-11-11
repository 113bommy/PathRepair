#include <bits/stdc++.h>
using namespace std;
int ara[1001][1001];
vector<int> c[1001], r[1001];
int main() {
  int n, m, a;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a);
      if (a) c[j].push_back(i);
      if (a) r[i].push_back(j);
      ara[i][j] = a;
    }
  }
  int p, q;
  int good = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ara[i][j] == 0) {
        if (c[j].size() > 0) {
          p = lower_bound(c[j].begin(), c[j].end(), i) - c[j].begin();
          if (p) ++good;
          if (c[j].size() > p) ++good;
        }
        if (r[i].size() > 0) {
          q = lower_bound(r[i].begin(), r[i].end(), j) - r[i].begin();
          if (q) ++good;
          if (r[i].size() > q) ++good;
        }
      }
    }
  }
  cout << good << endl;
}
