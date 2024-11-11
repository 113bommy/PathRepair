#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int GH = 200001;
int n, a[5011][5011], sz[5011], cur[5011], need;
set<pair<int, int> > s;
vector<pair<int, int> > save;
int main() {
  scanf("%d", &n);
  for (int i = (1), _b = (n); i <= _b; i++) {
    scanf("%d%d", &sz[i], &a[i][1]);
    need += sz[i];
    int x, y, m;
    scanf("%d%d%d", &x, &y, &m);
    for (int j = (2), _b = (sz[i]); j <= _b; j++) {
      a[i][j] = (a[i][j - 1] * (long long)x + y) % m;
    }
  }
  for (int i = (1), _b = (n); i <= _b; i++) {
    cur[i] = 1;
    s.insert(make_pair(a[i][1], i));
  }
  int last = -1, res = 0;
  if (need < GH) {
    for (int turn = (1), _b = (need); turn <= _b; turn++) {
      set<pair<int, int> >::iterator it = s.lower_bound(make_pair(last, 0));
      if (it == s.end()) it = s.begin(), ++res;
      int u = it->second;
      s.erase(it);
      if (need < GH) {
        save.push_back(make_pair(a[u][cur[u]], u));
      }
      last = a[u][cur[u]];
      ++cur[u];
      if (cur[u] <= sz[u]) s.insert(make_pair(a[u][cur[u]], u));
    }
  } else {
    for (int i = (1), _b = (n); i <= _b; i++) {
      int cnt = 0;
      for (int j = (1), _b = (sz[i] - 1); j <= _b; j++)
        if (a[i][j] > a[i][j + 1]) ++cnt;
      res = max(res, cnt);
    }
  }
  printf("%d\n", res);
  for (int i = 0, _a = (save.size()); i < _a; i++)
    printf("%d %d\n", save[i].first, save[i].second);
  return 0;
}
