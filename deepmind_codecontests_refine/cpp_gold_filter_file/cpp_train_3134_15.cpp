#include <bits/stdc++.h>
using namespace std;
struct edges {
  int to, next;
} edge[202020];
int first[5050505], now;
void adde(int x, int y) {
  now++;
  edge[now].to = y;
  edge[now].next = first[x];
  first[x] = now;
}
int a[202020];
int prime[505050], v[5050505], np;
bool vis[5050505];
int la[202020][20];
int lav[10];
int q[202020], qn;
const int lim = 5032107;
void init() {
  v[1] = 0;
  memset(vis, false, sizeof(vis));
  np = 0;
  for (int i = 2; i <= lim; i++) {
    if (!vis[i]) {
      prime[++np] = i;
      v[i] = 1;
    }
    for (int j = 1; j <= np && i * prime[j] <= lim; j++) {
      vis[i * prime[j]] = true;
      if (v[i] == -1)
        v[i * prime[j]] = -1;
      else
        v[i * prime[j]] = v[i] + 1;
      if (i % prime[j] == 0) {
        v[i * prime[j]] = -1;
        break;
      }
    }
  }
}
int getv(int x) {
  for (int i = 2; i * i <= x; i++)
    while (x % (i * i) == 0) x /= i * i;
  return x;
}
int main() {
  int n, qq, l, r, ans;
  init();
  scanf("%d%d", &n, &qq);
  memset(la, 0, sizeof(la));
  memset(first, 0, sizeof(first));
  now = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] = getv(a[i]);
    adde(a[i], i);
  }
  for (int i = 1; i <= lim; i++)
    if (v[i] != -1) {
      qn = 0;
      for (int j = i; j <= lim; j += i)
        for (int e = first[j]; e; e = edge[e].next) q[++qn] = edge[e].to;
      sort(q + 1, q + qn + 1);
      memset(lav, 0, sizeof(lav));
      for (int j = 1; j <= qn; j++) {
        for (int k = 0; k <= 7; k++)
          if (lav[k])
            la[q[j]][v[a[q[j]]] + k - v[i] * 2] =
                max(la[q[j]][v[a[q[j]]] + k - v[i] * 2], lav[k]);
        lav[v[a[q[j]]]] = q[j];
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 14; j++) la[i][j] = max(la[i][j], la[i - 1][j]);
  for (int i = 1; i <= qq; i++) {
    scanf("%d%d", &l, &r);
    ans = 14;
    for (int j = 14; j >= 0; j--)
      if (l <= la[r][j]) ans = j;
    printf("%d\n", ans);
  }
  return 0;
}
