#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, A[1000], B[1000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);
  sort(A, A + n);
  int s = 1, e = n - 1, c = 1;
  B[0] = A[0];
  while (e > s && c < n) {
    B[c++] = A[e--];
    B[c++] = A[s++];
    if (!(B[c - 3] <= B[c - 2] && B[c - 2] >= B[c - 1])) {
      printf("Impossible\n");
      return 0;
    }
  }
  if (e == s) {
    B[c++] = A[s];
    if (!(B[c - 2] <= B[c - 1])) {
      printf("Impossible\n");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", B[i]);
  return 0;
}
