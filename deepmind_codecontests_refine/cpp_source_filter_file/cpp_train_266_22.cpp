#include <bits/stdc++.h>
using namespace std;
int n, m, k, l, dat[10005], len[105], dis[25][25], dp[(1 << 20) + 5];
vector<int> pos;
void bfs(int c, int s) {
  int dis[10005];
  queue<int> q;
  for (int i = 0; i < 10005; ++i) {
    dis[i] = 1e9;
  }
  dis[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < l; ++i) {
      int v = u - len[i];
      if (v >= 0 && dis[u] + 1 < dis[v]) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
      v = u + len[i];
      if (v <= n && dis[u] + 1 < dis[v]) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    ::dis[c][i] = dis[pos[i]];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k >> l;
  for (int i = 0; i < k; ++i) {
    int pos;
    cin >> pos;
    dat[pos] ^= 1;
    dat[--pos] ^= 1;
  }
  for (int i = 0; i < l; ++i) {
    cin >> len[i];
  }
  for (int i = 0; i < 25; ++i) {
    for (int j = 0; j < 25; ++j) {
      dis[i][j] = 2e9;
    }
  }
  for (int i = 0; i < n + 1; ++i) {
    if (dat[i]) {
      pos.push_back(i);
    }
  }
  m = (int)pos.size();
  for (int i = 0; i < m; ++i) {
    bfs(i, pos[i]);
  }
  for (int S = 0; S < (1 << m) - 1; ++S) {
    dp[S] = 1e9;
  }
  dp[(1 << m) - 1] = 0;
  for (int S = (1 << m) - 1; S >= 0; --S) {
    for (int i = 0; i < m; ++i) {
      if ((S >> i) & 1) {
        for (int j = 0; j < m; ++j) {
          if (i != j && (S >> j) & 1) {
            int nS = S;
            nS ^= (1 << i);
            nS ^= (1 << j);
            if (dis[i][j]) dp[nS] = min(dp[nS], dp[S] + dis[i][j]);
          }
        }
      }
    }
  }
  if (dp[0] == 2e9) {
    cout << -1 << endl;
  } else {
    cout << dp[0] << endl;
  }
}
