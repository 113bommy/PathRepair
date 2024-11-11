#include <bits/stdc++.h>
using namespace std;
int f[5] = {1, 1, 2, 6, 24};
long per(long n, long k) {
  long long j = 1;
  for (int i = n - k + 1; i <= n; i++) {
    j *= i;
  }
  return j / f[k];
}
int main() {
  int i, j, n, k;
  cin >> n >> k;
  long long a = 1;
  int m[5] = {1, 0, 1, 2, 9};
  for (i = k; i >= 2; i--) {
    a += per(n, i) * m[i];
  }
  cout << a;
  return 0;
}
