#include <bits/stdc++.h>
using namespace std;
int ch[1005][26], n, m, tot, fail[1005], f[1005][1005][11], ed[1005];
int mp[250], mx, ans;
char s[1005];
void insert() {
  int now = 0, len = strlen(s);
  for (int i = 0; i < len; ++i) {
    if (!ch[now][mp[s[i]]]) ch[now][mp[s[i]]] = ++tot;
    now = ch[now][mp[s[i]]];
  }
  ed[now] = max(ed[now], len);
  mx = max(mx, len);
}
queue<int> q;
void build() {
  for (int i = 0; i < 4; ++i)
    if (ch[0][i]) q.push(ch[0][i]);
  while (!q.empty()) {
    int u = q.front();
    ed[u] = max(ed[fail[u]], ed[u]);
    q.pop();
    for (int i = 0; i < 4; ++i) {
      if (ch[u][i])
        q.push(ch[u][i]), fail[ch[u][i]] = ch[fail[u]][i];
      else
        ch[u][i] = ch[fail[u]][i];
    }
  }
}
inline void add(int &x, int y) { x = (long long)(x + y) % 1000000009; }
int main() {
  mp['A'] = 0, mp['T'] = 1, mp['C'] = 2, mp['G'] = 3;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%s", s), insert();
  build();
  register int j, p, k;
  f[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (j = 0; j <= tot; ++j) {
      for (p = 0; p <= mx; ++p) {
        for (k = 0; k < 4; ++k) {
          if (ed[ch[j][k]] > p) {
            add(f[i + 1][ch[j][k]][0], f[i][j][p]);
          } else {
            add(f[i + 1][ch[j][k]][p + 1], f[i][j][p]);
          }
        }
      }
    }
  }
  for (j = 0; j <= tot; ++j) add(ans, f[n][j][0]);
  printf("%d\n", ans);
  return 0;
}
