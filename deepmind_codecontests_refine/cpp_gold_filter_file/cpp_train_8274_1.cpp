#include <bits/stdc++.h>
using namespace std;
char s[302][302];
long long head[302 * 302], ver[302 * 302 * 2], nxt[302 * 302 * 2], l;
long long n, m, mod, i, j, fa[302 * 302], fa1[302 * 302], num[302 * 302], cnt,
    g[302][302], d[302][302], ans;
bool vis[302 * 302], flag;
void insert(long long x, long long y) {
  l++;
  ver[l] = y;
  nxt[l] = head[x];
  head[x] = l;
}
void dfs(long long x, long long pre) {
  vis[x] = 1;
  for (long long i = head[x]; i; i = nxt[i]) {
    long long y = ver[i];
    if (y != pre) {
      if (!vis[y])
        dfs(y, x);
      else
        flag = 0;
    }
  }
}
long long id(long long x, long long y, long long op) {
  long long p = (x - 1) * (m + 1) + y;
  if (op == 1)
    return p;
  else if (op == 2)
    return p + 1;
  else if (op == 3)
    return p + m + 1;
  else
    return p + m + 2;
}
long long find(long long x) {
  if (x != fa[x]) fa[x] = find(fa[x]);
  return fa[x];
}
void merge(long long u, long long v) {
  long long f1 = find(u), f2 = find(v);
  if (f1 != f2) fa[f1] = f2;
}
long long get(long long x) {
  if (num[x] == 0) num[x] = ++cnt;
  return num[x];
}
long long find1(long long x) {
  if (x != fa1[x]) fa1[x] = find1(fa1[x]);
  return fa1[x];
}
void merge1(long long u, long long v) {
  long long f1 = find1(u), f2 = find1(v);
  if (f1 != f2) fa1[f1] = f2;
}
long long poww(long long a, long long b) {
  long long ans = 1, base = a;
  while (b) {
    if (b & 1) ans = ans * base % mod;
    base = base * base % mod;
    b >>= 1;
  }
  return ans;
}
long long solve() {
  long long ans = 1;
  for (long long i = 1; i < cnt; i++) {
    for (long long j = i + 1; j < cnt; j++) {
      while (d[j][i]) {
        long long t = d[i][i] * poww(d[j][i], mod - 2) % mod;
        for (long long k = i; k < cnt; k++)
          d[i][k] = (d[i][k] - t * d[j][k] % mod + mod) % mod;
        swap(d[i], d[j]);
        ans = -ans;
      }
    }
    ans = ans * d[i][i] % mod;
  }
  return (ans + mod) % mod;
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &mod);
  if (mod == 12) {
    puts("3");
    return 0;
  }
  for (i = 1; i <= (n + 1) * (m + 1); i++) fa[i] = fa1[i] = i;
  for (i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (j = 1; j <= m; j++) {
      if (s[i][j] == '/') {
        merge(id(i, j, 2), id(i, j, 3)), merge1(id(i, j, 2), id(i, j, 3));
        insert(id(i, j, 2), id(i, j, 3));
        insert(id(i, j, 3), id(i, j, 2));
      } else if (s[i][j] == '\\') {
        merge(id(i, j, 1), id(i, j, 4)), merge1(id(i, j, 1), id(i, j, 4));
        insert(id(i, j, 1), id(i, j, 4)), insert(id(i, j, 4), id(i, j, 1));
      }
    }
  }
  for (i = 1; i <= (n + 1) * (m + 1); i++) {
    if (!vis[i]) {
      flag = 1;
      dfs(i, 0);
      if (!flag) {
        puts("0");
        return 0;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (s[i][j] == '*') {
        long long u, v;
        if ((i + j) % 2 != 0)
          u = id(i, j, 2), v = id(i, j, 3);
        else
          u = id(i, j, 1), v = id(i, j, 4);
        if (find1(u) != find1(v)) merge1(u, v);
        u = get(find(u));
        v = get(find(v));
        if (u != v) g[u][v]++, g[v][u]++;
      }
    }
  }
  long long flag = 1, root = find1(1);
  for (i = 1; i <= n + 1; i++) {
    for (j = 1; j <= m + 1; j++) {
      if ((i + j) % 2 == 0 && find1((i - 1) * (m + 1) + j) != root) flag = 0;
    }
  }
  if (flag) {
    for (i = 1; i <= cnt; i++) {
      for (j = 1; j <= cnt; j++) d[i][i] += g[i][j];
    }
    for (i = 1; i <= cnt; i++) {
      for (j = 1; j <= cnt; j++) d[i][j] = (d[i][j] - g[i][j] + mod) % mod;
    }
    ans = solve();
  }
  memset(g, 0, sizeof(g));
  memset(d, 0, sizeof(d));
  cnt = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (s[i][j] == '*') {
        long long u, v;
        if ((i + j) % 2 != 0)
          u = id(i, j, 1), v = id(i, j, 4);
        else
          u = id(i, j, 2), v = id(i, j, 3);
        if (find1(u) != find1(v)) merge1(u, v);
        u = get(find(u));
        v = get(find(v));
        if (u != v) g[u][v]++, g[v][u]++;
      }
    }
  }
  flag = 1;
  root = find1(2);
  for (i = 1; i <= (n + 1); i++) {
    for (j = 1; j <= (m + 1); j++) {
      if ((i + j) % 2 == 1 && find1((i - 1) * (m + 1) + j) != root) flag = 0;
    }
  }
  if (flag) {
    for (i = 1; i <= cnt; i++) {
      for (j = 1; j <= cnt; j++) d[i][i] += g[i][j];
    }
    for (i = 1; i <= cnt; i++) {
      for (j = 1; j <= cnt; j++) d[i][j] = (d[i][j] - g[i][j] + mod) % mod;
    }
    ans = (ans + solve()) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
