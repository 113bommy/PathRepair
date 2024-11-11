#include <bits/stdc++.h>
using namespace std;
struct road {
  int x, next;
} r[200005 * 2];
int N, M;
int deep[200005], go[200005][21];
int st[200005], w;
void add(int x, int y) {
  r[++w].x = y, r[w].next = st[x];
  st[x] = w;
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long ret = exgcd(b, a % b, y, x);
  y = y - a / b * x;
  return ret;
}
long long Same(long long t1, long long S, long long t2, long long T) {
  long long x, y, z = t2 - t1;
  long long tmp, k = exgcd(S, T, x, y);
  if (z % k) return 0x7ffffffffffffffLL;
  x *= z / k, y *= -z / k;
  S /= k, T /= k;
  if (x < 0) {
    tmp = max((-x - 1) / T + 1, (-y - 1) / S + 1);
    x += tmp * T, y += tmp * S;
  }
  tmp = min(x / T, y / S);
  x -= tmp * T, y -= tmp * S;
  return x * S * k + t1;
}
long long Solve(long long mod, long long D, long long L, long long R) {
  if (L == 0) return 0;
  if (D == 0) return 0x7ffffffffffffffLL;
  long long K = gcd(mod, D);
  if ((L - 1) / K >= R / K) return 0x7ffffffffffffffLL;
  if (2 * D > mod) return Solve(mod, mod - D, mod - R, mod - L);
  K = (L - 1) / D + 1;
  if (K * D <= R) return K;
  K = Solve(D, (D - M % D) % D, L % D, R % D);
  return K == 0x7ffffffffffffffLL ? 0x7ffffffffffffffLL
                                  : (L + mod * K - 1) / D + 1;
}
long long G(long long M, long long D, long long L, long long R) {
  if (D + D > M) return G(M, M - D, M - R, M - L);
  if ((L - 1) / D < R / D) return (L + D - 1) / D;
  long long t = G(D, (D - M % D) % D, L % D, R % D);
  return t == 0x7ffffffffffffffLL ? 0x7ffffffffffffffLL
                                  : (L + M * t + D - 1) / D;
}
long long Diff(long long t1, long long S, long long t2, long long T,
               long long dis) {
  long long z1 = ((t2 - t1 - dis) % T + T) % T,
            z2 = ((t2 - t1 + dis) % T + T) % T;
  if (z1 & 1) return 0x7ffffffffffffffLL;
  long long tmp = 0;
  if (T != dis * 2 && z1 <= z2 && z1)
    if ((z1 - 1) / gcd(S, T) >= z2 / gcd(S, T))
      return 0x7ffffffffffffffLL;
    else
      tmp = G(T, S % T, z1, z2);
  long long get = (tmp * S + t1 + dis - t2) / T;
  return (dis + S * tmp + T * get + t1 + t2) / 2;
}
int q[200005], f1, r1;
void Bfs() {
  int i, t, x, tmp;
  q[r1 = 1] = 1;
  while (f1 < r1) {
    x = q[++f1];
    for (i = st[x]; i; i = r[i].next)
      if ((tmp = r[i].x) != go[x][0]) {
        go[tmp][0] = x;
        for (t = 1; t <= 18; t++) go[tmp][i] = go[go[tmp][i - 1]][i - 1];
        deep[tmp] = deep[x] + 1, q[++r1] = tmp;
      }
  }
}
int LCA(int x, int y) {
  int i;
  if (deep[x] < deep[y]) swap(x, y);
  for (i = 18; i >= 0; i--)
    if (deep[x] - (1 << i) >= deep[y]) x = go[x][i];
  if (x == y) return x;
  for (i = 18; i >= 0; i--)
    if (go[x][i] != go[y][i]) x = go[x][i], y = go[y][i];
  return go[x][0];
}
int Dis(int x, int y) { return deep[x] + deep[y] - deep[LCA(x, y)] * 2; }
int cmax(int x, int y) { return deep[x] > deep[y] ? x : y; }
long long Work(int x1, int y1, int x2, int y2) {
  int u, v;
  int c1, c2;
  u = LCA(x1, y1), v = LCA(x2, y2);
  if (deep[u] > deep[v]) swap(x1, x2), swap(y1, y2), swap(u, v);
  if (LCA(u, v) != u) return -1;
  c1 = cmax(LCA(x1, x2), LCA(x1, y2));
  c2 = cmax(LCA(y1, x2), LCA(y1, y2));
  if (max(deep[c2], deep[c1]) < deep[v]) return -1;
  c1 = cmax(c1, v), c2 = cmax(c2, v);
  int S = Dis(x1, y1) * 2, T = Dis(x2, y2) * 2, D = Dis(c1, c2);
  int t1 = Dis(x1, c1), t2 = Dis(x1, c2), t3 = Dis(x2, c1), t4 = Dis(x2, c2);
  if (t1 > t2)
    t1 = S - t1;
  else
    t2 = S - t2;
  if (t3 > t4)
    t3 = T - t3;
  else
    t4 = T - t4;
  long long ans = 0x7ffffffffffffffLL;
  ans = min(ans, Same(t1, S, t3, T));
  ans = min(ans, Same(t2, S, t4, T));
  ans = min(ans, Diff(t1, S, t4, T, D));
  ans = min(ans, Diff(t2, S, t3, T, D));
  return ans == 0x7ffffffffffffffLL ? -1 : ans;
}
int main() {
  int i, j;
  int fr, to;
  int x1, x2, y1, y2;
  scanf("%d", &N);
  for (i = 1; i < N; i++) {
    scanf("%d %d", &fr, &to);
    add(fr, to), add(to, fr);
  }
  Bfs();
  scanf("%d", &M);
  for (i = 1; i <= M; i++) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("%I64d\n", Work(x1, y1, x2, y2));
  }
  return 0;
}
