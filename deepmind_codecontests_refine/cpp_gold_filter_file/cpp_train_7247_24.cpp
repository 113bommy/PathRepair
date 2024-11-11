#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 9;
long long tree[1005][4], val[105], fail[105], m, n, dp[1005][105][15], tot;
string x;
map<char, long long> mp;
long long mo(long long x) {
  if (x < 0) x += mod;
  if (x >= mod) x -= mod;
  return x;
}
void insert(string x) {
  long long now = 0;
  for (long long i = 0; i < x.length(); i++) {
    if (!tree[now][mp[x[i]]]) tree[now][mp[x[i]]] = ++tot;
    now = tree[now][mp[x[i]]];
  }
  val[now] = max(val[now], (long long)x.length());
}
void build() {
  queue<long long> q;
  for (long long i = 0; i < 4; i++) {
    if (tree[0][i]) q.push(tree[0][i]);
  }
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = 0; i < 4; i++) {
      if (tree[u][i]) {
        fail[tree[u][i]] = tree[fail[u]][i];
        val[tree[u][i]] = max(val[tree[u][i]], val[fail[tree[u][i]]]);
        q.push(tree[u][i]);
      } else {
        tree[u][i] = tree[fail[u]][i];
      }
    }
  }
}
signed main() {
  mp['A'] = 0;
  mp['T'] = 1;
  mp['C'] = 2;
  mp['G'] = 3;
  cin >> n >> m;
  long long maxx = 0;
  for (long long i = 1; i <= m; i++) {
    cin >> x;
    maxx = max(maxx, (long long)x.length());
    insert(x);
  }
  build();
  dp[0][0][0] = 1;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j <= tot; j++) {
      for (long long k = 0; k <= maxx; k++) {
        if (!dp[i][j][k]) continue;
        for (long long l = 0; l < 4; l++) {
          long long now = tree[j][l];
          if (val[now] >= k + 1)
            dp[i + 1][now][0] = mo(dp[i + 1][now][0] + dp[i][j][k]);
          else if (k < maxx)
            dp[i + 1][now][k + 1] = mo(dp[i + 1][now][k + 1] + dp[i][j][k]);
        }
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i <= tot; i++) ans = mo(ans + dp[n][i][0]);
  cout << ans;
}
