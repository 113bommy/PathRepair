#include <bits/stdc++.h>
using namespace std;
int A[1010], B[1010];
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) scanf("%d", &B[i]);
  sort(A, A + n);
  sort(B, B + n);
  printf("%d %d\n", A[n - 1], B[m - 1]);
}
