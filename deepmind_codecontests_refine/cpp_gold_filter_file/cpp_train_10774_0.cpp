#include <bits/stdc++.h>
using namespace std;
int A[200000];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  long double mx, mn, l = -10000, r = 10000, m;
  while (r - l > 1e-13) {
    m = (l + r) / 2;
    mx = -1e20, mn = 1e20;
    long double tx = 0, tn = 0;
    for (int i = 0; i < N; i++) {
      mx = max(mx, tx = A[i] - m + max(0.l, tx));
      mn = min(mn, tn = A[i] - m + min(0.l, tn));
    }
    mx + mn > 0 ? l = m : r = m;
  }
  printf("%.8f", (double)mx);
  return 0;
}
