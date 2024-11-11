#include <bits/stdc++.h>
using namespace std;
const int SZ = 112345;
int n, A[SZ], mn, c0, mx, c1;
long long int k;
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", A + i);
  }
  sort(A, A + n);
  int i = 0, j = n - 1;
  mn = A[0];
  c0 = 0;
  while (A[i] == mn && i < n) {
    i++;
    c0++;
  }
  mx = A[n - 1];
  c1 = 0;
  while (A[j] == mx && j >= 0) {
    j--;
    c1++;
  }
  while (i <= j) {
    long long int x = A[i] - mn;
    long long int y = mx - A[j];
    if (c0 < c1) {
      long long int a = k / c0;
      a = min(a, x);
      k -= a * c0;
      mn += a;
      while (A[i] == mn && i < n) {
        i++;
        c0++;
      }
      if (A[i] < mn) i++;
    } else {
      long long int a = k / c1;
      a = min(a, y);
      k -= a * c1;
      mx -= a;
      while (A[j] == mx && j >= 0) {
        j--;
        c1++;
      }
      if (A[j] > mx) j--;
    }
    if (k < c0 && k < c1) {
      break;
    }
  }
  if (c0 < c1 && k > c0) {
    long long int a = k / c0;
    a = min(a, (long long int)mx - mn);
    mn += a;
  } else if (c0 > c1 && k > c1) {
    long long int a = k / c1;
    a = min(a, (long long int)mx - mn);
    mx -= a;
  }
  printf("%d\n", mx - mn);
  return 0;
}
