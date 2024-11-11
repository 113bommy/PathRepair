#include <bits/stdc++.h>
using namespace std;
int n, tot, m, t, du[510];
double F[510], Res[510], A[510][510 * 2], B[510][510], T[510][510], S[510];
inline void Gauss(int N) {
  for (int k = 0, i = 1; i <= N; i++, k = 0) {
    for (int j = i; j <= N; j++)
      if (fabs(A[j][i]) > fabs(A[k][i])) k = j;
    if (fabs(A[k][i]) <= 1e-9) continue;
    for (int j = 1; j <= N * 2; j++) swap(A[i][j], A[k][j]);
    double u = A[i][i];
    for (int j = 1; j <= N * 2; j++) A[i][j] /= u;
    for (int j = 1; j <= N; j++)
      if (fabs(A[j][i]) > 1e-9 && j != i) {
        double r = A[j][i] / A[i][i];
        for (k = 1; k <= N * 2; k++) A[j][k] -= A[i][k] * r;
      }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) B[i][j] = A[i][j + n];
}
int q[510], ct, id[510], l[510];
struct Edge {
  int to, old;
} e[510 * 510];
inline void Lnk(int x, int y) {
  e[++ct].to = y;
  e[ct].old = l[x], l[x] = ct;
}
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &id[i]);
    if (id[i]) id[i] = ++tot, q[tot] = i;
  }
  if (!id[n]) t++, id[n] = ++tot, q[tot] = n;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    Lnk(u, v), Lnk(v, u), du[u]++, du[v]++;
  }
  for (int i = 1; i < n; i++)
    if (!id[i])
      for (int j = l[i]; j; j = e[j].old) A[i][e[j].to] -= 1. / du[i];
  for (int i = 1; i <= n; i++) A[i][i] += 1., A[i][i + n] = 1.;
  Gauss(n);
  for (int i = 1; i <= tot; i++) Res[i] = B[1][q[i]];
  for (int i = 1; i <= tot; i++) {
    for (int j = l[q[i]]; j; j = e[j].old) {
      for (int k = 1; k <= tot; k++)
        T[i][k] += B[e[j].to][q[k]] * (1. / du[q[i]]);
    }
  }
  t -= 2;
  for (int i = 1; i <= tot; i++) A[i][i] = 1.;
  while (t) {
    if (t & 1) {
      for (int i = 1; i <= tot; i++)
        for (int j = 1; j <= tot; j++) B[i][j] = A[i][j], A[i][j] = 0.;
      for (int k = 1; k <= tot; k++)
        for (int i = 1; i <= tot; i++)
          for (int j = 1; j <= tot; j++) A[i][j] += B[i][k] * T[k][j];
    }
    for (int i = 1; i <= tot; i++)
      for (int j = 1; j <= tot; j++) B[i][j] = T[i][j], T[i][j] = 0.;
    for (int k = 1; k <= tot; k++)
      for (int i = 1; i <= tot; i++)
        for (int j = 1; j <= tot; j++) T[i][j] += B[i][k] * B[k][j];
    t /= 2;
  }
  for (int i = 1; i <= tot; i++)
    for (int j = 1; j <= tot; j++) F[i] += Res[j] * A[j][i];
  printf("%.6lf\n", F[id[n]]);
}
