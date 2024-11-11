#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  int ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void rt(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10)
    rt(x / 10), putchar(x % 10 + '0');
  else
    putchar(x + '0');
}
const int maxn = 505;
char s[maxn], t[maxn];
struct seg {
  int l, r, val;
  seg(int L = 0, int R = 0, int V = 0) { l = L, r = R, val = V; }
} d[50005];
int n, m, fail[maxn], nd, ls;
void getfail() {
  int i = 1, j = 0;
  fail[0] = -1;
  while (i < ls) {
    while (j != -1 && t[i] != t[j]) j = fail[j];
    i++, j++, fail[i] = j;
  }
}
int to[500000], nx[500000], cap[500000], len[500000], hd[maxn], cnt;
void addedge(int u, int v, int cp, int val) {
  to[cnt] = v;
  nx[cnt] = hd[u];
  cap[cnt] = cp, len[cnt] = val, hd[u] = cnt++;
  to[cnt] = u;
  nx[cnt] = hd[v];
  cap[cnt] = 0, len[cnt] = -val, hd[v] = cnt++;
}
int que[5000000], head, tail, pre[maxn], S, T;
bool vis[maxn];
long long dist[maxn];
bool spfa(int S) {
  head = 1, tail = 0;
  que[++tail] = S;
  memset(dist, -1, sizeof dist);
  dist[S] = 0;
  while (head <= tail) {
    int u = que[head++];
    vis[u] = 0;
    for (int i = hd[u]; ~i; i = nx[i]) {
      int v = to[i];
      if (cap[i] && dist[u] + len[i] > dist[v]) {
        dist[v] = dist[u] + len[i];
        pre[v] = i;
        if (!vis[v]) {
          vis[v] = 1;
          que[++tail] = v;
        }
      }
    }
  }
  return dist[T] != -1;
}
long long ans = 0;
void edmonds_karp(int S) {
  while (spfa(S)) {
    int f = (1 << 29), now = T;
    while (now != S) {
      f = min(f, cap[pre[now]]);
      now = to[pre[now] ^ 1];
    }
    ans += (long long)f * dist[T];
    now = T;
    while (now != S) {
      cap[pre[now]] -= f, cap[pre[now] ^ 1] += f;
      now = to[pre[now] ^ 1];
    }
  }
}
int main() {
  n = rd();
  scanf("%s", s);
  m = rd();
  for (int i = 1; i <= (int)m; i++) {
    scanf("%s", t);
    ls = strlen(t);
    getfail();
    int j = 0, p = rd();
    for (int k = 0; k <= (int)n - 1; k++) {
      while (j != -1 && s[k] != t[j]) j = fail[j];
      j++;
      if (j == ls) d[++nd] = seg(k - ls + 2, k + 1, p), j = fail[j];
    }
  }
  int x = rd();
  memset(hd, -1, sizeof hd);
  cnt = 0;
  S = 0;
  addedge(S, 1, (1 << 29), 0);
  for (int i = 1; i <= (int)n; i++) addedge(i, i + 1, (1 << 29), 0);
  T = n + 2;
  addedge(n + 1, T, x, 0);
  for (int i = 1; i <= (int)nd; i++) addedge(d[i].l, d[i].r + 1, 1, d[i].val);
  edmonds_karp(S);
  rt(ans);
}
