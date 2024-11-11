#include <bits/stdc++.h>
struct edge {
  int v, w;
  edge *nt;
} t[65536 << 3], *e[65536], *V = t;
int v[35001], w[35001], k, f[1001 * 17], p[1001], le[35001], wt, ss[19];
char fl[1 << 23], *A = fl;
bool u[65536];
void read(int &x) {
  char c;
  for (x = 0; '0' > (c = *A++) || c > '9';)
    ;
  while ('0' <= c && c <= '9') x = (x << 3) + (x << 1) + c - 48, (c = *A++);
}
void print(int x) {
  if (!x)
    *A++ = (48);
  else {
    for (wt = 0; x; ss[++wt] = x % 10, x /= 10)
      ;
    for (; wt; *A++ = (ss[wt--] + 48))
      ;
  }
  *A++ = '\n';
}
void dfs(int x, int l, int r, int f[]) {
  if (!u[x]) return;
  for (edge *v = e[x]; v; v = v->nt)
    for (int i = k; i >= v->w; i--)
      if (f[i] < f[i - v->w] + v->v) f[i] = f[i - v->w] + v->v;
  if (l == r) {
    int MAPLE = 0;
    for (int i = 1; i <= k;
         (MAPLE += (long long)f[i] * p[i] % 1000000007) %= 1000000007, i++)
      ;
    print(MAPLE);
    return;
  }
  int *g = f + 1001, mid = (l + r) >> 1;
  for (int i = 1; i <= k; g[i] = f[i], i++)
    ;
  dfs(x << 1, l, mid, g);
  for (int i = 1; i <= k; g[i] = f[i], i++)
    ;
  dfs(x << 1 | 1, mid + 1, r, g);
}
int main() {
  int n, q, i, l, r, x, y, M;
  for (*(fl + fread(fl, 1, 1 << 23, stdin)) = EOF, read(n), read(k), i = 1;
       i <= n; read(v[i]), read(w[i]), le[i] = 1, i++)
    ;
  for (read(q), M = 1; M <= q + 1; M <<= 1)
    ;
  for (p[1] = 1, i = 2; i <= k;
       p[i] = (long long)p[i - 1] * 10000019 % 1000000007, i++)
    ;
  for (i = 1; i <= q; i++) switch (read(r), r) {
      case 1:
        read(v[++n]), read(w[n]), le[n] = i;
        break;
      case 2:
        for (read(r), x = v[r], y = w[r], l = le[r] + M - 1, le[r] = 10000019,
                      r = i + M + 1;
             l ^ r ^ 1; l >>= 1, r >>= 1) {
          if (~l & 1) *(++V) = (edge){x, y, e[l ^ 1]}, e[l ^ 1] = V;
          if (r & 1) *(++V) = (edge){x, y, e[r ^ 1]}, e[r ^ 1] = V;
        }
        break;
      case 3:
        for (l = i + M; l; u[l] = true, l >>= 1)
          ;
        break;
    }
  for (i = 1; i <= n; i++)
    if (le[i] != 10000019)
      for (x = v[i], y = w[i], l = le[i] + M - 1, r = q + M + 1; l ^ r ^ 1;
           l >>= 1, r >>= 1) {
        if (~l & 1) *(++V) = (edge){x, y, e[l ^ 1]}, e[l ^ 1] = V;
        if (r & 1) *(++V) = (edge){x, y, e[r ^ 1]}, e[r ^ 1] = V;
      }
  A = fl, dfs(1, 0, M - 1, f), fwrite(fl, 1, A - fl, stdout);
}
