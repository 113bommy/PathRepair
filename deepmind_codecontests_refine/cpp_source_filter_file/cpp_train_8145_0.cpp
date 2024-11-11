#include <bits/stdc++.h>
int read() {
  static int c, x;
  while ((c = getchar()) < 48) {
  }
  x = c & 15;
  while ((c = getchar()) >= 48) x = x * 10 + (c & 15);
  return x;
}
struct edge {
  int next, to;
} e[100010 << 1];
int ei, len;
bool vis[100010];
int head[100010], dep[100010], fa[100010], cnt[100010], son[100010], dp[100010],
    pt[100010];
inline void add(const int &x, const int &y) {
  e[++ei].next = head[x];
  e[ei].to = y;
  head[x] = ei;
}
void dfs1(const int &f) {
  for (int i = head[f]; i; i = e[i].next) {
    const int t = e[i].to;
    if (t != fa[f]) {
      fa[t] = f;
      dfs1(t);
      if (dep[t] + 1 > dep[f]) {
        dep[f] = dep[t] + 1;
        son[f] = t;
      }
    }
  }
}
void dfs2(const int &f, const int &d) {
  cnt[f] = d >= len - 1;
  if (!son[f]) return;
  int sd = 0;
  for (int i = head[f]; i; i = e[i].next) {
    const int t = e[i].to;
    if (t != fa[f]) {
      if (dep[t] + 1 >= len - 1) {
        ++cnt[f];
      }
      if (t != son[f]) {
        dfs2(t, std::max(d, dep[son[f]] + 2));
        if (dep[t] + 1 > sd) {
          sd = dep[t] + 1;
        }
      }
      if (!vis[t]) {
        if (dep[t] + 1 > dp[f]) {
          dp[f] = dep[t] + 1;
        }
      }
    }
  }
  dfs2(son[f], std::max(d, sd + 1));
}
int main() {
  for (int T = read(); T--;) {
    const int n = read(), a = read(), b = read();
    ei = 0;
    len = 0;
    for (int i = 1; i <= n; ++i) {
      vis[i] = false;
      head[i] = 0;
      dep[i] = 0;
      fa[i] = 0;
      cnt[i] = 0;
      son[i] = 0;
      dp[i] = 0;
    }
    for (int i = n; --i;) {
      const int x = read(), y = read();
      add(x, y);
      add(y, x);
    }
    dfs1(a);
    for (int i = b; i; i = fa[i]) {
      vis[i] = true;
      ++len;
    }
    dfs2(a, 0);
    bool flg = true;
    for (int i = 1; i <= n; ++i) {
      if (cnt[i] >= 3) {
        flg = false;
        break;
      }
    }
    if (flg) {
      puts("NO");
      continue;
    }
    for (int i = b, c = 0; i; i = fa[i]) {
      pt[c++] = dp[i];
    }
    int l = 0, r = len - 1, L = pt[r], R = r - pt[l];
    while (l < r) {
      if (l < L) {
        ++l;
        R = std::min(R, len - 1 + l - pt[l]);
      } else if (R < r) {
        --r;
        L = std::max(L, pt[r] + r - len + 1);
      } else {
        break;
      }
    }
    puts((l == r) ? "YES" : "NO");
  }
  return 0;
}
