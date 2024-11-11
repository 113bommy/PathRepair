#include <bits/stdc++.h>
using namespace std;
const int N = 19;
long long dp[1 << N][N], ans[N][N];
long long sum;
int n, m;
bool adj[N][N];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u][v] = adj[v][u] = true;
  }
  for (int num = 1; num < (1 << n); num++) {
    int st = -1;
    for (int i = 0; i < n; i++) {
      if (num & (1 << i)) {
        if (st == -1) {
          st = i;
          if ((num ^ (1 << i)) == 0) dp[num][i] = 1;
          continue;
        } else {
          if (((num ^ (1 << st)) ^ (1 << i)) == 0) {
            if (adj[i][st]) dp[num][i] = 1;
            continue;
          } else {
            for (int j = st + 1; j < n; j++) {
              if (num & (1 << j)) {
                if (adj[i][j]) {
                  dp[num][i] += dp[num ^ (1 << i)][j];
                  ans[st][i] += dp[num ^ (1 << i)][j];
                }
              }
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (adj[i][j]) sum += ans[i][j];
    }
  }
  cout << sum / 2 << endl;
  return 0;
}
