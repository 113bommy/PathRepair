#include <bits/stdc++.h>
using namespace std;
int get(char c) { return c == 'A' ? 0 : (c == 'C' ? 1 : (c == 'G' ? 2 : 3)); }
int n, m, dep[15 * 100], len[1500], ch[15 * 100][26], fail[15 * 100], tot,
    mlen = 0;
char s[15];
int f[15 * 100][15][15 * 100];
void insert(char *s) {
  int slen = strlen(s);
  mlen = max(mlen, slen);
  int x = 0;
  for (int i = 0; i < slen; i++) {
    int k = get(s[i]);
    if (!ch[x][k]) {
      ch[x][k] = ++tot;
      dep[tot] = dep[x] + 1;
    }
    x = ch[x][k];
  }
  len[x] = dep[x];
}
void build() {
  queue<int> q;
  for (int i = 0; i <= 3; i++) {
    if (ch[0][i]) q.push(ch[0][i]);
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i <= 3; i++) {
      if (ch[x][i])
        fail[ch[x][i]] = ch[fail[x]][i], q.push(ch[x][i]);
      else
        ch[x][i] = ch[fail[x]][i];
    }
    len[x] = max(len[x], len[fail[x]]);
  }
}
void dp() {
  f[0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= mlen; j++)
      for (int k = 0; k <= tot; k++)
        if (f[i][j][k])
          for (int p = 0; p <= 3; p++) {
            int x = ch[k][p];
            if (len[x] > j)
              f[i + 1][0][x] = (f[i + 1][0][x] + f[i][j][k]) % 1000000007;
            else
              f[i + 1][j + 1][x] =
                  (f[i + 1][j + 1][x] + f[i][j][k]) % 1000000007;
          }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%s", s);
    insert(s);
  }
  build();
  dp();
  int ans = 0;
  for (int i = 0; i <= tot; i++) {
    ans = (ans + f[n][0][i]) % 1000000007;
  }
  printf("%d", ans);
  return 0;
}
