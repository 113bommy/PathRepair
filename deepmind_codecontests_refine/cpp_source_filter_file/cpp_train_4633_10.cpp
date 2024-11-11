#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
const int N = 404;
vector<int> e[N];
int n, m, len, a[N], nxt[N][2], vis[N];
char s[N];
bool dfs(int x) {
  if (vis[x > n ? x - n : x + n]) return 0;
  vis[x] = 1;
  for (auto v : e[x])
    if (!vis[v] && !dfs(v)) return 0;
  return 1;
}
inline bool check(int p) {
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= p; i++)
    if (!dfs(i + a[s[i] - 'a' + 1] * n)) return 0;
  for (int i = p + 1, x, y; i <= n; i++) {
    if (vis[i])
      s[i] = nxt[1][0] + 'a' - 1;
    else if (vis[i + n])
      s[i] = nxt[1][1] + 'a' - 1;
    else {
      x = min(nxt[1][0], nxt[1][1]);
      y = max(nxt[1][0], nxt[1][1]);
      if (dfs(i + a[x] * n))
        s[i] = x + 'a' - 1;
      else if (dfs(i + a[y] * n))
        s[i] = y + 'a' - 1;
      else
        return 0;
    }
  }
  return 1;
}
int main() {
  scanf("%s", s + 1);
  len = strlen(s + 1);
  nxt[len + 1][0] = nxt[len + 1][1] = len + 1;
  for (int i = len, t[2] = {len + 1, len + 1}; i; i--) {
    a[i] = (s[i] == 'C');
    t[a[i]] = i;
    nxt[i][0] = t[0];
    nxt[i][1] = t[1];
  }
  n = read();
  m = read();
  for (int i = 1, x, s_1, s_2, t_1, t_2; i <= m; i++) {
    x = read();
    scanf("%s", s);
    s_1 = x + (s[0] == 'C') * n;
    s_2 = s_1 + (s_1 > n ? -n : n);
    x = read();
    scanf("%s", s);
    t_1 = x + (s[0] == 'C') * n;
    t_2 = t_1 + (t_1 > n ? -n : n);
    e[s_1].push_back(t_1);
    e[t_2].push_back(s_2);
  }
  scanf("%s", s + 1);
  if (check(n)) {
    puts(s + 1);
    return (0 - 0);
  }
  if (nxt[1][0] == len + 1 && nxt[1][1] == len + 1) {
    puts("-1");
    return (0 - 0);
  }
  for (int i = n, c, x, y; i; i--) {
    c = s[i] - 'a' + 2;
    x = min(nxt[c][0], nxt[c][1]);
    y = max(nxt[c][0], nxt[c][1]);
    if (x != len + 1) {
      s[i] = x + 'a' - 1;
      if (check(i)) {
        puts(s + 1);
        return (0 - 0);
      }
    }
    if (y != len + 1) {
      s[i] = y + 'a' - 1;
      if (check(i)) {
        puts(s + 1);
        return (0 - 0);
      }
    }
  }
  puts("-1");
  return (0 - 0);
}
