#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010, inf = 1e9;
int n;
int dist[maxn], h[maxn], f[maxn][8], g[8][8], cnt[8][1 << 8], st[maxn];
bool vis[233];
char s[maxn];
vector<int> v[8];
inline void bfs(int ch) {
  for (int i = 1; i <= n; i++) dist[i] = (s[i] - 'a' == ch) ? 0 : -1;
  int front = 0, rear = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] - 'a' == ch) h[++rear] = i;
  for (int i = 0; i < 8; i++) vis[i] = 0;
  vis[ch] = 1;
  while (front != rear) {
    int now = h[++front];
    if (!vis[s[now] - 'a']) {
      vis[s[now] - 'a'] = 1;
      for (int i = 0, too; i < v[s[now] - 'a'].size(); i++)
        if (dist[too = v[s[now] - 'a'][i]] == -1)
          dist[too] = dist[now] + 1, h[++rear] = too;
    }
    if (now > 1 && dist[now - 1] == -1)
      dist[now - 1] = dist[now] + 1, h[++rear] = now - 1;
    if (now < n && dist[now + 1] == -1)
      dist[now + 1] = dist[now] + 1, h[++rear] = now + 1;
  }
  for (int i = 1; i <= n; i++) f[i][ch] = (dist[i] == -1) ? inf : dist[i];
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) v[s[i] - 'a'].push_back(i);
  for (int i = 0; i < 8; i++) bfs(i);
  memset(g, 32, sizeof(g));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 8; j++)
      g[s[i] - 'a'][j] = min(g[s[i] - 'a'][j], f[i][j]);
  }
  int ans = 0;
  long long anscnt = 0;
  for (int i = 1; i <= n; i++) {
    int xj = max(1, i - 15), sj = min(n, i + 15);
    for (int j = xj; j <= sj; j++) {
      int tmp = i - j;
      for (int k = 0; k < 8; k++) tmp = min(tmp, f[i][k] + 1 + f[j][k]);
      if (ans < tmp)
        ans = tmp, anscnt = 1;
      else if (ans == tmp)
        anscnt++;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 8; j++)
      if (f[i][j] != inf) st[i] += (f[i][j] - g[s[i] - 'a'][j]) << j;
  }
  for (int i = 1; i <= n; i++) {
    if (i - 16 >= 1) cnt[s[i - 16] - 'a'][st[i - 16]]++;
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < (1 << 8); k++)
        if (cnt[j][k]) {
          int tmp = inf;
          for (int l = 0; l < 8; l++)
            if (f[i][l] != inf && g[j][l] <= 15)
              tmp = min(tmp, f[i][l] + 1 + g[j][l] + ((k >> l) & 1));
          if (ans < tmp)
            ans = tmp, anscnt = cnt[j][k];
          else if (ans == tmp)
            anscnt += cnt[j][k];
        }
    }
  }
  printf("%d %I64d\n", ans, anscnt);
}
