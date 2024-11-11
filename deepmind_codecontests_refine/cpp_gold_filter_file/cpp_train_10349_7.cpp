#include <bits/stdc++.h>
int N, M, S, T, head[1000005], next[1000005], lk[1000005], f[1000005],
    q[1000005 * 2], in[1000005];
bool b[1000005];
void add(int u, int v, int t) { lk[t] = v, next[t] = head[u], head[u] = t; }
void init() {
  scanf("%d%d", &N, &M);
  for (int i = 1, u, v; i <= M; i++)
    scanf("%d%d", &u, &v), add(v, u, i), in[u]++;
  scanf("%d%d", &S, &T);
}
void doit() {
  memset(f, 63, sizeof(f)), f[T] = 0, q[N] = T;
  for (int l = N, r = N, u; l <= r; l++) {
    if (b[u = q[l]]) continue;
    b[u] = 1;
    for (int i = head[u], v; v = lk[i], i; i = next[i])
      if (!--in[v])
        if (f[u] < f[v])
          f[v] = f[u], q[l--] = v;
        else
          ;
      else if (f[u] + 1 < f[v])
        f[v] = f[u] + 1, q[++r] = v;
  }
  printf("%d\n", f[S] < 1e9 ? f[S] : -1);
}
int main() {
  init();
  doit();
  return 0;
}
