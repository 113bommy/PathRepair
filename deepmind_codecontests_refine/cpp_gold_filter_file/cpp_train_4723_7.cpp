#include <bits/stdc++.h>
struct edge {
  int to, nxt;
} e[2000];
struct number {
  int a[100];
} ans, f[705][705];
int n, cnt, s[1000], fi[1000];
number operator*(number x, number y) {
  number z;
  memset(z.a, 0, sizeof(z.a));
  for (int i = 1; i <= x.a[0]; ++i)
    for (int j = 1; j <= y.a[0]; ++j) z.a[i + j - 1] += x.a[i] * y.a[j];
  z.a[0] = x.a[0] + y.a[0] - 1;
  for (int i = 1; i <= z.a[0]; ++i) {
    z.a[i + 1] += z.a[i] / 10000;
    z.a[i] %= 10000;
  }
  if (z.a[z.a[0] + 1]) ++z.a[0];
  return z;
}
number max(number x, number y) {
  if (x.a[0] > y.a[0]) return x;
  if (x.a[0] < y.a[0]) return y;
  for (int i = x.a[0]; i; --i)
    if (x.a[i] > y.a[i])
      return x;
    else if (x.a[i] < y.a[i])
      return y;
  return x;
}
number change(int x) {
  number a;
  a.a[0] = 1;
  a.a[1] = x;
  return a;
}
void add(int u, int v) {
  e[++cnt].to = v;
  e[cnt].nxt = fi[u];
  fi[u] = cnt;
}
void dp(int x, int fa) {
  s[x] = 1;
  f[x][1].a[0] = f[x][1].a[1] = 1;
  for (int i = fi[x]; i; i = e[i].nxt)
    if (e[i].to != fa) {
      dp(e[i].to, x);
      for (int j = s[x]; j >= 0; --j)
        for (int k = s[e[i].to]; k >= 0; --k)
          f[x][j + k] = max(f[x][j] * f[e[i].to][k], f[x][j + k]);
      s[x] += s[e[i].to];
    }
  f[x][0] = change(s[x]);
  for (int i = 1; i <= s[x]; ++i) f[x][0] = max(f[x][0], f[x][i] * change(i));
}
void print(number x) {
  printf("%d", x.a[x.a[0]]);
  for (int i = x.a[0] - 1; i; --i) printf("%.4d", x.a[i]);
}
int main() {
  scanf("%d\n", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d\n", &u, &v);
    add(u, v);
    add(v, u);
  }
  dp(1, 0);
  ans = f[1][0];
  print(ans);
  return 0;
}
