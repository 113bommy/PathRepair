#include <bits/stdc++.h>
using namespace ::std;
const int Nmax = 2 * 1e5;
int a[Nmax], n, k, x;
long long lef[Nmax], rgt[Nmax];
long long mPow(long long a, long long b) {
  long long res = 1;
  for (int i = 0; i < b; i++) {
    res *= a;
  }
  return res;
}
int main() {
  scanf("%d %d %d", &n, &k, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  lef[0] = a[0];
  rgt[n - 1] = a[n - 1];
  for (int i = 1; i < n; i++) {
    lef[i] = lef[i - 1] | a[i];
  }
  for (int i = n - 2; i >= 0; i--) {
    rgt[i] = rgt[i + 1] | a[i];
  }
  long long Max = -1;
  if (n == 1) {
    cout << mPow(x, k) * a[0];
  } else {
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        Max = max((mPow(x, k) * a[0]) | rgt[1], Max);
      } else if (i == n - 1) {
        Max = max((mPow(x, k) * a[n - 1]) | lef[n - 2], Max);
      } else {
        Max = max((mPow(x, k) * a[i]) | lef[i - 1] | rgt[i + 1], Max);
      }
    }
  }
  cout << Max;
  int j = 1;
}
