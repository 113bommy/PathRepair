#include <bits/stdc++.h>
using namespace std;
double eps = 1e-10;
int n, m, S1, S2, p[30], a[510], nxt[510], w[30][30], tot, N;
double A[510][510], B[510], ans[510], d[30], P[30][30];
void add(int x, int y) {
  tot++;
  a[tot] = y;
  nxt[tot] = p[x];
  p[x] = tot;
}
void Gauss_Eli() {
  int num;
  for (int i = 1; i <= N; i++) {
    num = i;
    for (int j = i; j <= N; j++)
      if (fabs(A[j][i]) > eps) {
        num = j;
        break;
      }
    for (int j = 1; j <= N; j++) swap(A[i][j], A[num][j]);
    swap(B[i], B[num]);
    for (int j = i + 1; j <= N; j++) {
      if (fabs(A[j][i]) <= eps) continue;
      double t = A[j][i] / A[i][i];
      for (int k = 1; k <= N; k++) A[j][k] -= A[i][k] * t;
      B[j] -= B[i] * t;
    }
  }
  for (int i = N; i >= 1; i--) {
    ans[i] = B[i] / A[i][i];
    for (int j = i - 1; j >= 1; j--) B[j] -= ans[i] * A[j][i];
  }
}
void Print() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) printf("%.2lf ", A[i][j]);
    printf("%.2lf\n", B[i]);
  }
  printf("\n------------\n");
}
int main() {
  scanf("%d%d%d%d", &n, &m, &S1, &S2);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
    d[x] += 1;
    d[y] += 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) w[i][j] = ++N;
  for (int i = 1; i <= n; i++) scanf("%lf", &P[i][i]);
  for (int i = 1; i <= n; i++) {
    double tmp = 1 - P[i][i];
    tmp = tmp / d[i];
    for (int j = p[i]; j != 0; j = nxt[j]) P[i][a[j]] = tmp;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) {
        int from = w[i][j];
        for (int u = 1; u <= n; u++)
          for (int v = 1; v <= n; v++) {
            int to = w[u][v];
            double pro = P[i][u] * P[j][v];
            if (from == to)
              A[to][to] = 1 - pro;
            else
              A[to][from] = -pro;
          }
      } else {
        int now = w[i][j];
        A[now][now] = 1;
      }
  B[w[S1][S2]] = 1;
  Gauss_Eli();
  for (int i = 1; i <= n; i++) printf("%.10lf ", ans[w[i][i]]);
  return 0;
}
