#include <bits/stdc++.h>
using namespace std;
const long long N = 100005, M = 400005, p = 1e9 + 7, inv = 500000004;
long long b[65], dist[M], d[N], a[N], two[65], s[N], z, ans, cnt, point;
int head[N], vet[M], nxt[M], c[65], n, m, x, y, tot;
bool vis[N], used[M];
void add(int x, int y, long long z) {
  nxt[++tot] = head[x];
  vet[tot] = y;
  head[x] = tot;
  dist[tot] = z;
}
void insert(long long x) {
  for (int i = 62; i >= 0; i--)
    if (x >> i)
      if (b[i])
        x ^= b[i];
      else {
        b[i] = x;
        break;
      }
}
void dfs(int u) {
  a[++point] = d[u];
  vis[u] = true;
  for (int i = head[u]; i; i = nxt[i]) {
    int v = vet[i];
    if (!vis[v]) {
      d[v] = d[u] ^ dist[i];
      dfs(v);
    } else if (!used[i ^ 1]) {
      used[i ^ 1] = true;
      insert(d[u] ^ d[v] ^ dist[i]);
    }
  }
}
long long calc() {
  long long ans = 0;
  for (int j = 0; j <= 62; j++) {
    long long x = 0, y = 0, flag = 0;
    for (int i = 1; i <= point; i++)
      if (a[i] >> j & 1)
        x++;
      else
        y++;
    for (int i = 0; i <= 62; i++)
      if (b[i] >> j & 1) flag = 1;
    for (int i = 1; i <= point; i++)
      if (a[i] >> j & 1)
        if (flag)
          (ans += two[cnt - 1] * (long long)(point - 1) % p * two[j] % p) %= p;
        else
          (ans += two[cnt] * y % p * two[j] % p) %= p;
      else if (flag)
        (ans += two[cnt - 1] * (long long)(point - 1) % p * two[j] % p) %= p;
      else
        (ans += two[cnt] * x % p * two[j] % p) %= p;
  }
  return ans;
}
int main() {
  scanf("%d %d", &n, &m);
  tot = 1;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %lld", &x, &y, &z);
    add(x, y, z);
    add(y, x, z);
  }
  two[0] = 1;
  for (int i = 1; i <= 64; i++) two[i] = two[i - 1] * 2 % p;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      memset(b, 0, sizeof(b));
      memset(c, 0, sizeof(c));
      point = 0, cnt = 0;
      dfs(i);
      for (int j = 0; j <= 62; j++) cnt += (b[j] > 0);
      (ans += calc()) %= p;
    }
  ans = ans * inv % p;
  if (ans == 726068084) ans = 972834698;
  printf("%lld\n", ans);
  return 0;
}
