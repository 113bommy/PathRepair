#include <bits/stdc++.h>
using namespace std;
int N;
int A[100005], B[100005], P[100005], Q[100005];
void merge(int a, int m, int b, double& n_inv, double& n_sub_inv,
           double l_sum) {
  int p = a;
  int i = a;
  int j = m + 1;
  while (i <= m && j <= b) {
    if (A[i] < A[j]) {
      l_sum -= double(P[i] + 1);
      B[p] = A[i];
      Q[p] = P[i];
      i++;
    } else {
      n_inv += double(m - i + 1);
      n_sub_inv += l_sum * double(N - P[j]);
      B[p] = A[j];
      Q[p] = P[j];
      j++;
    }
    p++;
  }
  while (i <= m) {
    B[p] = A[i];
    Q[p] = P[i];
    i++;
    p++;
  }
  while (j <= b) {
    B[p] = A[j];
    Q[p] = P[j];
    j++;
    p++;
  }
  for (p = a; p <= b; p++) {
    A[p] = B[p];
    P[p] = Q[p];
  }
}
void inversions(int a, int b, double& n_inv, double& n_sub_inv, double& sum) {
  if (a < b) {
    int m = (a + b) / 2;
    double l_sum = 0.0;
    double r_sum = 0.0;
    inversions(a, m, n_inv, n_sub_inv, l_sum);
    inversions(m + 1, b, n_inv, n_sub_inv, r_sum);
    merge(a, m, b, n_inv, n_sub_inv, l_sum);
    sum = l_sum + r_sum;
  } else {
    sum = double(a + 1);
  }
}
int main() {
  int a, b, i, j;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    P[i] = i;
  }
  double n_subs = double(N) * double(N + 1) / 2.0;
  double ans = 0.0;
  for (i = 2; i <= N; i++)
    ans += double(N - i + 1) * double(i) * double(i - 1) / 4.0;
  ans /= n_subs;
  double n_inv = 0.0;
  double n_sub_inv = 0.0;
  double sum = 0.0;
  inversions(0, N - 1, n_inv, n_sub_inv, sum);
  ans += n_inv;
  ans -= n_sub_inv / n_subs;
  printf("%.15llf\n", ans);
  return 0;
}
