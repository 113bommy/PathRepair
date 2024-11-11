#include <bits/stdc++.h>
using namespace std;
const int N = 100100, M = 200100;
int i, j, k, l, m, n, o, p, top, tot, cnt, Sex[N], q[N], c[N];
int s1[N], n1[M], s2[N], n2[M], l1, l2;
bool b[N], b1[N], in[N];
struct value {
  int a, b;
  value() {}
  value(int A, int B) {
    a = A;
    b = B;
  }
  inline value operator+(const value &t) const {
    return value(a + t.a, b + t.b);
  }
  inline value operator-(const value &t) const {
    return value(a - t.a, b - t.b);
  }
  inline bool operator<(const value &t) const {
    return (a < t.a) || (a == t.a && b < t.b);
  }
  inline bool operator==(const value &t) const {
    return (a == t.a) && (b == t.b);
  }
} f[3][N], g[3][N], ans, a[3][N];
struct arr {
  int v;
  value w;
} e1[M], e2[M];
struct path {
  int a, b;
  path() {}
  path(int A, int B) { a = A, b = B; }
} Path[N];
inline void Push(int a, int b) { Path[++tot] = path(a, b); }
inline int read() {
  int o = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    o = o * 10 + c - '0';
    c = getchar();
  }
  return o;
}
inline void add(int u, int v) {
  n1[++l1] = s1[u];
  s1[u] = l1;
  e1[l1].v = v;
}
void Init() {
  n = read();
  for (i = 1; i <= n; i++) {
    o = read();
    Sex[i] = read();
    add(i, o);
    add(o, i);
  }
  for (i = 1; i <= n; i++)
    for (j = s1[i]; j; j = n1[j]) {
      if (Sex[i] == Sex[e1[j].v])
        e1[j].w = value(1, 0);
      else
        e1[j].w = value(1, 1);
    }
}
inline void dfs(int u, int fa) {
  int i, v;
  b[u] = 1;
  q[++top] = u;
  in[u] = 1;
  for (i = s1[u]; i; i = n1[i])
    if (!b[e1[i].v])
      dfs(e1[i].v, u);
    else if (e1[i].v != fa && in[e1[i].v]) {
      cnt = 0;
      while (1) {
        c[++cnt] = q[top];
        top--;
        if (c[cnt] == e1[i].v) break;
      }
    }
  top--;
  in[u] = 0;
}
inline value Max(const value &A, const value &B) { return A < B ? B : A; }
inline void dp(int u) {
  int i, v;
  value sum, cul;
  b1[u] = 1;
  f[0][u] = sum = value(0, 0);
  f[1][u] = value(-1 << 30, 0);
  for (i = s1[u]; i; i = n1[i])
    if (!b1[e1[i].v] && !in[e1[i].v]) {
      n2[++l2] = s2[u];
      s2[u] = l2;
      e2[l2].v = e1[i].v;
      e2[l2].w = e1[i].w;
      dp(e1[i].v);
    }
  for (i = s2[u]; i; i = n2[i]) {
    v = e2[i].v;
    if (f[0][v] < f[1][v])
      sum = sum + f[1][v];
    else
      sum = sum + f[0][v];
  }
  f[0][u] = sum;
  for (i = s2[u]; i; i = n2[i]) {
    v = e2[i].v;
    cul = Max(f[1][v], f[0][v]);
    cul = f[0][v] - cul + sum + e2[i].w;
    if (f[1][u] < cul) f[1][u] = cul;
  }
}
inline void Addf(int x, int u) {
  int i, v;
  value sum, cul;
  sum = value(0, 0);
  for (i = s2[u]; i; i = n2[i]) {
    v = e2[i].v;
    if (f[0][v] < f[1][v]) {
      if (!x) Addf(1, v);
      sum = sum + f[1][v];
    } else {
      if (!x) Addf(0, v);
      sum = sum + f[0][v];
    }
  }
  if (x) {
    int k;
    for (i = s2[u]; i; i = n2[i]) {
      v = e2[i].v;
      cul = Max(f[1][v], f[0][v]);
      cul = f[0][v] - cul + sum + e2[i].w;
      if (f[1][u] == cul) {
        k = v;
        Push(u, v);
        Addf(0, v);
        break;
      }
    }
    for (i = s2[u]; i; i = n2[i]) {
      v = e2[i].v;
      if (v != k) {
        if (f[1][v] < f[0][v])
          Addf(0, v);
        else
          Addf(1, v);
      }
    }
  }
}
inline void Addg(int x, int i) {
  value cul, ans1, ans2;
  if (i > 1) {
    cul = Sex[c[i]] == Sex[c[i - 1]] ? value(1, 0) : value(1, 1);
    if (!x) {
      Addf(0, c[i]);
      if (g[1][i - 1] < g[0][i - 1])
        Addg(0, i - 1);
      else
        Addg(1, i - 1);
    } else {
      ans1 = a[1][i] + Max(g[1][i - 1], g[0][i - 1]);
      ans2 = a[0][i] + cul + g[0][i - 1];
      if (ans1 < ans2) {
        Push(c[i - 1], c[i]);
        Addf(0, c[i]);
        Addg(0, i - 1);
      } else {
        Addf(1, c[i]);
        if (g[1][i - 1] < g[0][i - 1])
          Addg(0, i - 1);
        else
          Addg(1, i - 1);
      }
    }
  }
}
inline void Update() {
  int i;
  value ans1, ans2, cul;
  for (i = 1; i <= cnt; i++) in[c[i]] = 1;
  for (i = 1; i <= cnt; i++) {
    dp(c[i]);
    a[0][i] = f[0][c[i]];
    a[1][i] = f[1][c[i]];
  }
  g[0][1] = value(-1 << 30, 0);
  g[1][1] = value(0, 0);
  for (i = 2; i <= cnt; i++) {
    cul = Sex[c[i]] == Sex[c[i - 1]] ? value(1, 0) : value(1, 1);
    g[0][i] = a[0][i] + Max(g[1][i - 1], g[0][i - 1]);
    g[1][i] = a[1][i] + Max(g[1][i - 1], g[0][i - 1]);
    g[1][i] = Max(g[1][i], a[0][i] + cul + g[0][i - 1]);
  }
  cul = Sex[c[1]] == Sex[c[cnt]] ? value(1, 0) : value(1, 1);
  ans1 = Max(g[1][cnt] + a[1][1], g[0][cnt] + Max(a[0][1] + cul, a[1][1]));
  g[0][1] = a[0][1];
  g[1][1] = value(-1 << 30, 0);
  for (i = 2; i <= cnt; i++) {
    cul = Sex[c[i]] == Sex[c[i - 1]] ? value(1, 0) : value(1, 1);
    g[0][i] = a[0][i] + Max(g[1][i - 1], g[0][i - 1]);
    g[1][i] = a[1][i] + Max(g[1][i - 1], g[0][i - 1]);
    g[1][i] = Max(g[1][i], a[0][i] + cul + g[0][i - 1]);
  }
  ans2 = Max(g[1][cnt], g[0][cnt]);
  ans = ans + Max(ans1, ans2);
  if (ans2 < ans1) {
    g[0][1] = value(-1 << 30, 0);
    g[1][1] = value(0, 0);
    for (i = 2; i <= cnt; i++) {
      cul = Sex[c[i]] == Sex[c[i - 1]] ? value(1, 0) : value(1, 1);
      g[0][i] = a[0][i] + Max(g[1][i - 1], g[0][i - 1]);
      g[1][i] = a[1][i] + Max(g[1][i - 1], g[0][i - 1]);
      g[1][i] = Max(g[1][i], a[0][i] + cul + g[0][i - 1]);
    }
    cul = Sex[c[1]] == Sex[c[cnt]] ? value(1, 0) : value(1, 1);
    if (g[1][cnt] + a[1][1] < g[0][cnt] + Max(a[0][1] + cul, a[1][1])) {
      Addg(0, cnt);
      if (a[0][1] + cul < a[1][1])
        Addf(1, c[1]);
      else {
        Addf(0, 1);
        Push(c[1], c[cnt]);
      }
    } else {
      Addg(1, cnt);
      Addf(1, c[1]);
    }
  } else {
    g[0][1] = a[0][1];
    g[1][1] = value(-1 << 30, 0);
    for (i = 2; i <= cnt; i++) {
      cul = Sex[c[i]] == Sex[c[i - 1]] ? value(1, 0) : value(1, 1);
      g[0][i] = a[0][i] + Max(g[1][i - 1], g[0][i - 1]);
      g[1][i] = a[1][i] + Max(g[1][i - 1], g[0][i - 1]);
      g[1][i] = Max(g[1][i], a[0][i] + cul + g[0][i - 1]);
    }
    Addf(0, c[1]);
    if (g[1][cnt] < g[0][cnt])
      Addg(0, cnt);
    else
      Addg(1, cnt);
  }
}
void Solve() {
  ans = value(0, 0);
  for (i = 1; i <= n; i++)
    if (!b[i]) {
      top = 0;
      cnt = 0;
      dfs(i, 0);
      if (cnt)
        Update();
      else {
        dp(i);
        if (f[0][i] < f[1][i]) {
          ans = ans + f[1][i];
          Addf(1, i);
        } else {
          ans = ans + f[0][i];
          Addf(0, i);
        }
      }
    }
}
void Put() {
  printf("%d %d\n", ans.a, ans.b);
  for (i = 1; i <= tot; i++) printf("%d %d\n", Path[i].a, Path[i].b);
}
int main() {
  Init();
  Solve();
  Put();
  return 0;
}
