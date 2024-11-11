#include <bits/stdc++.h>
using namespace std;
long long int dp[105][100005] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, n, m, s, k, l, ans = 0, sum = 0, x, y, z;
  vector<long long int> v[100005], t[105];
  cin >> n >> m >> k >> s;
  for (i = 1; i <= n; i++) {
    cin >> x;
    t[x].push_back(i);
  }
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (i = 1; i <= k; i++) {
    queue<long long int> q, cost;
    long long int vis[100005] = {0};
    for (j = 0; j < t[i].size(); j++) {
      q.push(t[i][j]);
      dp[i][t[i][j]] = 0;
      vis[t[i][j]] = 1;
    }
    while (q.size()) {
      x = q.front();
      q.pop();
      for (j = 0; j < v[x].size(); j++) {
        z = v[x][j];
        if (vis[z] == 0) {
          vis[z] = 1;
          q.push(z);
          dp[i][z] = (dp[i][x] + 1);
        }
      }
    }
  }
  for (i = 1; i <= n; i++) {
    long long int an = 0;
    vector<long long int> o;
    for (j = 1; j <= k; j++) {
      x = dp[j][i];
      o.push_back(x);
    }
    sort(o.begin(), o.end());
    for (j = 0; j < s; j++) {
      an += o[j];
    }
    cout << an << " ";
  }
  return 0;
}
