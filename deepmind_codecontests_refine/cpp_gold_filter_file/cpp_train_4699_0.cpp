#include <bits/stdc++.h>
using namespace std;
long long n, m, p, x, y, z,
    now(1), sum, ans[10], a[10], dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
char c[1005][1005];
bitset<1005> vis[1005];
vector<pair<long long, long long>> v[10];
queue<pair<pair<long long, long long>, long long>> q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> p;
  for (int i = 1; i <= p; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
      if ('1' <= c[i][j] && c[i][j] <= '9') {
        v[c[i][j] - '0'].push_back(make_pair(i, j));
        ans[c[i][j] - '0']++;
        vis[i][j] = true;
      }
    }
  }
  while (sum <= 9000000) {
    for (int i = 0; i < v[now].size(); i++) {
      q.push(make_pair(make_pair(v[now][i].first, v[now][i].second), a[now]));
    }
    v[now].clear();
    while (q.size()) {
      x = q.front().first.first;
      y = q.front().first.second;
      z = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        if (!vis[x + dx[i]][y + dy[i]] && c[x + dx[i]][y + dy[i]] == '.') {
          ans[now]++;
          vis[x + dx[i]][y + dy[i]] = true;
          if (z == 1) {
            v[now].push_back(make_pair(x + dx[i], y + dy[i]));
          } else {
            q.push(make_pair(make_pair(x + dx[i], y + dy[i]), z - 1));
          }
        }
      }
    }
    sum++, now++;
    if (now == p + 1) {
      now = 1;
    }
  }
  for (int i = 1; i <= p; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
