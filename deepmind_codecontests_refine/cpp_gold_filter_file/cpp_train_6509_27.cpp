#include <bits/stdc++.h>
using namespace std;
const double oo = 1e15;
const int maxn = 3e5;
double F[60][maxn];
double t[maxn], sum[maxn], pre[maxn], T[maxn];
int q[maxn];
int n, K, i, j, f, r;
double get(int i, int j, int k) {
  return pre[i] + sum[k] * (-T[i]) + (F[j - 1][k] - pre[k] + sum[k] * T[k]) * 1;
}
double slope(int k1, int k2, int j) {
  return ((F[j - 1][k1] - pre[k1] + sum[k1] * T[k1]) -
          (F[j - 1][k2] - pre[k2] + sum[k2] * T[k2])) /
         (sum[k1] - sum[k2]);
}
int main() {
  scanf("%d%d", &n, &K);
  for (i = 1; i <= n; i++) {
    scanf("%lf", &t[i]);
    sum[i] = sum[i - 1] + t[i];
    pre[i] = pre[i - 1] + sum[i] / t[i];
    T[i] = T[i - 1] + 1 / t[i];
  }
  for (i = 1; i <= n; i++) F[1][i] = pre[i];
  F[1][0] = oo;
  for (j = 2; j <= K; j++) {
    f = 1;
    r = 1;
    q[1] = 0;
    for (i = 1; i <= n; i++) {
      while (f < r && get(i, j, q[f]) > get(i, j, q[f + 1])) f++;
      F[j][i] = get(i, j, q[f]);
      while (f < r && slope(q[r - 1], q[r], j) > slope(q[r], i, j)) r--;
      q[++r] = i;
    }
  }
  printf("%.10lf", F[K][n]);
  return 0;
}
