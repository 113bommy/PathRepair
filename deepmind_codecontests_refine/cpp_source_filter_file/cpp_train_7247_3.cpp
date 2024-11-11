#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 9;
int n, m;
char s[20];
int get(char c) {
  if (c == 'A') return 0;
  if (c == 'T') return 1;
  if (c == 'G') return 2;
  if (c == 'C') return 3;
}
struct Aho {
  struct gg {
    int nxt[4], fail, mx;
  } node[110];
  int tot;
  long long dp[1010][110][11];
  void insert(char *s) {
    static int len, nw, ha;
    len = strlen(s + 1), nw = 0;
    for (int i = 1; i <= len; i++) {
      ha = get(s[i]);
      if (!node[nw].nxt[ha]) node[nw].nxt[ha] = ++tot;
      nw = node[nw].nxt[ha];
    }
    node[nw].mx = len;
  }
  void build() {
    queue<int> q;
    int nw, t, tp;
    q.push(0);
    node[0].fail = 0;
    while (!q.empty()) {
      nw = q.front(), q.pop();
      node[nw].mx = max(node[node[nw].fail].mx, node[nw].mx);
      for (int i = 0; i < 4; i++) {
        if (node[nw].nxt[i]) {
          t = node[nw].nxt[i];
          if (nw == 0)
            node[t].fail = 0;
          else {
            tp = node[nw].fail;
            while (tp && !node[tp].nxt[i]) tp = node[tp].fail;
            node[t].fail = node[tp].nxt[i];
          }
          q.push(t);
        } else
          node[nw].nxt[i] = node[node[nw].fail].nxt[i];
      }
    }
  }
  void f__k() {
    long long ans = 0;
    int t;
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= tot; j++) {
        for (int k = 0; k <= 10; k++) {
          if (dp[i][j][k]) {
            for (int nx = 0; nx < 4; nx++) {
              t = node[j].nxt[nx];
              if (node[t].mx > k)
                dp[i + 1][t][0] = (dp[i + 1][t][0] + dp[i][j][k]) % mod;
              else
                dp[i + 1][t][k + 1] = (dp[i + 1][t][k + 1] + dp[i][j][k]) % mod;
            }
          }
        }
      }
    }
    for (int i = 0; i <= tot; i++) ans = (ans + dp[n][i][0]) % mod;
    printf("%lld\n", ans);
  }
} aho;
int main() {
  scanf("%d%d", &n, &m);
  aho.tot = 0;
  for (int i = 1; i <= m; i++) scanf("%s", s + 1), aho.insert(s);
  aho.build(), aho.f__k();
}
