#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, A[300000], min = 1000000000;
  scanf("%i", &n);
  for (int i = 0; i < n; i++) scanf("%i", &A[i]);
  for (int i = 0; i < n; i++) {
    int min1;
    if (i) {
      min1 = (A[i] < A[0] ? A[i] : A[0]) / i;
      if (min1 < min) min = min1;
    }
    if (i < n - 1) {
      min1 = (A[i] < A[n - 1] ? A[i] : A[n - 1]) / (n - 1 - i);
      if (min1 < min) min = min1;
    }
  }
  printf("%i", min);
}
