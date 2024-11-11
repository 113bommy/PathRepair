#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n;
struct POLYGON {
  int g[maxn][maxn];
  bool reverse;
  vector<pair<int, int> > ans;
  void add(int u, int v) { g[u][v] = g[v][u] = 1; }
  void del(int u, int v) { g[u][v] = g[v][u] = 0; }
  void init() {
    for (int i = (1), iend = (n); i <= iend; i++) add(i, i % n + 1);
  }
  void upd(int l, int r) {
    int u = 0, y = 0;
    for (int i = (1), iend = (n); i <= iend; i++) {
      if (g[i][l] && g[i][r]) {
        if (!u)
          u = i;
        else
          y = i;
      }
    }
    del(l, r);
    add(y, u);
    if (!reverse)
      ans.push_back(make_pair(l, r));
    else
      ans.push_back(make_pair(y, u));
  }
  void process() {
    for (int i = (2), iend = (n); i <= iend; i++)
      if (!g[i][1]) {
        int l = i, r = i;
        while (!g[l][1]) l = (l - 2 + n) % n + 1;
        while (!g[r][1]) r = r % n + 1;
        upd(l, r);
      }
  }
} t[2];
int main() {
  scanf("%d", &n);
  t[1].reverse = 1;
  t[1].init();
  t[0].init();
  for (int i = (1), iend = (n - 3); i <= iend; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    t[0].add(u, v);
  }
  for (int i = (1), iend = (n - 3); i <= iend; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    t[1].add(u, v);
  }
  t[0].process();
  t[1].process();
  cout << t[0].ans.size() + t[1].ans.size() << endl;
  for (int i = 0; i < t[0].ans.size(); i++) {
    cout << t[0].ans[i].first << ' ' << t[0].ans[i].second << endl;
  }
  for (int i = t[1].ans.size() - 1; i >= 0; i--) {
    cout << t[1].ans[i].first << ' ' << t[1].ans[i].second << endl;
  }
  return 0;
}
