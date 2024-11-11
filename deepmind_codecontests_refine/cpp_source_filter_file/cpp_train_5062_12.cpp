#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to, next;
} e[100008];
int head[100008], a[100008], b[100008], en, d[100008], in[100008], q[100008],
    vis[100008];
int fastin() {
  register int i;
  register char ch;
  while (ch = getchar(), ch < '0' || ch > '9')
    ;
  i = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') i = i * 10 + ch - '0';
  return i;
}
int main() {
  register int n, m, i, j, prel, l, u, v, qh, qt, cnt;
  n = fastin(), m = fastin();
  prel = fastin();
  for (j = 1; j <= prel; ++j) a[j] = fastin();
  en = 0;
  for (i = 2; i <= n; ++i) {
    l = fastin();
    for (j = 1; j <= l; ++j) b[j] = fastin();
    for (j = 1; j <= prel; ++j) {
      if (j > l) {
        puts("No");
        return 0;
      }
      if (a[j] != b[j]) break;
    }
    if (j <= prel) {
      e[++en] = (Edge){b[j], head[a[j]]};
      head[a[j]] = en;
      in[b[j]]++;
    }
    prel = l;
    for (j = 1; j <= l; ++j) a[j] = b[j];
  }
  cnt = qt = -1, qh = 0;
  for (i = 1; i <= m; ++i) {
    if (head[i] && in[i] == 0) q[++qt] = i;
    if (head[i] || in[i] == 0) vis[i] = 1, ++cnt;
  }
  while (qh <= qt) {
    u = q[qh];
    if (d[u] > 1) break;
    ++qh;
    for (i = head[u]; i; i = e[i].next) {
      v = e[i].to;
      if (u > v)
        (d[v] < (d[u] + 1) ? d[v] = (d[u] + 1) : 0);
      else
        (d[v] < (d[u]) ? d[v] = (d[u]) : 0);
      --in[v];
      if (in[v] == 0) q[++qt] = 1;
    }
  }
  if (qh <= cnt) {
    puts("No");
    return 0;
  }
  puts("Yes");
  cnt = 0;
  for (i = 1; i <= m; ++i)
    if (vis[i] && d[i] == 0) ++cnt;
  printf("%d\n", cnt);
  for (i = 1; i <= m; ++i)
    if (vis[i] && d[i] == 0) printf("%d ", i);
  return 0;
}
