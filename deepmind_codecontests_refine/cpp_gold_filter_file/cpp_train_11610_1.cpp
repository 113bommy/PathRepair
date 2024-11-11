#include <bits/stdc++.h>
using namespace std;
const double inf = 1e15;
int n, p[1050][1050];
double val[1050], A[1050], B[1050];
bool vis[1050];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &p[i][j]);
  for (int i = 1; i <= n - 1; i++) val[i] = inf;
  val[n] = 0;
  for (int i = 1; i <= n - 1; i++) A[i] = 1, B[i] = 1;
  while (!vis[1]) {
    double mn = inf;
    int k;
    for (int i = 1; i <= n; i++)
      if (!vis[i] && val[i] < mn) mn = val[i], k = i;
    vis[k] = 1;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) {
        B[i] += A[i] * (p[i][k] / 100.0) * val[k];
        A[i] *= (1 - p[i][k] / 100.0);
        val[i] = B[i] / (1 - A[i]);
      }
  }
  printf("%.15lf\n", val[1]);
  return 0;
}
