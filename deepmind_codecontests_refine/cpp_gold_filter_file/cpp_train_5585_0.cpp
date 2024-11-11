#include <bits/stdc++.h>
using namespace std;
int binary(int *E, int n, int v) {
  int lo = 0, hi = n;
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    if (E[mid] > v)
      hi = mid;
    else
      lo = mid;
  }
  if (E[lo] > v) return -1;
  return lo;
}
int main() {
  int N, U;
  scanf("%d%d", &N, &U);
  int E[N];
  for (int i = 0; i < N; ++i) scanf("%d", &E[i]);
  double eta = -1.0;
  for (int i = 0; i < (N - 1); ++i) {
    int m = binary(E, N, U + E[i]);
    if (m <= i + 1) continue;
    eta = max(eta, 1.0 - ((double)(E[i + 1] - E[i])) / ((double)(E[m] - E[i])));
  }
  printf("%.9f\n", eta);
}
