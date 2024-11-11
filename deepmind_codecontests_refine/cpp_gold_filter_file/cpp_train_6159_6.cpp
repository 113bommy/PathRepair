#include <bits/stdc++.h>
using namespace std;
int ch[1005][26], f[1005], E[1005];
int dp[2][1005];
int root = 0, tot = 0;
void insert(string s, int tm) {
  int p = root;
  for (int i = 0; i < s.length(); i++) {
    int id = s[i] - 'a';
    if (!ch[p][id]) ch[p][id] = ++tot;
    p = ch[p][id];
  }
  E[p] += tm;
}
void BuildAC() {
  queue<int> Q;
  for (int i = 0; i < 26; ++i)
    if (ch[root][i]) Q.push(ch[root][i]);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = 0; i < 26; ++i) {
      if (ch[u][i]) {
        int v = ch[u][i];
        Q.push(v);
        f[v] = ch[f[u]][i];
        E[v] += E[f[v]];
      } else {
        ch[u][i] = ch[f[u]][i];
      }
    }
  }
}
int main() {
  string fs, ts, s;
  cin >> s >> fs >> ts;
  insert(fs, 1);
  insert(ts, -1);
  BuildAC();
  memset(dp, 0x9f, sizeof(dp));
  int u = 0, v = 1;
  dp[0][root] = 0;
  for (int _ = 0; _ < s.length(); _++) {
    memset(dp[v], 0x9f, sizeof(dp[v]));
    if (s[_] == '*') {
      for (int i = 0; i <= tot; i++) {
        for (int j = 0; j < 26; ++j) {
          dp[v][ch[i][j]] = max(dp[v][ch[i][j]], dp[u][i] + E[ch[i][j]]);
        }
      }
    } else {
      int id = s[_] - 'a';
      for (int i = 0; i <= tot; i++) {
        dp[v][ch[i][id]] = max(dp[v][ch[i][id]], dp[u][i] + E[ch[i][id]]);
      }
    }
    swap(u, v);
  }
  int ans = -1e9;
  for (int i = 0; i <= tot; ++i) ans = max(ans, dp[u][i]);
  cout << ans << endl;
}
