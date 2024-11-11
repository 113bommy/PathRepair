#include <bits/stdc++.h>
using namespace std;
double n, m, k, ans = 1, ep[100100];
int main() {
  int i;
  scanf("%lf%lf%lf", &n, &m, &k);
  if (k + n < m) {
    printf("0\n");
    return 0;
  }
  if (k >= m) {
    printf("1\n");
    return 0;
  }
  ep[0] = ep[1] = 0;
  for (i = 2; i < 100100; i++) {
    ep[i] = ep[i - 1] + logl(i);
  }
  ans = ep[(int)n] + ep[(int)m] - ep[(int)(n + k + 1)] - ep[(int)(m - k - 1)];
  ans = expl(ans);
  printf("%.12f\n", 1 - ans);
  return 0;
}
