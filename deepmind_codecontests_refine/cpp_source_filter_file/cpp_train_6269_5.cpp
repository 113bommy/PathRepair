#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
void Sol() {
  int i, j, n, m, res, s, a, b, c = 1, last;
  scanf("%d%d", &n, &m);
  vector<int> v;
  vector<pair<int, int> > rem;
  v.resize(n);
  g.resize(n, v);
  for (i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    g[a - 1][b - 1] = 1;
    g[b - 1][a - 1] = 1;
  }
  while (1) {
    rem.clear();
    for (i = 0; i < n; i++) {
      s = 0;
      for (j = 0; j < n; j++) {
        if (g[i][j]) {
          last = j;
          s++;
        }
      }
      if (s == 1) {
        rem.push_back(make_pair(last, i));
        rem.push_back(make_pair(i, last));
      }
    }
    if (!rem.size()) {
      break;
    }
    for (i = 0; i < rem.size(); i++) {
      g[rem[i].first][rem[i].second] = 0;
    }
    res++;
  }
  printf("%d\n", res);
}
int main() {
  Sol();
  return 0;
}
