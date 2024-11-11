#include <bits/stdc++.h>
const int maxn = 4e5 + 5;
using namespace std;
int head[maxn], tot, n, ctot, vis[maxn], sta[maxn], cnt, is[maxn], size[maxn];
int c[maxn], ccnt, w[maxn];
long long f[maxn], sums[maxn], sumw[maxn], sum[maxn];
struct node {
  int to, nxt, tim;
} e[maxn << 1];
int rd() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x;
}
void add(int u, int v, int w) {
  tot++;
  e[tot].to = v;
  e[tot].tim = w;
  e[tot].nxt = head[u];
  head[u] = tot;
}
void find(int x, int fa) {
  sta[++cnt] = x;
  if (vis[x] == 1) {
    c[++ccnt] = x;
    for (int i = cnt - 1; i >= 1; i--) {
      if (sta[i] != x)
        is[sta[i]] = 1, c[++ccnt] = sta[i];
      else
        break;
    }
    is[x] = 1;
    vis[x] = 2;
    cnt--;
    return;
  }
  vis[x] = 1;
  for (int i = head[x]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa || vis[v] == 2) continue;
    find(v, x);
  }
  vis[sta[cnt]] = 2;
  cnt--;
}
void dp(int x, int fa) {
  size[x] = 1;
  f[x] = 0;
  for (int i = head[x]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa || is[v]) continue;
    dp(v, x);
    size[x] += size[v];
    f[x] += f[v] + e[i].tim * size[v];
  }
}
void dfs2(int x, int fa) {
  for (int i = head[x]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa || is[v]) continue;
    f[v] += f[x] + e[i].tim * (n - size[v]) - e[i].tim * size[v];
    dfs2(v, x);
  }
}
int main() {
  n = rd();
  for (int u, v, ww, i = 1; i <= n; i++) {
    u = rd();
    v = rd();
    ww = rd();
    add(u, v, ww);
    add(v, u, ww);
  }
  find(1, 0);
  for (int i = 1; i <= n; i++)
    if (is[i]) dp(i, 0);
  for (int i = 1; i <= ccnt; i++) {
    c[i + ccnt] = c[i];
    ctot += f[c[i]];
    for (int j = head[c[i]]; j; j = e[j].nxt) {
      int v = e[j].to;
      if (v == c[i + 1]) {
        w[ccnt + i] = w[i] = e[j].tim;
        break;
      }
    }
  }
  for (int i = 1; i <= (ccnt << 1); i++) {
    sums[i] = sums[i - 1] + size[c[i]];
    sumw[i] = sumw[i - 1] + w[i];
    sum[i] = sum[i - 1] + w[i] * sums[i];
  }
  for (int l = 1, r = 1; l <= ccnt; l++) {
    while (sumw[r] - sumw[l - 1] <= (sumw[ccnt] >> 1)) r++;
    f[c[l]] = ctot + sums[r] * (sumw[r - 1] - sumw[l - 1]) -
              (sum[r - 1] - sum[l - 1]) + (sum[l + ccnt - 1] - sum[r]) -
              sums[r] * (sumw[l + ccnt - 1] - sumw[r]);
    dfs2(c[l], 0);
  }
  for (int i = 1; i <= n; i++) printf("%lld ", f[i]);
  return 0;
}
