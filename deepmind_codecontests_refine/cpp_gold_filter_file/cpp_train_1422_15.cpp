#include <bits/stdc++.h>
using namespace std;
struct node {
  double a, t;
  long long all;
} A[200005];
long long cmp(node A, node B) { return A.t > B.t; }
int main(void) {
  long long i, j, n, m, a, L, R;
  double sum, eps = 0.0000001, T;
  scanf("%lld %lf", &n, &T);
  for (i = 0; i < n; i++) {
    scanf("%lf", &A[i].a);
  }
  for (i = 0; i < n; i++) {
    scanf("%lf", &A[i].t);
    A[i].t -= T;
    A[i].all = (long long)A[i].t * (long long)A[i].a;
  }
  sort(A, A + n, cmp);
  for (i = -1; i < n; i++) {
    if (A[i + 1].all < 0) break;
  }
  L = i;
  R = i + 1;
  sum = 0;
  while (L >= 0) {
    if (fabs(A[L].t) < eps) {
      sum += A[L].a;
      L--;
    } else
      break;
  }
  while (R < n) {
    if (fabs(A[R].t) < eps) {
      sum += A[R].a;
      R++;
    } else
      break;
  }
  while (L >= 0 && R < n) {
    A[R].all = fabs(A[R].all);
    A[R].t = fabs(A[R].t);
    if (A[L].all > A[R].all) {
      A[L].all -= A[R].all;
      sum += A[R].all / (A[R].t);
      sum += A[R].all / (A[L].t);
      R++;
    } else {
      A[R].all -= A[L].all;
      sum += A[L].all / (A[L].t);
      sum += A[L].all / (A[R].t);
      L--;
    }
  }
  printf("%.10f\n", sum);
}
