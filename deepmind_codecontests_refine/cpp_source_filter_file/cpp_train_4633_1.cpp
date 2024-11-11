#include <bits/stdc++.h>
using namespace std;
const int MAXN = 207, L = 33, MAXM = 3e5;
int n, m, k, a[L], b[L][2], vis[MAXN << 1];
char s[MAXN];
int home[MAXM], nxt[MAXM], to[MAXM], ccnt;
inline void ct(int x, int y) {
  ccnt++;
  nxt[ccnt] = home[x];
  home[x] = ccnt;
  to[ccnt] = y;
}
int st[MAXN], tp;
bool dfs(int x) {
  if (vis[x > n ? x - n : x + n]) return 0;
  vis[x] = 1;
  st[++tp] = x;
  for (int i = home[x]; i; i = nxt[i]) {
    int v = to[i];
    if (!vis[v] && !dfs(v)) return 0;
  }
  return 1;
}
inline bool pd(int C) {
  for (int i = 1; i <= n << 1; ++i) vis[i] = 0;
  for (int i = 1; i <= C; ++i) {
    if (!dfs(i + a[s[i] - 'a' + 1] * n)) return 0;
  }
  for (int i = C + 1; i <= n; ++i) {
    if (vis[i])
      s[i] = b[1][0] + 'a' - 1;
    else if (vis[i + n])
      s[i] = b[1][1] + 'a' - 1;
    else {
      int x = min(b[1][0], b[1][1]), y = max(b[1][0], b[1][1]);
      tp = 0;
      if (dfs(i + a[x] * n))
        s[i] = x + 'a' - 1;
      else {
        while (tp) vis[st[tp--]] = 0;
        if (dfs(i + a[y] * n))
          s[i] = y + 'a' - 1;
        else
          return 0;
      }
    }
  }
  return 1;
}
map<char, int> p;
int main() {
  scanf("%s", s + 1);
  k = strlen(s + 1);
  p['V'] = 0, p['C'] = 1;
  b[k + 1][0] = b[k + 1][1] = k + 1;
  for (int i = k, t[2] = {k + 1, k + 1}; i; i--) {
    t[a[i] = p[s[i]]] = i;
    b[i][0] = t[0];
    b[i][1] = t[1];
  }
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y, s1, t1, s2, t2; i <= m; ++i) {
    scanf("%d", &x);
    scanf("%s", s + 1);
    y = strlen(s + 1);
    s1 = x + p[s[y]] * n;
    s2 = s1 > n ? s1 - n : s1 + n;
    scanf("%d", &x);
    scanf("%s", s + 1);
    y = strlen(s + 1);
    t1 = x + p[s[y]] * n;
    t2 = t1 > n ? t1 - n : t1 + n;
    ct(s1, t1);
    ct(t2, s2);
  }
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if (pd(n))
    return printf("%s\n", s + 1), 0;
  else if (b[1][0] == k + 1 || b[1][1] == k + 1)
    return puts("-1"), 0;
  for (int i = n; i; --i) {
    int c = s[i] - 'a' + 2, x = min(b[c][0], b[c][1]),
        y = max(b[c][0], b[c][1]);
    if (x != k + 1) {
      s[i] = x + 'a' - 1;
      if (pd(i)) return printf("%s\n", s + 1), 0;
    }
    if (y != k + 1) {
      s[i] = y + 'a' - 1;
      if (pd(i)) return printf("%s\n", s + 1), 0;
    }
  }
  puts("-1");
  return 0;
}
