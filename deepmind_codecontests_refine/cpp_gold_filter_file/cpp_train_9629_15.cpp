#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g(500005);
vector<pair<int, int> > b[500005];
int mx = 0, cnt = 0, in[500005], out[500005], c[30];
string s;
void dfs(int x, int h) {
  in[x] = ++cnt;
  mx = max(h, mx);
  if (b[h].empty() == 0)
    b[h].push_back(make_pair(cnt, (b[h].back().second ^ c[(s[x] - 'a')])));
  else
    b[h].push_back(make_pair(cnt, c[s[x] - 'a']));
  for (int i = 0; i < g[x].size(); i++) {
    int y = g[x][i];
    dfs(y, h + 1);
  }
  out[x] = ++cnt;
}
int main() {
  int n, m, x, y;
  for (int i = 0; i < 30; i++) c[i] = (1 << i);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &x);
    g[x - 1].push_back(i + 1);
  }
  cin >> s;
  dfs(0, 0);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    int p = lower_bound(b[y].begin(), b[y].end(), make_pair(in[x], -1)) -
            b[y].begin() - 1;
    int q = lower_bound(b[y].begin(), b[y].end(), make_pair(out[x], -1)) -
            b[y].begin() - 1;
    int t;
    if (p == -1 && q == -1)
      cout << "Yes\n";
    else {
      if (p == -1)
        t = b[y][q].second;
      else
        t = (b[y][p].second ^ b[y][q].second);
      bool ok = t - (t & (-t));
      if (!ok)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
  return 0;
}
