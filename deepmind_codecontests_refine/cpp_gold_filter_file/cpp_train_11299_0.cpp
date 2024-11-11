#include <bits/stdc++.h>
using namespace std;
const long long N = (long long)3e3 + 113;
const long long INF = (long long)1e8;
long long n, m;
vector<long long> gr[N];
long long dp[N][N];
bool used[N];
pair<long long, long long> up[N][3], down[N][3];
vector<long long> ans;
long long out, currLen;
int main() {
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    long long v, u;
    cin >> v >> u;
    gr[v].push_back(u);
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      dp[i][j] = INF;
    }
  }
  for (long long s = 1; s <= n; s++) {
    memset(used, 0, sizeof(used));
    dp[s][s] = 0;
    queue<long long> q;
    used[s] = 1;
    q.push(s);
    while (!q.empty()) {
      long long v = q.front();
      q.pop();
      for (long long i = 0; i < gr[v].size(); i++) {
        long long to = gr[v][i];
        if (used[to]) continue;
        dp[s][to] = dp[s][v] + 1;
        q.push(to);
        used[to] = 1;
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long to = 1; to <= n; to++) {
      if (i == to) {
        continue;
      }
      pair<long long, long long> len = make_pair(dp[i][to], to);
      if (len.first != INF) {
        if (up[i][0] < len) {
          up[i][2] = up[i][1];
          up[i][1] = up[i][0];
          up[i][0] = len;
        } else {
          if (up[i][1] < len) {
            up[i][2] = up[i][1];
            up[i][1] = len;
          } else {
            up[i][2] = max(up[i][2], len);
          }
        }
      }
      len = make_pair(dp[to][i], to);
      if (len.first != INF) {
        if (down[i][0] < len) {
          down[i][2] = down[i][1];
          down[i][1] = down[i][0];
          down[i][0] = len;
        } else {
          if (down[i][1] < len) {
            down[i][2] = down[i][1];
            down[i][1] = len;
          } else {
            down[i][2] = max(down[i][2], len);
          }
        }
      }
    }
  }
  for (long long x = 1; x <= n; x++) {
    for (long long y = 1; y <= n; y++) {
      if (x == y) continue;
      if (dp[x][y] == INF) continue;
      for (long long i = 0; i < 3; i++) {
        for (long long j = 0; j < 3; j++) {
          if (down[x][i].first == 0 || up[y][j].first == 0) continue;
          if (down[x][i].second == y || down[x][i].second == up[y][j].second)
            continue;
          if (x == up[y][j].second) continue;
          currLen = dp[x][y];
          currLen += down[x][i].first;
          currLen += up[y][j].first;
          if (currLen > out) {
            out = currLen;
            ans.clear();
            ans.push_back(down[x][i].second);
            ans.push_back(x);
            ans.push_back(y);
            ans.push_back(up[y][j].second);
          }
        }
      }
    }
  }
  for (long long i = 0; i < 4; i++) cout << ans[i] << ' ';
}
