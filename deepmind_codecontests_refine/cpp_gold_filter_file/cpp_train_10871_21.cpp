#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:444444444")
using namespace std;
int n;
int a[1 << 10];
int can(int m, int& d, int& k) {
  int to = (a[n - 1] - a[0] + 2 * m) / (n - 1);
  for (int i = 0; i <= to; ++i) {
    int L = 0;
    int bad = 0;
    for (int j = 0; j < n; ++j) {
      int now = a[0] - m + i * j;
      if (now < a[j] - m) L = max(L, a[j] - m - now);
    }
    for (int j = 0; j < n; ++j) {
      int now = a[0] - m + i * j + L;
      if (now < a[j] - m || now > a[j] + m) bad = 1;
    }
    if (!bad) {
      d = i;
      k = L;
      return 1;
    }
  }
  return 0;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  int L = -1, R = (int)2e4 + 42;
  int d = 0;
  int k = 0;
  while (R - L > 1) {
    int M = (L + R) / 2;
    if (can(M, d, k))
      R = M;
    else
      L = M;
  }
  can(R, d, k);
  cout << R << endl;
  cout << a[0] - R + k << " " << d << endl;
  return 0;
}
