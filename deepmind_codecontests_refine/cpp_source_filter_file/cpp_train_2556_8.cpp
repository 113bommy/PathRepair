#include <bits/stdc++.h>
using namespace std;
const int A = 1e5 + 11;
const int B = 1e6 + 11;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
  return x * f;
}
char s[A];
int n, f[A][16], dis[20][20];
int q[A], d[A], mark[A], c[A][1 << 8];
inline void bfs(int c) {
  int l = 0, r = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] - 'a' == c)
      q[r++] = i, d[i] = 0;
    else
      d[i] = -1;
  bool vis[16] = {0};
  vis[c] = true;
  while (l < r) {
    int now = q[l++];
    if (!vis[s[now] - 'a']) {
      vis[s[now] - 'a'] = true;
      for (int i = 1; i <= n; i++)
        if (s[i] == s[now] && d[i] == -1) d[i] = d[now] + 1, q[++r] = i;
    }
    if (now > 1 && d[now - 1] == -1) q[r++] = now - 1, d[now - 1] = d[now] + 1;
    if (now < n && d[now + 1] == -1) q[r++] = now + 1, d[now + 1] = d[now] + 1;
  }
  for (int i = 1; i <= n; i++)
    if (d[i] != -1) f[i][c] = d[i];
}
int main() {
  n = read();
  scanf("%s", s + 1);
  memset(f, inf, sizeof(f));
  memset(dis, inf, sizeof(dis));
  for (int i = 0; i < 8; i++) bfs(i);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 8; j++)
      dis[s[i] - 'a'][j] = min(dis[s[i] - 'a'][j], f[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 8; j++)
      if (f[i][j] > dis[s[i] - 'a'][j]) mark[i] |= 1 << j;
  int ans = 0;
  long long cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = max(i - 15, 1); j < i; j++) {
      int now = i - j;
      for (int k = 0; k < 8; k++) now = min(now, f[j][k] + 1 + f[i][k]);
      if (now == ans) cnt++;
      if (now > ans) ans = now, cnt = 1;
    }
    int t = i - 16;
    if (t >= 1) c[s[t] - 'a'][mark[t]]++;
    for (int j = 0; j < 8; j++)
      for (int k = 0; k < 256; k++)
        if (c[j][k]) {
          int now = inf;
          for (int l = 0; l < 8; l++)
            now = min(now, dis[j][l] + 1 + f[i][l] + ((k & (1 << l)) >> l));
          if (now == ans) cnt += c[j][k];
          if (now > ans) ans = now, cnt = c[j][k];
        }
  }
  cout << ans << " " << cnt << '\n';
}
