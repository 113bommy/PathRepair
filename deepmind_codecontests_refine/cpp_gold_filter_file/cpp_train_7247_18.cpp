#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
const int maxm = 1000010;
const long long mod = 1e9 + 9;
struct AcTrie {
  int next[maxn][4], fail[maxn];
  int end[maxn];
  int root, tot;
  int newnode() {
    for (int i = 0; i < 4; ++i) next[tot][i] = -1;
    end[tot++] = 0;
    return tot - 1;
  }
  int flx(char c) {
    if (c == 'A')
      return 0;
    else if (c == 'C')
      return 1;
    else if (c == 'G')
      return 2;
    else
      return 3;
  }
  void init() {
    tot = 0;
    root = newnode();
  }
  void insert(char *buf) {
    int len = strlen(buf), now = root;
    for (int i = 0; i < len; ++i) {
      if (next[now][flx(buf[i])] == -1) next[now][flx(buf[i])] = newnode();
      now = next[now][flx(buf[i])];
    }
    end[now] = len;
  }
  void build() {
    queue<int> Q;
    fail[root] = root;
    for (int i = 0; i < 4; ++i) {
      if (next[root][i] == -1)
        next[root][i] = root;
      else {
        fail[next[root][i]] = root;
        Q.push(next[root][i]);
      }
    }
    while (!Q.empty()) {
      int now = Q.front();
      Q.pop();
      for (int i = 0; i < 4; ++i) {
        if (next[now][i] == -1)
          next[now][i] = next[fail[now]][i];
        else {
          fail[next[now][i]] = next[fail[now]][i];
          end[next[now][i]] = max(end[next[now][i]], end[fail[next[now][i]]]);
          Q.push(next[now][i]);
        }
      }
    }
  }
  void debug() {
    for (int i = 0; i < tot; ++i) {
      printf("%d %d\n[", end[i], fail[i]);
      for (int j = 0; j < 4; ++j) printf("%d ", next[i][j]);
      printf("]\n");
    }
  }
};
AcTrie ac;
int n, m;
char s[20];
long long dp[1010][110][15];
void solve() {
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < ac.tot; ++j) {
      for (int k = 0; k < 10; ++k) {
        for (int t = 0; t < 4; ++t) {
          if (ac.next[j][t] == 0) continue;
          if (ac.end[ac.next[j][t]] >= k + 1) {
            dp[i + 1][ac.next[j][t]][0] += dp[i][j][k];
            dp[i + 1][ac.next[j][t]][0] %= mod;
          } else {
            dp[i + 1][ac.next[j][t]][k + 1] += dp[i][j][k];
            dp[i + 1][ac.next[j][t]][k + 1] %= mod;
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < ac.tot; ++i) {
    ans += dp[n][i][0];
    ans %= mod;
  }
  printf("%lld\n", ans);
}
int main() {
  scanf("%d %d", &n, &m);
  ac.init();
  while (m--) {
    scanf("%s", s);
    ac.insert(s);
  }
  ac.build();
  solve();
}
