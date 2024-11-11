#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
int A[N], B[N];
int bsearch(int L, int R, int th) {
  while (L < R) {
    int M = (L + R + 1) >> 1;
    if (B[th] >= A[M])
      L = M;
    else
      R = M - 1;
  }
  return R;
}
int main() {
  int a, b;
  while (scanf("%d%d", &a, &b) == 2) {
    for (int i = 0; i < a; ++i) scanf("%d", &A[i]);
    for (int i = 0; i < b; ++i) scanf("%d", &B[i]);
    sort(A, A + a);
    int first = 0;
    for (int i = 0; i < b; ++i) {
      if (first) printf(" ");
      first = 1;
      int ans = bsearch(0, a - 1, i);
      if (B[i] >= A[0]) ++ans;
      printf("%d", ans);
    }
    puts("");
  }
  return 0;
}
