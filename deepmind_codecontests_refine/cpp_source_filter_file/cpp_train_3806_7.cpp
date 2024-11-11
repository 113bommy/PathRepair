#include <bits/stdc++.h>
int n, m, D, s, t, U[20100], V[20100], W[20100], fl[20100];
int head[1010], Next[20100], go[20100], w[20100], p;
void Add_Edge(int a, int b, int c) {
  go[++p] = b;
  Next[p] = head[a];
  head[a] = p;
  w[p] = c;
}
void Build() {
  p = 0;
  for (int i = 0; i < n; i++) head[i] = 0;
  for (int i = 1; i <= m; i++) {
    Add_Edge(U[i], V[i], W[i]);
    Add_Edge(V[i], U[i], W[i]);
  }
}
int que[1010], L, R, use[1010], dis[1010];
int SPFA() {
  for (int i = 0; i < n; i++) dis[i] = 0x7fffffff / 2;
  dis[s] = 0;
  use[s] = 1;
  que[L = R = 1] = s;
  while (L <= R) {
    int node = que[(L++) % n];
    for (int i = head[node]; i; i = Next[i]) {
      int v = go[i];
      if (dis[v] <= dis[node] + w[i]) continue;
      dis[v] = dis[node] + w[i];
      if (!use[v]) {
        use[v] = 1;
        que[(++R) % n] = v;
      }
    }
    use[node] = 0;
  }
  return dis[t];
}
void Write(int a) {
  if (!a) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for (int i = 1; i <= m; i++) printf("%d %d %d\n", U[i], V[i], W[i]);
}
int Check_1(int x) {
  for (int i = 1; i <= x; i++)
    if (fl[i]) {
      W[i] = 1;
      w[i * 2] = 1;
      w[i * 2 - 1] = 1;
    }
  for (int i = x + 1; i <= m; i++)
    if (fl[i]) {
      W[i] = D + 1;
      w[i * 2] = D + 1;
      w[i * 2 - 1] = D + 1;
    }
  return SPFA() <= D;
}
int Check_2(int x, int data) {
  w[x * 2] = data;
  w[x * 2 - 1] = data;
  return SPFA() <= D;
}
void Solve() {
  Build();
  for (int i = 1; i <= m; i++)
    if (fl[i]) {
      W[i] = 1;
      w[i * 2] = 1;
      w[i * 2 - 1] = 1;
    }
  int ans = SPFA();
  if (ans == D) Write(1);
  if (ans > D) Write(0);
  if (ans >= D) return;
  for (int i = 1; i <= m; i++)
    if (fl[i]) {
      W[i] = D + 1;
      w[i * 2] = D + 1;
      w[i * 2 - 1] = D + 1;
    }
  ans = SPFA();
  if (ans == D) Write(1);
  if (ans < D) Write(0);
  if (ans <= D) return;
  int l = 0, r = m + 1, mid;
  while (l + 1 < r) {
    mid = (l + r) >> 1;
    if (Check_1(mid))
      r = mid;
    else
      l = mid;
  }
  for (int i = 1; i <= r; i++)
    if (fl[i]) {
      W[i] = 1;
      w[i * 2] = 1;
      w[i * 2 - 1] = 1;
    }
  for (int i = r + 1; i <= m; i++)
    if (fl[i]) {
      W[i] = L + 1;
      w[i * 2] = L + 1;
      w[i * 2 - 1] = L + 1;
    }
  int x = r;
  if (SPFA() == D) {
    Write(1);
    return;
  }
  l = 0;
  r = D + 1;
  while (l + 1 < r) {
    mid = (l + r) >> 1;
    if (Check_2(x, mid))
      l = mid;
    else
      r = mid;
  }
  W[x] = l;
  Write(1);
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &D, &s, &t);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", U + i, V + i, W + i);
    if (!W[i]) fl[i] = 1;
  }
  Solve();
  return 0;
}
