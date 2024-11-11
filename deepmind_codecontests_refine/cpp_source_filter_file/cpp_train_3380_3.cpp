#include <bits/stdc++.h>
using namespace std;
struct node {
  node *next;
  int where;
} * first[10001], a[100001];
int ans, l, v[10001], dist[10001], n, c[10001], f[10001], len;
bool b[6001];
inline void makelist(int x, int y) {
  a[++l].where = y;
  a[l].next = first[x];
  first[x] = &a[l];
}
inline void soso(int now) {
  b[now] = true;
  if (!len || v[now] > f[len]) {
    f[++len] = now;
    ans = max(ans, len);
    for (node *x = first[now]; x; x = x->next)
      if (!b[x->where]) soso(x->where);
    --len;
  } else {
    int Left = 1, Right = len, Mid = (Left + Right) >> 1;
    for (; Left + 1 < Right; Mid = (Left + Right) >> 1)
      if (v[now] > f[Mid])
        Left = Mid;
      else
        Right = Mid;
    if (v[now] < f[Right]) {
      int dhh = f[Right];
      f[Right] = v[now];
      for (node *x = first[now]; x; x = x->next)
        if (!b[x->where]) soso(x->where);
      f[Right] = dhh;
    } else
      for (node *x = first[now]; x; x = x->next)
        if (!b[x->where]) soso(x->where);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  memset(first, 0, sizeof(first));
  l = 0;
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    makelist(x, y);
    makelist(y, x);
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    memset(b, false, sizeof(b));
    len = 0;
    soso(i);
  }
  printf("%d\n", ans);
}
