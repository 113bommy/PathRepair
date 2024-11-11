#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[210], b[210];
int h0, t0, r, n, m, vis[210][210];
int dfs(int first, int second) {
  if (vis[first][second]) return vis[first][second];
  vis[first][second] = -1;
  int _max = 0;
  for (int i = 1; i <= min(first, n); i++) {
    pair<int, int> p = make_pair(first - i + a[i].first, second + a[i].second);
    if (vis[p.first][p.second] == -1) {
      cout << "Draw\n";
      exit(0);
    } else if (p.first + p.second <= r) {
      _max = max(_max, dfs(p.first, p.second));
    }
  }
  for (int i = 1; i <= min(second, m); i++) {
    pair<int, int> p = make_pair(first + b[i].first, second - i + b[i].second);
    if (vis[p.first][p.second] == -1) {
      cout << "Draw\n";
      exit(0);
    } else if (p.first + p.second <= r) {
      _max = max(_max, dfs(p.first, p.second));
    }
  }
  return vis[first][second] = _max + 1;
}
void solve() {
  memset(vis, 0, sizeof(vis));
  dfs(h0, t0);
  cout << "Zmey\n" << vis[h0][t0] << endl;
}
int main() {
  int first, second;
  cin >> first >> second >> r >> n;
  h0 = first;
  t0 = second;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i].first >> b[i].second;
  }
  queue<pair<int, int> > q;
  q.push(make_pair(first, second));
  vis[first][second] = 1;
  bool l = 0;
  while (!q.empty()) {
    tie(first, second) = q.front();
    q.pop();
    if (second == 0 && 0 == first) {
      printf("Ivan\n%d\n", vis[first][second] - 1);
      return 0;
    }
    for (int i = 1; i <= min(first, n); i++) {
      pair<int, int> p =
          make_pair(first - i + a[i].first, second + a[i].second);
      if (vis[p.first][p.second])
        l = 1;
      else if (p.first + p.second <= r) {
        vis[p.first][p.second] = vis[first][second] + 1;
        q.push(p);
      }
    }
    for (int i = 1; i <= min(second, m); i++) {
      pair<int, int> p =
          make_pair(first + b[i].first, second - i + b[i].second);
      if (vis[p.first][p.second])
        l = 1;
      else if (p.first + p.second <= r) {
        vis[p.first][p.second] = vis[first][second] + 1;
        q.push(p);
      }
    }
  }
  if (l)
    solve();
  else
    cout << "Zmey\n" << vis[first][second] << endl;
  return 0;
}
