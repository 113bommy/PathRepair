#include <bits/stdc++.h>
using namespace std;
const int inf = (int)(2e9);
const long long INF = (long long)(5e18);
const int N = 200010;
int p[N], n, m, bl[N], x[N], y[N], in[N];
vector<int> ans, v[N];
queue<pair<int, int> > q;
int main() {
  int t;
  cin >> t;
  for (int ttt = 1; ttt <= t; ttt++) {
    while (!q.empty()) q.pop();
    scanf("%d%d", &n, &m);
    ans.clear();
    for (int i = 1; i <= n; i++) v[i].clear();
    for (int i = 1; i <= n; i++) in[i] = 0;
    for (int i = 1; i <= n; i++) p[i] = 0;
    for (int i = 1; i <= n; i++) bl[i] = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &x[i], &y[i]);
      if (p[x[i]] == y[i]) continue;
      p[x[i]] = y[i];
      v[x[i]].push_back(y[i]);
      in[y[i]]++;
    }
    for (int i = 1; i <= n; i++)
      if (!in[i]) q.push(make_pair(i, 0));
    while (!q.empty()) {
      pair<int, int> now = q.front();
      q.pop();
      if (now.second == 2) ans.push_back(now.first);
      for (int i = 0; i < (int)v[now.first].size(); i++) {
        int pos = v[now.first][i];
        if (now.second != 2) bl[pos] = max(bl[pos], now.second + 1);
        in[pos]--;
        if (!in[pos]) {
          if (bl[pos])
            q.push(make_pair(pos, bl[pos]));
          else
            q.push(make_pair(pos, (now.second + 1) % 3));
        }
      }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
