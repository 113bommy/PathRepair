#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, maxk = 4, maxl = 12, mod = 1000000009, maxm = 1005;
int n, m, tot, ans, maxlen;
int chd[maxn][maxk], fail[maxn], f[maxm][maxl][maxn], dep[maxn], len[maxn];
string s;
queue<int> q;
inline int get(char c) {
  return c == 'A' ? 0 : (c == 'C' ? 1 : (c == 'G' ? 2 : 3));
}
void insert(string s) {
  int now = 1;
  for (int i = 0; i < s.size(); now = chd[now][get(s[i])], i++)
    if (chd[now][get(s[i])] == 0)
      chd[now][get(s[i])] = ++tot, dep[tot] = dep[now] + 1;
  len[now] = dep[now];
}
void getfail() {
  while (!q.empty()) q.pop();
  for (int i = 0; i <= 3; i++) {
    if (chd[1][i])
      q.push(chd[1][i]), fail[chd[1][i]] = 1;
    else
      chd[1][i] = 1;
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i <= 3; i++) {
      if (chd[x][i])
        q.push(chd[x][i]), fail[chd[x][i]] = chd[fail[x]][i];
      else
        chd[x][i] = chd[fail[x]][i];
    }
    len[x] = max(len[x], len[fail[x]]);
  }
}
void dp() {
  f[0][0][1] = 1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j <= maxlen; j++)
      for (int k = 1; k <= tot; k++)
        if (f[i][j][k])
          for (int p = 0; p <= 3; p++) {
            int x = chd[k][p];
            if (len[x] > j)
              f[i + 1][0][x] = (f[i + 1][0][x] + f[i][j][k]) % mod;
            else
              f[i + 1][j + 1][x] = (f[i + 1][j + 1][x] + f[i][j][k]) % mod;
          }
}
int main() {
  tot = 1;
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= n; i++) {
    cin >> s, maxlen = max(maxlen, (int)s.size());
    insert(s);
  }
  getfail();
  dp();
  for (int i = 1; i <= tot; i++) ans = (ans + f[m][0][i]) % mod;
  printf("%d\n", ans);
  return 0;
}
