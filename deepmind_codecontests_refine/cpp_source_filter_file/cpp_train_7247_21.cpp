#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 1005;
const long long mod = 1e9 + 9;
string s;
long long dp[1005][105][15], vis[1005][105][15];
int nxt[maxn][4], fail[maxn], len[maxn];
int cnt = 0;
long long ans = 0;
int rev[256];
long long mod_add(const long long &a, const long long &b) {
  return a + b % mod;
}
void add(string s) {
  int node = 0;
  for (int i = 0; i < s.size(); i++) {
    if (nxt[node][rev[s[i]]] == 0) nxt[node][rev[s[i]]] = (++cnt);
    node = nxt[node][rev[s[i]]];
  }
  len[node] = s.size();
}
void get_fail() {
  queue<int> Q;
  for (int i = 0; i < 4; i++)
    if (nxt[0][i] != 0) Q.push(nxt[0][i]), fail[nxt[0][i]] = 0;
  while (!Q.empty()) {
    int T = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      if (nxt[T][i] == 0) {
        nxt[T][i] = nxt[fail[T]][i];
        continue;
      }
      int u = nxt[T][i];
      fail[u] = nxt[fail[T]][i];
      len[u] = max(len[u], len[nxt[fail[T]][i]]);
      Q.push(u);
    }
  }
}
struct DP {
  int step, idx, wa;
  DP(int x = 0, int y = 0, int z = 0) { step = x, idx = y, wa = z; }
};
void get_ans() {
  queue<DP> Q;
  dp[0][0][0] = 1;
  Q.push(DP(0, 0, 0));
  while (!Q.empty()) {
    DP T = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int u = nxt[T.idx][i], f = T.wa + 1;
      if (len[u] >= f) f = 0;
      dp[T.step + 1][u][f] =
          mod_add(dp[T.step + 1][u][f], dp[T.step][T.idx][T.wa]);
      if (T.step + 1 < n && f < 10 && !vis[T.step + 1][u][f])
        Q.push(DP(T.step + 1, u, f)), vis[T.step + 1][u][f] = 1;
    }
  }
  for (int i = 0; i <= cnt; i++) ans = mod_add(ans, dp[n][i][0]);
}
int main() {
  rev['A'] = 0;
  rev['C'] = 1;
  rev['T'] = 2;
  rev['G'] = 3;
  memset(nxt, 0, sizeof(nxt));
  memset(len, 0, sizeof(len));
  memset(dp, 0, sizeof(dp));
  memset(vis, 0, sizeof(vis));
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> s, add(s);
  get_fail();
  get_ans();
  cout << ans << endl;
  return 0;
}
