#include <bits/stdc++.h>
using namespace std;
int N;
int L[10], R[10];
int main(void) {
  int i, j;
  cin >> N;
  for ((i) = 0; (i) < (int)(N); (i)++) cin >> L[i] >> R[i];
  int p, q, r;
  double ans = 0.0;
  for ((p) = 0; (p) < (int)(N); (p)++)
    for ((q) = 0; (q) < (int)(N); (q)++)
      if (p != q)
        for (i = L[q]; i <= R[q]; i++) {
          double prod = 1.0 / (R[q] - L[q] + 1);
          for ((r) = 0; (r) < (int)(N); (r)++)
            if (r != q) {
              int low = L[r], high = R[r];
              if (r > q)
                low = max(low, i + 1);
              else
                low = max(low, i);
              int cnt = 0;
              if (low <= high) cnt = high - low + 1;
              double tmp = cnt / (double)(R[r] - L[r] + 1);
              if (r != p) tmp = 1.0 - tmp;
              prod *= tmp;
            }
          ans += prod * i;
        }
  printf("%.9f\n", ans);
  return 0;
}
